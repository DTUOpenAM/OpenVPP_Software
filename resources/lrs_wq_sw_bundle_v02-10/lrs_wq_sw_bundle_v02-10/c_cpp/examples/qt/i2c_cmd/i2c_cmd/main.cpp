#include <QCoreApplication>
#include "i2cdrivers.h"
#include "constants.h"
#include "errors.h"
#include <QThread>
#include <math.h>

int main(int argc, char *argv[])
{

    if(argc <= 1){
        printf("Missing arguments...\n");
        return ERROR_MISSING_ARGUMENTS;
    }

    QCoreApplication a(argc, argv);
int ret;
i2cDrivers program;

ret = program.init();
if(ret != 0){
    printf("Init failed %d\n",ret);
    return ret;
}
ret = program.openDevice();
if(ret != 0){
     printf("Open device failed %d\n",ret);
     program.disconnectServer();
    return ret;
}
/*
ret = program.setFrequency();
if(ret != 0){
     printf("setFrequency failed %d\n",ret);
     program.disconnectServer();
    return ret;
}
*/
ret = program.setI2cMaster();
if(ret != 0){
     printf("Set I2c master failed %d\n",ret);
     program.disconnectServer();
    return ret;
}

if (strcmp(argv[1], "start") == 0){
   char sendbyte = TI_SEQUENCE_ON;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_SEQUENCE ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
}else if (strcmp(argv[1], "stop") == 0){
    char sendbyte = TI_SEQUENCE_OFF;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_SEQUENCE ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }

}else if (strcmp(argv[1], "pause") == 0){
    char sendbyte = TI_SEQUENCE_PAUSE;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_SEQUENCE ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
//}else if (strcmp(argv[1], "hdmi") == 0){
//    char sendbyte = TI_IT6536_HDMI;
//    ret = program.write(TI_I2C_RADDR,TI_REG_W_IT6535,1,&sendbyte,1);
//    if(ret != 0){
//        program.disconnectServer();
//        return ret;
//    }
}else if (strcmp(argv[1], "video") == 0){
    char sendbyte = TI_DISPLAY_MODE_NORMAL;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
QThread::sleep(6);
     sendbyte = TI_DISPLAY_MODE_VIDEO_PATTERN;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
  //  QThread::sleep(5);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
    /*
    ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }*/

}else if (strcmp(argv[1], "init") == 0){
    char sendbyte = TI_IT6536_HDMI;
    if(strcmp(argv[2], "dp") == 0){
            sendbyte = TI_IT6536_DISPLAY;
         printf("Display port mode set\n");
    }else{
            printf("HDMI mode set\n");
    }
       ret = program.write(TI_I2C_RADDR,TI_REG_W_IT6535,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
    QThread::sleep(10);
    sendbyte = TI_DISPLAY_MODE_NORMAL;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
    QThread::sleep(10);
     sendbyte = TI_DISPLAY_MODE_VIDEO_PATTERN;
    ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
}else if (strcmp(argv[1], "pixelmode") == 0){
    char sendbyte = 0x0;
    if(strcmp(argv[2], "dual") == 0){
            sendbyte = 0x2;
         printf("Pixel mode dual set\n");
    }else{
            printf("Pixel mode single set\n");
    }
       ret = program.write(TI_I2C_RADDR,0x83,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
}else if (strcmp(argv[1], "internal") == 0){
    if(argc == 3){
        QString imageNum2 = argv[2];
        bool ok;
        uint imageNum = imageNum2.toInt(&ok,10);
        if(imageNum>10){
            program.disconnectServer();
            return ERROR_TO_HIGH_IMAGE_NUM;
        }
        char sendbyte = TI_DISPLAY_MODE_PRE_STORED;
        ret = program.write(TI_I2C_RADDR,TI_REG_W_DISPLAY_MODE,1,&sendbyte,1);
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }

        sendbyte = imageNum & 0x0f;
        ret = program.write(TI_I2C_RADDR,TI_REG_W_TEST_PATTERN,1,&sendbyte,1);
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
    }else{
        program.disconnectServer();
        return ERROR_COMMAND_ARGUMENT_MISMATCH;
    }

}else if (strcmp(argv[1], "setamplitude") == 0){
    if(argc == 3){
        QString amplitude2 = argv[2];
        bool ok;
        uint amplitude = amplitude2.toInt(&ok,10);
        if(amplitude>4095){
            program.disconnectServer();
            return ERROR_TO_HIGH_LED_AMPLITUDE;
        }
        char sendbyte[4];
        sendbyte[0] = (amplitude>>24) & 0xff;
        sendbyte[1] = (amplitude>>16) & 0xff;
        sendbyte[2] = (amplitude>>8) & 0xff;
        sendbyte[3] = (amplitude>>0) & 0xff;
        ret = program.write(LED_I2C_WADDR,LED_AMPLITUDE_REGISTER,2,sendbyte,4);
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
         //TOGGLE UPDATE
        sendbyte[0] = 0;
        sendbyte[1] = 0;
        sendbyte[2] = 0;
        sendbyte[3] = 1;
        ret = program.write(LED_I2C_WADDR,LED_SV_UPDATE_REGISTER,2,sendbyte,4);
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }

        sendbyte[0] = 0;
        sendbyte[1] = 0;
        sendbyte[2] = 0;
        sendbyte[3] = 0;
        ret = program.write(LED_I2C_WADDR,LED_SV_UPDATE_REGISTER,2,sendbyte,4);
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
    }else{
        program.disconnectServer();
        return ERROR_COMMAND_ARGUMENT_MISMATCH;
    }
}else if (strcmp(argv[1], "upload") == 0){
    if(argc == 4){
        QString filename = argv[2];
        QString repeat2 = argv[3];
        bool ok;
        uint repeat = repeat2.toInt(&ok,10);
        //Stop sequencer
        char sendbyte = 0;
        //ret = program.write(TI_I2C_RADDR,TI_REG_W_SEQUENCE,1,&sendbyte,1);
        ret = 0;
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
        //parse sequence file
        ret = program.parseSendSequence(filename,repeat);
        if(ret != 0){
          printf("Problems sending sequence \n");
            program.disconnectServer();
            return ret;
        }
    }else{
        program.disconnectServer();
        return ERROR_COMMAND_ARGUMENT_MISMATCH;
    }

}else if (strcmp(argv[1], "boardtemp") == 0){
        char sendbyte[4];
        ret = program.read(LED_I2C_WADDR,LED_BOARDTEMP_REGISTER,2,sendbyte,4);
        ret = 0;
        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
        uint value = uint(sendbyte[0] & 0xff) << 24;
        value |= uint(sendbyte[1] & 0xff) << 16;
        value |= uint(sendbyte[2] & 0xff) << 8;
        value |= uint(sendbyte[3] & 0xff);
        printf("Boardtemp: %f",double(double(value)/256));
        return LED_BOARD_TEMP_RETURN_BASE + (value/256);
}else if (strcmp(argv[1], "ledtemp") == 0){
        char sendbyte[4];
        ret = program.read(LED_I2C_WADDR,LED_LEDTEMP_REGISTER,2,sendbyte,4);
        ret = 0;

        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
        uint value = uint(sendbyte[0] & 0xff) << 24;
        value |= uint(sendbyte[1] & 0xff) << 16;
        value |= uint(sendbyte[2] & 0xff) << 8;
        value |= uint(sendbyte[3] & 0xff);
        printf("Ledtemp: %f",double(double(value)/10));
        return LED_TEMP_RETURN_BASE + (value/10);
}else if (strcmp(argv[1], "sticky") == 0){
        char sendbyte[4];
        ret = program.read(LED_I2C_WADDR,LED_STICKYBITS_REGISTER,2,sendbyte,4);
        ret = 0;

        if(ret != 0){
            program.disconnectServer();
            return ret;
        }
        uint value = uint(sendbyte[0] & 0xff) << 24;
        value |= uint(sendbyte[1] & 0xff) << 16;
        value |= uint(sendbyte[2] & 0xff) << 8;
        value |= uint(sendbyte[3] & 0xff);
        printf("Sticky bits: %u",value);
        return LED_STICKY_RETURN_BASE + value;
}else if (strcmp(argv[1], "seqstatus") == 0){
    char sendbyte;
    ret = program.read(TI_I2C_RADDR,0x22 ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
                uint value = uint(sendbyte& 0xff);
                printf("Sequencer status: %u",value);
                return TI_SEQUENCE_RETURN_BASE + value;
}else if (strcmp(argv[1], "videostatus") == 0){
    char sendbyte;
    ret = program.read(TI_I2C_RADDR,0x69 ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
                uint value = uint(sendbyte& 0xff);
                printf("video status: %u",value);
                return TI_SEQUENCE_RETURN_BASE + value;
}else if (strcmp(argv[1], "hwstatus") == 0){
    char sendbyte;
    ret = program.read(TI_I2C_RADDR,0x20 ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
                uint value = uint(sendbyte& 0xff);
                printf("hwstatus status: %u",value);
                return TI_SEQUENCE_RETURN_BASE + value;

}else if (strcmp(argv[1], "memstatus") == 0){
    char sendbyte;
    ret = program.read(TI_I2C_RADDR,0x21 ,1,&sendbyte,1);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
                uint value = uint(sendbyte& 0xff);
                printf("Sequencer status: %u",value);
                return TI_SEQUENCE_RETURN_BASE + value;
}else if (strcmp(argv[1], "initled") == 0){
    program.initLedDriver();
}else if(strcmp(argv[1],"setledtemplimit") == 0){
     char sendbyte[4];
     QString limit = argv[2];
     bool ok;
     uint limit2 = limit.toInt(&ok,10);
    sendbyte[0] = (limit2>>24) & 0xff;
    sendbyte[1] = (limit2>>16) & 0xff;
    sendbyte[2] = (limit2>>8) & 0xff;
    sendbyte[3] = (limit2>>0) & 0xff;
    ret = program.write(LED_I2C_WADDR,LED_LED_TEMP_LIMIT_REGISTER,2,sendbyte,4);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
}else if(strcmp(argv[1],"setboardtemplimit") == 0){
    char sendbyte[4];
    QString limit = argv[2];
    bool ok;
    uint limit2 = limit.toInt(&ok,10);
    sendbyte[0] = (limit2>>24) & 0xff;
    sendbyte[1] = (limit2>>16) & 0xff;
    sendbyte[2] = (limit2>>8) & 0xff;
    sendbyte[3] = (limit2>>0) & 0xff;
    ret = program.write(LED_I2C_WADDR,LED_BOARD_TEMP_LIMIT_REGISTER,2,sendbyte,4);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }
}else if(strcmp(argv[1],"ocplimit")== 0){
    char sendbyte[4];
    QString limit = argv[2];
    bool ok;
    uint limit2 = limit.toInt(&ok,10);
    double ocpamp_per_unit = OCP_AMP_PER_UNIT_HW_VER1;
    uint senddata = round(limit2/ocpamp_per_unit);
    sendbyte[0] = (senddata>>24) & 0xff;
    sendbyte[1] = (senddata>>16) & 0xff;
    sendbyte[2] = (senddata>>8) & 0xff;
    sendbyte[3] = (senddata>>0) & 0xff;
    ret = program.write(LED_I2C_WADDR,LED_OCPVALUE_REGISTER,2,sendbyte,4);
    if(ret != 0){
        program.disconnectServer();
        return ret;
    }

}else if (strcmp(argv[1], "help") == 0){
printf("Arguments:\n");
printf("start\t\t- Start the sequencer\n");
printf("stop\t\t- Stop the sequencer\n");
printf("pause\t\t- Pause the sequencer\n");
//printf("hdmi\t\t- Activate hdmi transeiver\n");
printf("video\t\t- Turn on video pattern mode\n");
printf("internal imageNum\t- Turn on internal image demo\n");
printf("init interface\t\t- Activates hdmi or displayport interface and video pattern mode in one command. interface dp will activate display port. Everything else will activate hdmi\n");
printf("pixelmode mode\t\t- Activates single or dual pixel mode. mode dual will activate dual pixel mode. Everything else will activate single pixel mode\n");
printf("upload\tfilename\trepeat\t- Uploads sequence file filename and prepares to run it repeat times. A repeat value of 0 will run the sequence in a loop\n");
printf("initled\t\t\t- Inits and tweaks LED ocp/opp/temp limits and current regulation parametres\n");
printf("setamplitude value\t\t- Sets the led amplitude to the given value\n");
printf("boardtemp\t\t\t- Reads the led board temperature\n");
printf("ledtemp\t\t\t- Reads the led temperature\n");
printf("sticky\t\t\t- Reads the sticky bits\n");
printf("seqstatus- Reads the status of the sequencer, returned bit 1 shows sequencer status\n");
printf("setledtemplimit limit\t\t- Sets the led temperature limit. Temp in Celsius equals limit devided by 10\n");
printf("setboardtemplimit limit\t\t- Sets the board temperature limit. Temp in Celsius equals limit\n");
printf("ocplimit limit\t\t- Sets the board ocp limit in Ampere.\n");
printf("memstatus \t\t\t- Reads mem status\n");
printf("hwstatus \t\t\t- Reads hw status.\n");
printf("help\t\t- Shows this readme\n");
}

ret = program.disconnectServer();
printf("Disconnected %d\n",ret);

return 0;
//return a.exec();
}


