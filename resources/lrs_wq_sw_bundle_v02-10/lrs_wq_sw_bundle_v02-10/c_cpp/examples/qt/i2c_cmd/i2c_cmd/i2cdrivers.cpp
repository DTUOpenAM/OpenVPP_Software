#include "i2cdrivers.h"
#include "errors.h"
#include "../../../../common/dln_generic.h"
#include "../../../../common/dln_i2c_master.h"
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QByteArray>
#include <QThread>
#include "constants.h"
#include <math.h>

i2cDrivers::i2cDrivers():
 _handle(HDLN_INVALID_HANDLE)
{

}

int i2cDrivers::init(){
    i2cportNum = 0;
    i2cFrequency = 100000;
    DLN_RESULT result =
    DlnConnect("localhost", DLN_DEFAULT_SERVER_PORT);
    if (!DLN_SUCCEEDED(result))
    {
        return ERROR_DLN_SERVER_CONNECT_FAILED;
    }
    return ERROR_OK;
}

int i2cDrivers::disconnectServer(){
     DlnDisconnectAll();
     return 0;
}

int i2cDrivers::openDevice()
{
    if (_handle != HDLN_INVALID_HANDLE)
    {
        DlnCloseHandle(_handle);
        _handle = HDLN_INVALID_HANDLE;
    }
    DLN_RESULT result = DlnOpenDevice(0, &_handle);
    if (DLN_FAILED(result))
    {
        return ERROR_DLN_ADAPTER_OPEN;
    }
    if (initPortCombo())
    {
        enableControls(true);
        getConfiguration();
    }
    return ERROR_OK;
}

int i2cDrivers::initPortCombo()
{
    /*
    uint8_t count;
    DLN_RESULT result = DlnI2cMasterGetPortCount(_handle, &count);
    if (DLN_FAILED(result))
    {
        return ERROR_GET_I2C_PORT_COUNT;
    }
    if (count == 0)
    {
        return ERROR_NO_I2C_PORTS;
    }
    for (uint8_t i = 0; i < count; i++)
        ui->comboBoxPort->addItem(QString::number(i));
    ui->comboBoxPort->setCurrentIndex(0);
    */
    return ERROR_OK;
}

int i2cDrivers::setFrequency()
{
    uint32_t actualFrequency;
    DLN_RESULT result = DlnI2cMasterSetFrequency(_handle, i2cportNum,i2cFrequency, &actualFrequency);
    if (DLN_FAILED(result))
    {
        return ERROR_MASTER_SET_FREQUENCY_FAILED;
    }
    if(result == DLN_RES_VALUE_ROUNDED)
    {
        return WARNING_FREQUENCY_ROUNDED;
    }
   // actualFrequencyValue = actualFrequency;
    return ERROR_OK;
}

int i2cDrivers::getFrequency()
{
    uint32_t actualFrequency;
    DLN_RESULT result = DlnI2cMasterGetFrequency(_handle, i2cportNum, &actualFrequency);
    if (DLN_FAILED(result))
    {
         return ERROR_GET_FREQUENCY_FAILED;
    }
    i2cFrequency = actualFrequency;
    //ui->lineEditFrequency->setText(QString::number(actualFrequency));
    return ERROR_OK;
}

int i2cDrivers::setI2cMaster()
{
    uint16_t conflict;

        DLN_RESULT result = DlnI2cMasterEnable(_handle, i2cportNum, &conflict);
        if (DLN_FAILED(result))
        {
            return ERROR_MASTER_ENABLE_FAILED;
        }
        return ERROR_OK;
}

int i2cDrivers::unSetI2cMaster()
{
    //uint16_t conflict;

        DLN_RESULT result = DlnI2cMasterDisable(_handle, i2cportNum);
        if (DLN_FAILED(result))
        {
            return ERROR_MASTER_DISABLE_FAILED;
        }
    return ERROR_OK;
}
int i2cDrivers::getI2cMaster()
{
    uint8_t enabled;
    DLN_RESULT result = DlnI2cMasterIsEnabled(_handle, i2cportNum, &enabled);
    if (DLN_FAILED(result))
    {
       return ERROR_MASTER_IS_ENABLED_FAILED;
    }
    if(enabled == DLN_I2C_MASTER_ENABLED)
    {

       return ERROR_OK;
    }
    if(enabled == DLN_I2C_MASTER_DISABLED)
    {
       return ERROR_OK;
    }
    return ERROR_OK;
}

