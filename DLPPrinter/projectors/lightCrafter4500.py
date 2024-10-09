from PySide2.QtCore import Signal, Slot
from PySide2.QtWidgets import QWidget
from PySide2.QtGui import QPixmap
import sys
import os
import subprocess
import shlex
from pathlib import Path
from external_libraries import dlpc350 as dlp


DEBUG_MODE_ON = False


class LightCrafter4500(QWidget):

    print_text_signal = Signal(str)
    connection_status_signal = Signal(bool)
    display_image_signal = Signal(QPixmap)

    def __init__(self):
        QWidget.__init__(self)
        self.dlpc350 = dlp.DLPC350(debug=1, dryrun=0)


    @Slot()
    def init_projector(self):
        self.print_text_signal.emit('Initializing DLPC350...')
        if not self.dlpc350.connectDLP():
            self.print_text_signal.emit('Projector initialization failed!')
            self.connection_status_signal.emit(False)
            return False
        # Configure projector settings here (e.g., input source, mode)
        self.dlpc350.setLEDCurrent(0, 0, 255)                                    # Set blue LED to full intensity
        self.dlpc350.setInputSource(1)                                           # Set input source to HDMI
        self.dlpc350.setDisplayMode(1)                                           # Set to pattern mode
        self.dlpc350.setPatternTriggerMode(0)                                    # Set pattern trigger mode
        self.dlpc350.setPatternInputSource(0b00)                                 # Set pattern input source
        self.dlpc350.setPatternExposureTime(16667, 16667)                        # Set exposure time
        self.dlpc350.startPatternSequence()                                      # Start pattern sequence
        self.dlpc350.exitStandby()
        self.print_text_signal.emit("DLPC350 Projector READY!")
        self.connection_status_signal.emit(True)
        return True

    def stop_projector(self):
        self.dlpc350.enterStandby()  # Example method to stop the projection
        self.dlpc350.disconnectDLP()
        self.print_text_signal.emit("DLPC350 Projector stopped")
        self.connection_status_signal.emit(True)

    def set_projector_amplitude(self, amplitude):
        # Set the blue LED amplitude, assuming red and green are off (0)
        self.dlpc350.setLEDCurrent(0, 0, amplitude)
        self.print_text_signal.emit(f"Set projector blue LED amplitude to {amplitude}")
        return True


