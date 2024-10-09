#ifndef CONSTANTS_H
#define CONSTANTS_H

#define TI_I2C_WADDR 0x34
#define TI_I2C_RADDR 0x35

#define TI_REG_R_TESTIMAGE 0x00
#define TI_REG_W_TESTIMAGE 0x80

#define TI_REG_R_FLIP_LONG 0x08
#define TI_REG_W_FLIP_LONG 0x88

#define TI_REG_R_FLIP_SHORT 0x09
#define TI_REG_W_FLIP_SHORT 0x89

#define TI_REG_R_TRIGGER_OUT1 0x6A
#define TI_REG_W_TRIGGER_OUT1 0xEA

#define TI_REG_R_SEQUENCE 0x65
#define TI_REG_W_SEQUENCE 0xE5

#define TI_SEQUENCE_ON 0x2
#define TI_SEQUENCE_OFF 0x0
#define TI_SEQUENCE_PAUSE 0x1

#define TI_REG_R_INVERT_DATA 0x74
#define TI_REG_W_INVERT_DATA 0xF4


#define TI_REG_R_IT6535 0x0C
#define TI_REG_W_IT6535 0x8C

#define TI_IT6536_OFF 0
#define TI_IT6536_HDMI 1
#define TI_IT6536_DISPLAY 2


#define TI_REG_R_IT6535 0x0C
#define TI_REG_W_IT6535 0x8C

#define TI_REG_R_TEST_PATTERN 0x0A
#define TI_REG_W_TEST_PATTERN 0x8A

#define TI_REG_R_DISPLAY_MODE 0x69
#define TI_REG_W_DISPLAY_MODE 0xE9

#define TI_DISPLAY_MODE_NORMAL 0x0
#define TI_DISPLAY_MODE_PRE_STORED 0x1
#define TI_DISPLAY_MODE_VIDEO_PATTERN 0x2
#define TI_DISPLAY_MODE_ON_THE_FLY 0x3

#define TI_REG_R_ERROR_CODE 0x32

#define TI_REG_R_PATTERN_DISPLAY_LUT_CONFIG 0x75
#define TI_REG_W_PATTERN_DISPLAY_LUT_CONFIG 0xF5
//Bit 0-10 = Numer of LUT entries
//15:11 reserved
//16:47 Number of times to repeat pattern sequence  0=forever

#define TI_REG_W_PATTERN_DISPLAY_LUT 0xF8



#define LED_I2C_WADDR 0x44
#define LED_I2C_RADDR 0x45
#define LED_AMPLITUDE_REGISTER 0x14
#define LED_TEST_REGISTER 0x340
#define LED_SV_UPDATE_REGISTER 0x10

#define LED_PFACTOR_REGISER 0x24
#define LED_IFACTOR_REGISTER 0x28
#define LED_OCPVALUE_REGISTER 0x4C
#define LED_OPPVALUE_REGISTER 0x54
#define LED_PWM_KEEP_OFF_REGISTER 0x78
#define LED_BOARD_TEMP_LIMIT_REGISTER 0x378
#define LED_LED_TEMP_LIMIT_REGISTER 0x80

#define LED_BOARDTEMP_REGISTER 0x370
#define LED_LEDTEMP_REGISTER 0x34

#define LED_STICKYBITS_REGISTER 0x358
//Sticky bits: (4):OCP (3): Door_open (2): Fan stopped (1): Board_overtemp, (0): LED_overtemp
//Power mode

#define NUM_SEQUENCE_COMMAND_VAR 7
#define MAX_NUM_PATTERNS_IN_SEQ 512
const double OCP_AMP_PER_UNIT_HW_VER1 = 0.196;

#endif // CONSTANTS_H