int i2cDrivers::initSlaveAddressesCombo()
{
    //ui->comboBoxSlaveAddress->clear();
    uint8_t addressCount;
    QByteArray addressList(128, 0);
    DLN_RESULT result = DlnI2cMasterScanDevices(_handle, i2cportNum, &addressCount, (uint8_t*)addressList.data());
    if (DLN_FAILED(result))
    {
       return ERROR_MASTER_SCAN_FAILED;
    }

    /*for(uint8_t i = 0; i < addressCount; i++)
        ui->comboBoxSlaveAddress->addItem(QString::number(addressList.at(i), 16));
    ui->comboBoxSlaveAddress->setCurrentIndex(0);*/
    return ERROR_OK;
}


int i2cDrivers::write(uint8_t slaveAddr, uint32_t memAddr,uint8_t memAddrLen, char *data, int dataSize)
{
    QByteArray writeData;
    for(int i= 0; i< dataSize; i++){
        writeData.append(data[i]);
    }
    uint16_t bufferSize = dataSize;
    if(bufferSize != writeData.size())
    {
        for(int i = writeData.size(); i < bufferSize; i++)
            writeData.append(QByteArray::fromHex(("0")));
    }

    if (writeData.size() == 0)
    {
        //QMessageBox::warning(this, tr("Invalid write data"),
          //                   tr("Please provide data to write."));
        return ERROR_INVALID_WRITE_DATA;
    }

    DLN_RESULT result = DlnI2cMasterWrite(_handle, i2cportNum, slaveAddr>>1, memAddrLen, memAddr, bufferSize, (uint8_t*)writeData.data());
    if (DLN_FAILED(result))
    {
       //QMessageBox::warning(this, tr("DlnI2cMasterWrite() failed"),
       //                     tr("DlnI2cMasterWrite() function returns 0x")+ QString::number(result, 16).toUpper());
       return ERROR_WRITE_FAILED;
    }
    return 0;
}

int i2cDrivers::read(uint8_t slaveAddr, uint32_t memAddr, uint8_t memAddrLen, char *data, int dataSize)
{
    uint16_t bufferSize = dataSize;
   // QByteArray writeData = QByteArray::fromHex(ui->textEditWrite->toPlainText().toAscii());
    QByteArray readData(bufferSize, 0);

    DLN_RESULT result = DlnI2cMasterRead(_handle, i2cportNum, slaveAddr>>1, memAddrLen, memAddr, readData.size(), (uint8_t*)readData.data());
    if (DLN_FAILED(result))
    {
     //  QMessageBox::warning(this, tr("DlnI2cMasterRead() failed"),
     //                       tr("DlnI2cMasterRead() function returns 0x")+ QString::number(result, 16).toUpper());
       return ERROR_READ_FAILED;
    }
    for(int i=0;i<dataSize;i++){
        data[i] = readData.at(i);
    }

   // ui->textEditRead->setPlainText(readData.toHex());
    return 0;
}

int i2cDrivers::getConfiguration()
{
    getI2cMaster();
    getFrequency();
    on_pushButtonGetMaxReplyCount_clicked();
    return 0;
}


int i2cDrivers::on_pushButtonSetMaxReplyCount_clicked()
{
    DLN_RESULT result = DlnI2cMasterSetMaxReplyCount(_handle, i2cportNum,maxReplyCountValue);
    if (DLN_FAILED(result))
    {
        return ERROR_SET_REPLY_COUNT_FAILED;
    }
    return ERROR_OK;
}

