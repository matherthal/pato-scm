#-------------------------------------------------
#
# Project created by QtCreator 2011-10-16T03:14:53
#
#-------------------------------------------------

QT       += testlib

QT       -= gui
QT       += sql

TARGET = ../output/tst_test_patoworkspace
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test_patoworkspace.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -L"../output" -lPatoWorkspace -lPatoBase
