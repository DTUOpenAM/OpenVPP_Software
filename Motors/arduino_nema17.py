from PySide2.QtCore import QObject, Signal, Slot
import serial


class Arduino_Nema17(QObject):

    print_text_signal = Signal(str)
    connected_signal = Signal(bool)
    homed_signal = Signal(bool)
    move_to_origin_signal = Signal(bool)

    def __init__(self, spindle_pitch_microns=4000, steps_per_revolution=4000): #previously steps_per_revolution=6400    #FIXED
        QObject.__init__(self)
        self.ser = serial.Serial(timeout=5, write_timeout=0)
        self.projector_locked = True
        self.spindle_pitch_microns = spindle_pitch_microns  # mm
        self.steps_per_revolution = steps_per_revolution
        self.step_length_microns = self.spindle_pitch_microns / self.steps_per_revolution  # microns

    def get_step_length_microns(self):                                                                                  #FIXED
        return self.step_length_microns

    @Slot()
    def connect_motor(self, serial_port):                                                                               #FIXED
        self.ser.close()
        self.ser.port = serial_port
        self.ser.baudrate = 115200
        if self.ser.port == '':
            self.print_text_signal.emit("A valid port was NOT selected! Select a valid port.")
            return False
        try:
            self.ser.open()
            self.print_text_signal.emit("Connecting to " + self.ser.port + "...")
            if not self.__initialize_printer__():
                self.ser.close()
                self.print_text_signal.emit("Connection to " + self.ser.port + " NOT established!")
                return False
            self.print_text_signal.emit("Connection to " + self.ser.port + " ESTABLISHED!")
            self.connected_signal.emit(True)
            return True
        except:
            self.ser.close()
            self.print_text_signal.emit("Connection to " + self.ser.port + " NOT established!")
            return False
       
   
    def __initialize_printer__(self):
        go_home = b'G28 Z\n'
        set_unit_mm = b'G21\n'
        while True:
            cmd = self.ser.readline()
            #print(cmd)
            if cmd.startswith(b'echo:  M301'):
                cmd = self.ser.readline()
                cmd = self.ser.readline()
                break
            elif cmd == b'':
                print("serial timeout")
                self.print_text_signal.emit("Problem with the serial connection: check the cables!")
                return False
        self.__send_command_to_printer__(set_unit_mm)
        self.__send_command_to_printer__(go_home)
        return True

    @Slot()
    def disconnect_motor(self):                                                                                     #FIXED
        self.ser.close()
        try:
            self.ser.close()
            self.print_text_signal.emit("...connection to " + str(self.ser.port) + " CLOSED!")
            self.connected_signal.emit(False)
            return True
        except:
            self.print_text_signal.emit("...connection to " + str(self.ser.port) + " NOT closed!")
            return False

    @Slot()                                                                                                         #FIXED
    def reset_printer(self):                                                                                        
        if self.ser.isOpen():
            reset_cmd = b"M999\n"
            self.__send_command_to_printer__(reset_cmd)
            self.print_text_signal.emit("printer status: RESET")
            return True
        else:
            return False

    def __send_command_to_printer__(self, cmd):                                                                    #FIXED            
        if self.ser.isOpen():
            try:
                cmd_bytes = self.ser.write(cmd)
                print(cmd)
                if self.__wait_for_printer__():
                    return True
                else:
                    self.disconnect_motor()
                    self.print_text_signal.emit("There might be problem with the serial connection. Try to reconnect")
                    return False
            except Exception as e:
                self.print_text_signal.emit("Problem with Serial Connection: " + str(e))
                raise e

    def __wait_for_printer__(self):                                                                                 #FIXED
        while True:
            cmd = self.ser.readline()
            print(cmd)
            if cmd.startswith(b'ok') or cmd.startswith(b'\n'):
                return True
            # if cmd == b'':
            #     return False

    @Slot()
    def home_motor(self):                                                                                            #FIXED
            try:
                self.print_text_signal.emit("...homing building plate...")
                go_home_cmd = 'G28 Z\n'.encode('utf-8')
                self.__send_command_to_printer__(go_home_cmd)
                self.print_text_signal.emit("building plate homed!")
                self.homed_signal.emit(True)
                return True
            except Exception as e:
                self.homed_signal.emit(False)
                raise e

    @Slot()
    def move_motor(self, distance_mm, feed_rate, is_relative=True):                                                  #To be changed here          
        if self.ser.isOpen():
            try:
                # if is_relative:
                #     relative_system = b'G91\n'
                #     self.__send_command_to_printer__(relative_system)
                # else:
                #     absolute_system = b'G90\n'
                #     self.__send_command_to_printer__(absolute_system)
                move_up = ('G1 Z' + str(distance_mm) + ' F' + str(feed_rate) + '\n').encode('utf-8')
                self.__send_command_to_printer__(move_up)
                return True
            except Exception as e:
                raise e

    @Slot()
    def move_projector(self, distance, feed_rate, relative_move=True):
        self.print_text_signal.emit("Projector movement not supported!")
    @Slot()
    def home_projector(self):
        self.print_text_signal.emit("Projector movement not supported!")

    @Slot()
    def lock_projector(self):
        self.print_text_signal.emit("Projector movement not supported!")

    @Slot()
    def print_motor_position(self):                                                                                 #To be programmed in Arduino and changed here    
        if self.ser.isOpen():
            serial_clear = False
            while not serial_clear:
                cmd = self.ser.readline()
                if cmd.startswith(b''):
                    serial_clear = True
            get_position = 'M114\n'.encode('utf-8')
            self.ser.write(get_position)
            position_ready = False
            while not position_ready:
                cmd = self.ser.readline()
                if cmd.startswith(b'X:'):
                    positions = cmd.decode('UTF-8').split(' ')
                    projector_position = positions[0]
                    plate_position = positions[2]
                    print(cmd)
                    self.print_text_signal.emit("Building plate " + plate_position[2:len(plate_position)] + " Projector " + projector_position[2:len(projector_position)])
                    position_ready = True
        else:
            self.print_text_signal.emit("The printer is NOT connected!")

    def stop_motor_movements(self):                                                                               #To be programmed in Arduino
        stop_motor = 'M18\n'.encode('utf-8')
        if self.ser.isOpen():
            self.__send_command_to_printer__(stop_motor)