int i2cDrivers::on_pushButtonGetMaxReplyCount_clicked()
{
    uint16_t maxReplyCount;
    DLN_RESULT result = DlnI2cMasterGetMaxReplyCount(_handle, i2cportNum, &maxReplyCount);
    if (DLN_FAILED(result))
    {
        return ERROR_GET_REPLY_COUNT;
    }
    maxReplyCountValue = maxReplyCount;
    return ERROR_OK;
}

int i2cDrivers::parseSendSequence(QString fileName,uint repeat)
{
    QThread::sleep(3);
            int ret;
    QFile file(fileName);
    uint sequence[MAX_NUM_PATTERNS_IN_SEQ][NUM_SEQUENCE_COMMAND_VAR];
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
     QTextStream in(&file);
     int i=0;

     while(!in.atEnd()) {
         QString line = in.readLine();
         QStringList fields = line.split(",");
         if(fields.length()!= NUM_SEQUENCE_COMMAND_VAR){
             return ERROR_SEQUENCE_NUM_ARGS + i;
         }
         if(i>MAX_NUM_PATTERNS_IN_SEQ){
            return ERROR_SEQUENCE_TO_MANY_PATTERNS + i;
         }
         for(int j=0; j<NUM_SEQUENCE_COMMAND_VAR ;j++){
                sequence[i][j] = fields.at(j).toInt();
             }
         i++;
     }
    if(i==0){
        return ERROR_COULD_NOT_FIND_ANY_LINES_IN_SEQUENCE_FILE;
    }


     //SEND ALL PATTERNS
     char buf[12];
     for(int n=0; n<i;n++){
         //NOW CHECK VALUES AND SEND PATTERN TO WQ
        if(sequence[n][0] > 0xFFFFFF){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 0;
        }
        if(sequence[n][1] > 0x7){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 1;
        }
        if(sequence[n][2] > 0x7){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 2;
        }
        if(sequence[n][3] > 1){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 3;
        }
        if(sequence[n][4] > 0xFFFFFF){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 4;
        }
        if(sequence[n][5] > 23){
            return ERROR_SEQUENCE_VALUES + ((n << 4) & 0x70) + 5;
        }
        buf[0] = n & 0xff;
        buf[1] = (n >> 8) & 0xff;
        buf[2] = sequence[n][0] & 0xff;
        buf[3] = (sequence[n][0] >> 8) & 0xff;
        buf[4] = (sequence[n][0] >> 16) & 0xff;
        buf[5] = 0;
        buf[5] |= (sequence[n][1] << 1) & 0x0e;
        buf[5] |= (sequence[n][2] << 4) & 0x70;
        buf[5] |= (sequence[n][3] << 7) & 0x80;
        buf[5] |= (sequence[n][6]) & 0x1;
        buf[6] = sequence[n][4] & 0xff;
        buf[7] = (sequence[n][4] >> 8) & 0xff;
        buf[8] = (sequence[n][4] >> 16) & 0xff;
        buf[9] = 0;
        buf[10] = 0;
        buf[11] = (sequence[n][5]) & 0x1F;
        ret = write(TI_I2C_RADDR,TI_REG_W_PATTERN_DISPLAY_LUT,1,buf,12);
        if(ret != 0){
            return ERROR_WRITE_FAILED;
        }
        QThread::sleep(3);
        printBuffer(buf,12);

     }
     //SEND LUT CONFIG
    char bufconfig[6];
    bufconfig[0] = i & 0xff;
    bufconfig[1] = (i >> 8) & 0xff;
    bufconfig[2] = repeat & 0xff;
    bufconfig[3] = (repeat >> 8) & 0xff;
    bufconfig[4] = (repeat >> 16) & 0xff;
    bufconfig[5] = (repeat >> 24) & 0xff;
     printBuffer(bufconfig,6);
    ret = write(TI_I2C_RADDR,TI_REG_W_PATTERN_DISPLAY_LUT_CONFIG,1,bufconfig,6);
    if(ret != 0){
        return ERROR_WRITE_FAILED;
    }


     return 0;
    }
    return ERROR_COULD_NOT_FIND_SEQUENCE_FILE;

}

