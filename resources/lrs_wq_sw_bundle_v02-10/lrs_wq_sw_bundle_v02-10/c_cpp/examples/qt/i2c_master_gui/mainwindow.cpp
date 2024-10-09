#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "../../../common/dln_generic.h"
#include "../../../common/dln_i2c_master.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _handle(HDLN_INVALID_HANDLE)
{
    ui->setupUi(this);
    connect(ui->pushButtonOpenDevice, SIGNAL(clicked()), SLOT(openDevice()));
    connect(ui->pushButtonSetFrequency, SIGNAL(clicked()), SLOT(setFrequency()));
    connect(ui->pushButtonGetFrequency, SIGNAL(clicked()), SLOT(getFrequency()));
    connect(ui->checkBoxEnabled, SIGNAL(stateChanged(int)), SLOT(setI2cMaster()));
    connect(ui->pushButtonWrite, SIGNAL(clicked()), SLOT(write()));
    connect(ui->pushButtonRead, SIGNAL(clicked()), SLOT(read()));
    connect(ui->pushButtonScanAddresses, SIGNAL(clicked()), SLOT(initSlaveAddressesCombo()));

    openDevice();
}

MainWindow::~MainWindow()
{
    if (_handle != HDLN_INVALID_HANDLE)
        DlnCloseHandle(_handle);
    delete ui;
}

void MainWindow::openDevice()
{
    enableControls(false);
    if (_handle != HDLN_INVALID_HANDLE)
    {
        DlnCloseHandle(_handle);
        _handle = HDLN_INVALID_HANDLE;
    }
    DLN_RESULT result = DlnOpenDevice(0, &_handle);
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DLN adapter openning error"),
                             tr("Failed to open DLN-series adapter. DlnOpenDevice() returns 0x") + QString::number(result, 16).toUpper());
        return;
    }
    if (initPortCombo())
    {
        enableControls(true);
        getConfiguration();
    }
}

bool MainWindow::initPortCombo()
{
    ui->comboBoxPort->clear();
    uint8_t count;
    DLN_RESULT result = DlnI2cMasterGetPortCount(_handle, &count);
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DlnI2cMasterGetPortCount() failed"),
                             tr("DlnI2cGetPortCount() function returns 0x")+ QString::number(result, 16).toUpper());
        return false;
    }
    if (count == 0)
    {
        QMessageBox::warning(this, tr("No I2C ports"),
                             tr("Current DLN adapter has no I2C ports"));
        return false;
    }
    for (uint8_t i = 0; i < count; i++)
        ui->comboBoxPort->addItem(QString::number(i));
    ui->comboBoxPort->setCurrentIndex(0);
    return true;
}

void MainWindow::setFrequency()
{
    uint32_t actualFrequency;
    DLN_RESULT result = DlnI2cMasterSetFrequency(_handle, ui->comboBoxPort->currentIndex(),ui->lineEditFrequency->text().toUInt(), &actualFrequency);
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DlnI2cMasterSetFrequency() failed"),
                             tr("DlnI2cMasterSetFrequency() function returns 0x")+ QString::number(result, 16).toUpper());
        return;
    }
    if(result == DLN_RES_VALUE_ROUNDED)
    {
        QMessageBox::warning(this, tr("Set Frequency"),
                             tr("Frequency value was rounded to ")+ QString::number(actualFrequency));
    }
    ui->lineEditFrequency->setText(QString::number(actualFrequency));
}

void MainWindow::getFrequency()
{
    uint32_t actualFrequency;
    DLN_RESULT result = DlnI2cMasterGetFrequency(_handle, ui->comboBoxPort->currentIndex(), &actualFrequency);
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DlnI2cMasterGetFrequency() failed"),
                             tr("DlnI2cMasterGetFrequency() function returns 0x")+ QString::number(result, 16).toUpper());
        return;
    }
    ui->lineEditFrequency->setText(QString::number(actualFrequency));
}

void MainWindow::setI2cMaster()
{
    uint16_t conflict;
    if(ui->checkBoxEnabled->isChecked())
    {
        DLN_RESULT result = DlnI2cMasterEnable(_handle, ui->comboBoxPort->currentIndex(), &conflict);
        if (DLN_FAILED(result))
        {
            QMessageBox::warning(this, tr("DlnI2cMasterEnable() failed"),
                                       tr("DlnI2cMasterEnable() function returns 0x")+ QString::number(result, 16).toUpper());
            return;
        }
    }
    if(!ui->checkBoxEnabled->isChecked())
    {
        DLN_RESULT result = DlnI2cMasterDisable(_handle, ui->comboBoxPort->currentIndex());
        if (DLN_FAILED(result))
        {
            QMessageBox::warning(this, tr("DlnI2cMasterDisable() failed"),
                                       tr("DlnI2cMasterDisable() function returns 0x")+ QString::number(result, 16).toUpper());
            return;
        }
    }
}

void MainWindow::getI2cMaster()
{
    uint8_t enabled;
    DLN_RESULT result = DlnI2cMasterIsEnabled(_handle, ui->comboBoxPort->currentIndex(), &enabled);
    if (DLN_FAILED(result))
    {
       QMessageBox::warning(this, tr("DlnI2cMasterIsEnabled() failed"),
                            tr("DlnI2cMasterIsEnabled() function returns 0x")+ QString::number(result, 16).toUpper());
       return;
    }
    if(enabled == DLN_I2C_MASTER_ENABLED)
    {
       ui->checkBoxEnabled->setChecked(true);
       return;
    }
    if(enabled == DLN_I2C_MASTER_DISABLED)
    {
       ui->checkBoxEnabled->setChecked(false);
       return;
    }
}

