/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBoxSetup;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QCheckBox *checkBoxEnabled;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelFrequency;
    QLineEdit *lineEditFrequency;
    QSplitter *splitter;
    QPushButton *pushButtonSetFrequency;
    QPushButton *pushButtonGetFrequency;
    QPushButton *pushButtonOpenDevice;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelMaxReplyCount;
    QLineEdit *lineEditMaxReplyCount;
    QSplitter *splitter_2;
    QPushButton *pushButtonSetMaxReplyCount;
    QPushButton *pushButtonGetMaxReplyCount;
    QGroupBox *groupBoxTransfer;
    QTextEdit *textEditWrite;
    QTextEdit *textEditRead;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *labelSlaveAddress;
    QComboBox *comboBoxSlaveAddress;
    QPushButton *pushButtonScanAddresses;
    QLabel *labelMemoryAddress;
    QLineEdit *lineEditMemoryAddress;
    QLabel *labelMemAddrLength;
    QComboBox *comboBoxMemAddrLength;
    QWidget *layoutWidget3;
    QFormLayout *formLayout;
    QLabel *labelBufferSize;
    QLineEdit *lineEditBufferSize;
    QWidget *layoutWidget4;
    QFormLayout *formLayout_2;
    QPushButton *pushButtonWrite;
    QPushButton *pushButtonRead;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(411, 409);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBoxSetup = new QGroupBox(centralWidget);
        groupBoxSetup->setObjectName(QStringLiteral("groupBoxSetup"));
        groupBoxSetup->setGeometry(QRect(10, 10, 391, 121));
        layoutWidget1 = new QWidget(groupBoxSetup);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 20, 179, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelPort = new QLabel(layoutWidget1);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        horizontalLayout->addWidget(labelPort);

        comboBoxPort = new QComboBox(layoutWidget1);
        comboBoxPort->setObjectName(QStringLiteral("comboBoxPort"));

        horizontalLayout->addWidget(comboBoxPort);

        checkBoxEnabled = new QCheckBox(layoutWidget1);
        checkBoxEnabled->setObjectName(QStringLiteral("checkBoxEnabled"));

        horizontalLayout->addWidget(checkBoxEnabled);

        layoutWidget = new QWidget(groupBoxSetup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 371, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelFrequency = new QLabel(layoutWidget);
        labelFrequency->setObjectName(QStringLiteral("labelFrequency"));

        horizontalLayout_2->addWidget(labelFrequency);

        lineEditFrequency = new QLineEdit(layoutWidget);
        lineEditFrequency->setObjectName(QStringLiteral("lineEditFrequency"));

        horizontalLayout_2->addWidget(lineEditFrequency);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButtonSetFrequency = new QPushButton(splitter);
        pushButtonSetFrequency->setObjectName(QStringLiteral("pushButtonSetFrequency"));
        splitter->addWidget(pushButtonSetFrequency);
        pushButtonGetFrequency = new QPushButton(splitter);
        pushButtonGetFrequency->setObjectName(QStringLiteral("pushButtonGetFrequency"));
        splitter->addWidget(pushButtonGetFrequency);

        horizontalLayout_2->addWidget(splitter);

        pushButtonOpenDevice = new QPushButton(groupBoxSetup);
        pushButtonOpenDevice->setObjectName(QStringLiteral("pushButtonOpenDevice"));
        pushButtonOpenDevice->setGeometry(QRect(300, 20, 81, 23));
        layoutWidget_2 = new QWidget(groupBoxSetup);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 80, 371, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelMaxReplyCount = new QLabel(layoutWidget_2);
        labelMaxReplyCount->setObjectName(QStringLiteral("labelMaxReplyCount"));

        horizontalLayout_3->addWidget(labelMaxReplyCount);

        lineEditMaxReplyCount = new QLineEdit(layoutWidget_2);
        lineEditMaxReplyCount->setObjectName(QStringLiteral("lineEditMaxReplyCount"));

        horizontalLayout_3->addWidget(lineEditMaxReplyCount);

        splitter_2 = new QSplitter(layoutWidget_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButtonSetMaxReplyCount = new QPushButton(splitter_2);
        pushButtonSetMaxReplyCount->setObjectName(QStringLiteral("pushButtonSetMaxReplyCount"));
        splitter_2->addWidget(pushButtonSetMaxReplyCount);
        pushButtonGetMaxReplyCount = new QPushButton(splitter_2);
        pushButtonGetMaxReplyCount->setObjectName(QStringLiteral("pushButtonGetMaxReplyCount"));
        splitter_2->addWidget(pushButtonGetMaxReplyCount);

        horizontalLayout_3->addWidget(splitter_2);

        groupBoxTransfer = new QGroupBox(centralWidget);
        groupBoxTransfer->setObjectName(QStringLiteral("groupBoxTransfer"));
        groupBoxTransfer->setGeometry(QRect(10, 140, 391, 261));
        textEditWrite = new QTextEdit(groupBoxTransfer);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));
        textEditWrite->setGeometry(QRect(10, 160, 181, 91));
        textEditRead = new QTextEdit(groupBoxTransfer);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setEnabled(false);
        textEditRead->setGeometry(QRect(200, 160, 181, 91));
        layoutWidget2 = new QWidget(groupBoxTransfer);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 20, 342, 77));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelSlaveAddress = new QLabel(layoutWidget2);
        labelSlaveAddress->setObjectName(QStringLiteral("labelSlaveAddress"));

        gridLayout->addWidget(labelSlaveAddress, 0, 0, 1, 1);

        comboBoxSlaveAddress = new QComboBox(layoutWidget2);
        comboBoxSlaveAddress->setObjectName(QStringLiteral("comboBoxSlaveAddress"));
        comboBoxSlaveAddress->setEditable(true);

        gridLayout->addWidget(comboBoxSlaveAddress, 0, 1, 1, 1);

        pushButtonScanAddresses = new QPushButton(layoutWidget2);
        pushButtonScanAddresses->setObjectName(QStringLiteral("pushButtonScanAddresses"));

        gridLayout->addWidget(pushButtonScanAddresses, 0, 2, 1, 1);

        labelMemoryAddress = new QLabel(layoutWidget2);
        labelMemoryAddress->setObjectName(QStringLiteral("labelMemoryAddress"));

        gridLayout->addWidget(labelMemoryAddress, 1, 0, 1, 1);

        lineEditMemoryAddress = new QLineEdit(layoutWidget2);
        lineEditMemoryAddress->setObjectName(QStringLiteral("lineEditMemoryAddress"));

        gridLayout->addWidget(lineEditMemoryAddress, 1, 1, 1, 1);

        labelMemAddrLength = new QLabel(layoutWidget2);
        labelMemAddrLength->setObjectName(QStringLiteral("labelMemAddrLength"));

        gridLayout->addWidget(labelMemAddrLength, 2, 0, 1, 1);

        comboBoxMemAddrLength = new QComboBox(layoutWidget2);
        comboBoxMemAddrLength->setObjectName(QStringLiteral("comboBoxMemAddrLength"));

        gridLayout->addWidget(comboBoxMemAddrLength, 2, 1, 1, 1);

        layoutWidget3 = new QWidget(groupBoxTransfer);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(240, 130, 141, 22));
        formLayout = new QFormLayout(layoutWidget3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelBufferSize = new QLabel(layoutWidget3);
        labelBufferSize->setObjectName(QStringLiteral("labelBufferSize"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelBufferSize);

        lineEditBufferSize = new QLineEdit(layoutWidget3);
        lineEditBufferSize->setObjectName(QStringLiteral("lineEditBufferSize"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditBufferSize);

        layoutWidget4 = new QWidget(groupBoxTransfer);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 130, 158, 25));
        formLayout_2 = new QFormLayout(layoutWidget4);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonWrite = new QPushButton(layoutWidget4);
        pushButtonWrite->setObjectName(QStringLiteral("pushButtonWrite"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButtonWrite);

        pushButtonRead = new QPushButton(layoutWidget4);
        pushButtonRead->setObjectName(QStringLiteral("pushButtonRead"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButtonRead);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBoxSetup->setTitle(QApplication::translate("MainWindow", "Setup", 0));
        labelPort->setText(QApplication::translate("MainWindow", "Port #:", 0));
        checkBoxEnabled->setText(QApplication::translate("MainWindow", "Enabled", 0));
        labelFrequency->setText(QApplication::translate("MainWindow", "Frequency:", 0));
        pushButtonSetFrequency->setText(QApplication::translate("MainWindow", "Set", 0));
        pushButtonGetFrequency->setText(QApplication::translate("MainWindow", "Get", 0));
        pushButtonOpenDevice->setText(QApplication::translate("MainWindow", "Open Device", 0));
        labelMaxReplyCount->setText(QApplication::translate("MainWindow", "Max Reply Count:", 0));
        pushButtonSetMaxReplyCount->setText(QApplication::translate("MainWindow", "Set", 0));
        pushButtonGetMaxReplyCount->setText(QApplication::translate("MainWindow", "Get", 0));
        groupBoxTransfer->setTitle(QApplication::translate("MainWindow", "Transfer", 0));
        labelSlaveAddress->setText(QApplication::translate("MainWindow", "Slave Address:", 0));
        pushButtonScanAddresses->setText(QApplication::translate("MainWindow", "Scan", 0));
        labelMemoryAddress->setText(QApplication::translate("MainWindow", "Memory Address:", 0));
        labelMemAddrLength->setText(QApplication::translate("MainWindow", "Memory Address Length:", 0));
        comboBoxMemAddrLength->clear();
        comboBoxMemAddrLength->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0)
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
        );
        labelBufferSize->setText(QApplication::translate("MainWindow", "Buffer size:", 0));
        pushButtonWrite->setText(QApplication::translate("MainWindow", "Write", 0));
        pushButtonRead->setText(QApplication::translate("MainWindow", "Read", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