int i2cDrivers::initLedDriver(){
    // Default values
    const unsigned long DEF_PWM_KEEP_OFF = 1;
    const unsigned long DEF_PFACTOR = 100;
    const unsigned long DEF_IFACTOR = 25;
    const unsigned long DEF_LED_TEMP_LIMIT = 1000;    // LED temp limit: 50 deg C
    const unsigned long DEF_BOARD_TEMP_LIMIT = 90;   // Board temp limit: 70 deg C

    // Default OCP value
    const unsigned char DEF_OCP_AMP = 20;

    // Default OPP values for different hardware versions
    const unsigned long DEF_OPP_HW_VER_1 = 275;

    // OCP unit for conversion between ampere and unit

    char sendbyte[4];
    sendbyte[0] = (DEF_PWM_KEEP_OFF>>24) & 0xff;
    sendbyte[1] = (DEF_PWM_KEEP_OFF>>16) & 0xff;
    sendbyte[2] = (DEF_PWM_KEEP_OFF>>8) & 0xff;
    sendbyte[3] = (DEF_PWM_KEEP_OFF>>0) & 0xff;
    int ret = write(LED_I2C_WADDR,LED_PWM_KEEP_OFF_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }



    sendbyte[0] = (DEF_PFACTOR>>24) & 0xff;
    sendbyte[1] = (DEF_PFACTOR>>16) & 0xff;
    sendbyte[2] = (DEF_PFACTOR>>8) & 0xff;
    sendbyte[3] = (DEF_PFACTOR>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_PFACTOR_REGISER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }

    sendbyte[0] = (DEF_IFACTOR>>24) & 0xff;
    sendbyte[1] = (DEF_IFACTOR>>16) & 0xff;
    sendbyte[2] = (DEF_IFACTOR>>8) & 0xff;
    sendbyte[3] = (DEF_IFACTOR>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_IFACTOR_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }

    sendbyte[0] = (DEF_LED_TEMP_LIMIT>>24) & 0xff;
    sendbyte[1] = (DEF_LED_TEMP_LIMIT>>16) & 0xff;
    sendbyte[2] = (DEF_LED_TEMP_LIMIT>>8) & 0xff;
    sendbyte[3] = (DEF_LED_TEMP_LIMIT>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_LED_TEMP_LIMIT_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }

    sendbyte[0] = (DEF_BOARD_TEMP_LIMIT>>24) & 0xff;
    sendbyte[1] = (DEF_BOARD_TEMP_LIMIT>>16) & 0xff;
    sendbyte[2] = (DEF_BOARD_TEMP_LIMIT>>8) & 0xff;
    sendbyte[3] = (DEF_BOARD_TEMP_LIMIT>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_BOARD_TEMP_LIMIT_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }
    double ocpamp_per_unit = OCP_AMP_PER_UNIT_HW_VER1;
    uint ocpamp = DEF_OCP_AMP;
    uint senddata = round(ocpamp/ocpamp_per_unit);
    sendbyte[0] = (senddata>>24) & 0xff;
    sendbyte[1] = (senddata>>16) & 0xff;
    sendbyte[2] = (senddata>>8) & 0xff;
    sendbyte[3] = (senddata>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_OCPVALUE_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }


    sendbyte[0] = (DEF_OPP_HW_VER_1>>24) & 0xff;
    sendbyte[1] = (DEF_OPP_HW_VER_1>>16) & 0xff;
    sendbyte[2] = (DEF_OPP_HW_VER_1>>8) & 0xff;
    sendbyte[3] = (DEF_OPP_HW_VER_1>>0) & 0xff;
    ret = write(LED_I2C_WADDR,LED_OPPVALUE_REGISTER,2,sendbyte,4);
    if(ret != 0){
        disconnectServer();
        return ret;
    }
    return 0;
}
    void i2cDrivers::printBuffer(char *buf, int size){
        printf("\nBuffer: ");
        for(int i=0;i<size;i++){
            printf("%02x ",buf[i] & 0xff);
        }
    }
