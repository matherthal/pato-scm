#-------------------------------------------------
#
# Project created by QtCreator 2011-10-29T14:55:16
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

win32: TARGET = ../../output/TestPatoDataModel
unix:  TARGET = ../output/TestPatoDataModel

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_patodatamodeltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

symbian: LIBS += -lsqlite3
else:
unix: LIBS += -L"../output/" -L$$PWD/../patoDataModel/BDPatoDataModel/lib/ -lPatoDataModel -lsqlite3
win32: LIBS += -L"../output/" -L$$PWD/../patoDataModel/BDPatoDataModel/lib/ -lPatoDataModel -lsqlite3

INCLUDEPATH += $$PWD/../patoDataModel
DEPENDPATH += $$PWD/../patoDataModel
