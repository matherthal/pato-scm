#-------------------------------------------------
#
# Project created by QtCreator 2011-10-25T22:18:25
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

TARGET = tst_patofstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_patofstest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"



symbian: LIBS += -lPatoFS
else:unix|win32: LIBS += -L$$PWD/../PatoFS-build-desktop-Qt_4_7_4_for_Desktop_-_MSVC2008__Qt_SDK__Debug/output/ -lPatoFS

INCLUDEPATH += $$PWD/../patoFS
DEPENDPATH += $$PWD/../patoFS

OTHER_FILES += \
    ../PatoFS-build-desktop-Qt_4_7_4_for_Desktop_-_MSVC2008__Qt_SDK__Debug/output/PatoFS.dll

