#-------------------------------------------------
#
# Project created by QtCreator 2011-10-25T22:18:25
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui
QT       += sql

win32: TARGET = ../../output/TestPatoFS
unix:  TARGET = ../output/TestPatoFS
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_patofstest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"



symbian: LIBS += -lPatoFS
else:

unix: LIBS += -L"$../output/" -L"$$PWD/../patoFS/BDPatoFS/lib" -lPatoFS  -lsqlite3
win32: LIBS += -L"../output/" -L"$$PWD/../patoFS/BDPatoFS/lib" -lPatoFS  -lsqlite3

INCLUDEPATH += $$PWD/../patoFS
DEPENDPATH += $$PWD/../patoFS

