#-------------------------------------------------
#
# Project created by QtCreator 2011-01-05T16:46:19
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = i2c_master_gui
TEMPLATE = app

QMAKE_LFLAGS += -static-libgcc

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += ../../../bin/dln.lib
