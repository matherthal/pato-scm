#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:37:57
#
#-------------------------------------------------

QT       -= gui
QT       += sql


win32: TARGET = ../../output/patoserverapi
unix:  TARGET = ../output/PatoServerApi

TEMPLATE = lib

DEFINES += PATOSERVERAPI_LIBRARY

SOURCES += patoserverapi.cpp

HEADERS += patoserverapi.h\
        PatoServerApi_global.h

#LIBS += -L"./xmlrpc" -lxmlrpc_client++ -lxmlrpc_client -lxmlrpc++ -lxmlrpc -lxmlrpc_xmlparse -lxmlrpc_xmltok -lxmlrpc_util -lcurl -lxmlrpc_packetsocket

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE1E60A81
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoServerApi.dll
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

LIBS += -L"../output"  -lPatoFS -lPatoDataModel
