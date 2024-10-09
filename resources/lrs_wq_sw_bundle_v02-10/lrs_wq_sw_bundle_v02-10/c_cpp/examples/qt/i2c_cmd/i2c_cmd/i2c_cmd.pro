#-------------------------------------------------
#
# Project created by QtCreator 2015-06-23T11:22:13
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_LFLAGS += -static-libgcc

TARGET = i2c_cmd
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    i2cdrivers.cpp

HEADERS += \
    i2cdrivers.h \
    errors.h \
    constants.h

LIBS += ../../../../bin/dln.lib
