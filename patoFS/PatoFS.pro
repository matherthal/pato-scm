#-------------------------------------------------
#
# Project created by QtCreator 2011-08-29T14:00:39
#
#-------------------------------------------------

QT       -= gui
QT       += sql

win32: TARGET = ../../output/PatoFS
unix: TARGET = ../output/PatoFS

TEMPLATE = lib

DEFINES += PATOFS_LIBRARY

SOURCES += patofs.cpp \
#    BDPatoFS/source/CppSQLite3.cpp \
    BDPatoFS/source/bdpatoFS.cpp

HEADERS += patofs.h\
        PatoFS_global.h \
#    BDPatoFS/source/CppSQLite3.h \
    BDPatoFS/source/bdpatoFS.h

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



symbian: LIBS += -lsqlite3
#else:unix|win32: LIBS += -L"../output" -lsqlite3

INCLUDEPATH += $$PWD/BDPatoFS/source
DEPENDPATH += $$PWD/BDPatoFS
