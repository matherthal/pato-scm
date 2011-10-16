#-------------------------------------------------
#
# Project created by QtCreator 2011-08-29T14:00:39
#
#-------------------------------------------------

QT       -= gui
QT       += sql

TARGET = ../output/PatoFS
TEMPLATE = lib

DEFINES += PATOFS_LIBRARY

SOURCES += patofs.cpp

HEADERS += patofs.h\
        PatoFS_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE4332F71
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoFS.dll
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
