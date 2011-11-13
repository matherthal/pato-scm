#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:32:45
#
#-------------------------------------------------

QT       -= gui

win32: TARGET = ../../output/PatoClientApi
unix:  TARGET = ../output/PatoClientApi

TEMPLATE = lib

DEFINES += PATOCLIENTAPI_LIBRARY

SOURCES += patoclientapi.cpp \
    PatoClientException.cpp \
    updateOutput.cpp \
    statusOutput.cpp \
    logOutput.cpp \
    checkoutOutput.cpp \
    addOutput.cpp

HEADERS += patoclientapi.h\
        PatoClientApi_global.h \
    PatoClientException.h \
    updateOutput.h \
    statusOutput.h \
    logOutput.h \
    checkoutOutput.h \
    addOutput.h


windows: LIBS += -L"../../output/"
unix: LIBS += -L"../output/"

LIBS += -lPatoWorkspace


LIBS += -L"../output" -lPatoWorkspace

