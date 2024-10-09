#ifndef I2CDRIVERS_H
#define I2CDRIVERS_H

#include <QByteArray>
#include <QString>
#include "../../../../common/dln_i2c_master.h"


class i2cDrivers
{
public:
    i2cDrivers();
    int openDevice();
    int init();
    int disconnectServer();
    int getFrequency();
    int setFrequency();
    int setI2cMaster();
    int unSetI2cMaster();
    int write(uint8_t slaveAddr, uint32_t memAddr, uint8_t memAddrLen, char *data, int dataSize);
    int read(uint8_t slaveAddr, uint32_t memAddr, uint8_t memAddrLen, char *data, int dataSize);
    int initSlaveAddressesCombo();

    int on_pushButtonSetMaxReplyCount_clicked();

    int on_pushButtonGetMaxReplyCount_clicked();
    int parseSendSequence(QString fileName, uint repeat);
    int initLedDriver();
private:
    HDLN _handle;
    int initPortCombo();
    int enableControls(bool enable);
    int getI2cMaster();
    int getConfiguration();
void printBuffer(char *buf, int size);
   uint32_t i2cportNum;
    uint32_t i2cFrequency;
    uint16_t maxReplyCountValue;

};

#endif // I2CDRIVERS_H
