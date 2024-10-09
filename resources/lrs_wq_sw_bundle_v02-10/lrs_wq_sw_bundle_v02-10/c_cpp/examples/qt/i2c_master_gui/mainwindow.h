#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../../common/dln_i2c_master.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void openDevice();
    void getFrequency();
    void setFrequency();
    void setI2cMaster();
    void write();
    void read();
    void initSlaveAddressesCombo();

    void on_pushButtonSetMaxReplyCount_clicked();

    void on_pushButtonGetMaxReplyCount_clicked();

private:
    Ui::MainWindow *ui;
    HDLN _handle;
    bool initPortCombo();
    void enableControls(bool enable);
    void getI2cMaster();
    void getConfiguration();
};

#endif // MAINWINDOW_H
