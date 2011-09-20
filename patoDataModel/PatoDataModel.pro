#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:56:35
#
#-------------------------------------------------

QT       -= gui

TARGET = ../output/PatoDataModel
TEMPLATE = lib

DEFINES += PATODATAMODEL_LIBRARY

SOURCES += patodatamodel.cpp

HEADERS += patodatamodel.h\
        PatoDataModel_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE27423A1
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoDataModel.dll
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
