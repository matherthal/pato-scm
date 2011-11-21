#-------------------------------------------------
#
# Project created by QtCreator 2011-09-21T12:30:35
#
#-------------------------------------------------

QT       -= gui

win32: TARGET = ../../output/patobase
unix:  TARGET = ../output/PatoBase

TEMPLATE = lib
CONFIG += staticlib

SOURCES += patobase.cpp \
    patofilestatus.cpp \
    patochangeset.cpp \
    patoutils.cpp

HEADERS += patobase.h \
    patofilestatus.h \
    patotypes.h \
    patochangeset.h \
    patoutils.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


