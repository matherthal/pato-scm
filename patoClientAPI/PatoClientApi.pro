#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:32:45
#
#-------------------------------------------------

QT       -= gui

TARGET = ../output/PatoClientApi
TEMPLATE = lib

DEFINES += PATOCLIENTAPI_LIBRARY

SOURCES += patoclientapi.cpp

HEADERS += patoclientapi.h\
        PatoClientApi_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE1E6B326
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoClientApi.dll
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