void MainWindow::initSlaveAddressesCombo()
{
    ui->comboBoxSlaveAddress->clear();
    uint8_t addressCount;
    QByteArray addressList(128, 0);
    DLN_RESULT result = DlnI2cMasterScanDevices(_handle, ui->comboBoxPort->currentIndex(), &addressCount, (uint8_t*)addressList.data());
    if (DLN_FAILED(result))
    {
       QMessageBox::warning(this, tr("DlnI2cMasterScanDevices() failed"),
                            tr("DlnI2cMasterScanDevices() function returns 0x")+ QString::number(result, 16).toUpper());
       return;
    }

    for(uint8_t i = 0; i < addressCount; i++)
        ui->comboBoxSlaveAddress->addItem(QString::number(addressList.at(i)<<1, 16));
    ui->comboBoxSlaveAddress->setCurrentIndex(0);
}

void MainWindow::write()
{
    QByteArray writeData = QByteArray::fromHex(ui->textEditWrite->toPlainText().toLatin1());
    uint16_t bufferSize = (ui->lineEditBufferSize->text()).toUShort();
    if(bufferSize != writeData.size())
    {
        for(int i = writeData.size(); i < bufferSize; i++)
            writeData.append(QByteArray::fromHex(("0")));
    }

    if (writeData.size() == 0)
    {
        QMessageBox::warning(this, tr("Invalid write data"),
                             tr("Please provide data to write."));
        return;
    }

    DLN_RESULT result = DlnI2cMasterWrite(_handle, ui->comboBoxPort->currentIndex(), ui->comboBoxSlaveAddress->currentText().toUShort(0, 16)>>1, ui->comboBoxMemAddrLength->currentIndex(), ui->lineEditMemoryAddress->text().toUShort(0, 16), bufferSize, (uint8_t*)writeData.data());
    if (DLN_FAILED(result))
    {
       QMessageBox::warning(this, tr("DlnI2cMasterWrite() failed"),
                            tr("DlnI2cMasterWrite() function returns 0x")+ QString::number(result, 16).toUpper());
       return;
    }
}

void MainWindow::read()
{
    uint16_t bufferSize = (ui->lineEditBufferSize->text()).toUShort();
   // QByteArray writeData = QByteArray::fromHex(ui->textEditWrite->toPlainText().toAscii());
    QByteArray readData(bufferSize, 0);

    DLN_RESULT result = DlnI2cMasterRead(_handle, ui->comboBoxPort->currentIndex(), ui->comboBoxSlaveAddress->currentText().toUShort(0, 16)>>1, ui->comboBoxMemAddrLength->currentIndex(), ui->lineEditMemoryAddress->text().toUShort(0, 16), readData.size(), (uint8_t*)readData.data());
    if (DLN_FAILED(result))
    {
       QMessageBox::warning(this, tr("DlnI2cMasterRead() failed"),
                            tr("DlnI2cMasterRead() function returns 0x")+ QString::number(result, 16).toUpper());
       return;
    }
    ui->textEditRead->setPlainText(readData.toHex());
}

void MainWindow::getConfiguration()
{
    getI2cMaster();
    getFrequency();
    on_pushButtonGetMaxReplyCount_clicked();
}

void MainWindow::enableControls(bool enable)
{
    ui->lineEditBufferSize->setEnabled(enable);
    ui->comboBoxMemAddrLength->setEnabled(enable);
    ui->textEditWrite->setEnabled(enable);
    ui->pushButtonGetFrequency->setEnabled(enable);
    ui->pushButtonSetFrequency->setEnabled(enable);
    ui->pushButtonRead->setEnabled(enable);
    ui->pushButtonWrite->setEnabled(enable);
    ui->lineEditFrequency->setEnabled(enable);
    ui->lineEditMemoryAddress->setEnabled(enable);
    ui->pushButtonScanAddresses->setEnabled(enable);
    ui->checkBoxEnabled->setEnabled(enable);
    ui->comboBoxSlaveAddress->setEnabled(enable);
    ui->comboBoxPort->setEnabled(enable);
    ui->lineEditMaxReplyCount->setEnabled(enable);
    if (enable)
        connect(ui->comboBoxPort, SIGNAL(currentIndexChanged(int)), SLOT(getConfiguration()));
    else
        disconnect(ui->comboBoxPort, SIGNAL(currentIndexChanged(int)), this, SLOT(getConfiguration()));
}

void MainWindow::on_pushButtonSetMaxReplyCount_clicked()
{
    DLN_RESULT result = DlnI2cMasterSetMaxReplyCount(_handle, ui->comboBoxPort->currentIndex(),ui->lineEditMaxReplyCount->text().toUShort());
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DlnI2cMasterSetMaxReplyCount() failed"),
                             tr("DlnI2cMasterSetMaxReplyCount() function returns 0x")+ QString::number(result, 16).toUpper());
        return;
    }
}

void MainWindow::on_pushButtonGetMaxReplyCount_clicked()
{
    uint16_t maxReplyCount;
    DLN_RESULT result = DlnI2cMasterGetMaxReplyCount(_handle, ui->comboBoxPort->currentIndex(), &maxReplyCount);
    if (DLN_FAILED(result))
    {
        QMessageBox::warning(this, tr("DlnI2cMasterGetMaxReplyCount() failed"),
                             tr("DlnI2cMasterGetMaxReplyCount() function returns 0x")+ QString::number(result, 16).toUpper());
        return;
    }
    ui->lineEditMaxReplyCount->setText(QString::number(maxReplyCount));
}
