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
    testfilefactory.cpp \
    mockfile.cpp \
    ifile.cpp \
    filefactory.cpp \
    file.cpp \
    defaultlfilefactory.cpp \
    patoResourceAbstractFactory.cpp

HEADERS += patobase.h \
    patofilestatus.h \
    patotypes.h \
    patochangeset.h \
    testfilefactory.h \
    mockfile.h \
    ifile.h \
    filefactory.h \
    file.h \
    defaultlfilefactory.h \
    patoResourceAbstractFactory.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


