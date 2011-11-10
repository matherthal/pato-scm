#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:28:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

win32: TARGET = ../../output/pato
unix:  TARGET = ../output/pato

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    updateCLI.cpp \
    statusCLI.cpp \
    cliReader.cpp \
    checkoutCLI.cpp \
    checkinCLI.cpp \
    addCLI.cpp \
    utils.cpp \
    ../patoClientAPI/PatoClientException.cpp

HEADERS += \
    updateCLI.h \
    statusCLI.h \
    cliReader.h \
    checkoutCLI.h \
    checkinCLI.h \
    addCLI.h \
    utils.h \
    ../patoClientAPI/PatoClientException.h

LIBS += -L../output  -lPatoClientApi


