#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:43:14
#
#-------------------------------------------------

QT       -= gui

win32: TARGET = ../../output/PatoAlgorithms
unix:  TARGET = ../output/PatoAlgorithms

TEMPLATE = lib

DEFINES += PATOALGORITHMS_LIBRARY

SOURCES += patoalgorithms.cpp \
    main.cpp \
    diff.cpp \
    diffitem.cpp \
    merge.cpp \
    lcs.cpp

HEADERS += patoalgorithms.h\
        PatoAlgorithms_global.h \
    diff.h \
    diffitem.h \
    lcs.h \
    merge.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE29001CF
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoAlgorithms.dll
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








