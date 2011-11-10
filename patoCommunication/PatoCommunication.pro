#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:41:17
#
#-------------------------------------------------

QT       += network

QT       -= gui
QT       += sql

TARGET = ../output/PatoCommunication
TEMPLATE = lib

DEFINES += PATOCOMMUNICATION_LIBRARY

SOURCES += patocommunication.cpp

HEADERS += patocommunication.h\
        PatoCommunication_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE164B091
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoCommunication.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
