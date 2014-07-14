#-------------------------------------------------
#
# Project created by QtCreator 2014-07-13T13:09:46
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testcsvmodeltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app



SOURCES += tst_testcsvmodeltest.cpp \
    ../MineSenseDemo/models/csvmodel.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../MineSenseDemo/models/csvmodel.h

