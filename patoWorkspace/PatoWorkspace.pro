#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:39:00
#
#-------------------------------------------------

QT       -= gui

win32: TARGET = ../../output/patoworkspace
unix:  TARGET = ../output/PatoWorkspace


TEMPLATE = lib

DEFINES += PATOWORKSPACE_LIBRARY

SOURCES += patoworkspace.cpp

HEADERS += patoworkspace.h\
        PatoWorkspace_global.h

LIBS += -L"../output" -lPatoBase -lPatoAlgorithms

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2D147E2
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoWorkspace.dll
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
