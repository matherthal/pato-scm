#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:37:57
#
#-------------------------------------------------

QT       -= gui
QT       += sql

#TARGET = ../output/Server
TEMPLATE = lib

DEFINES += PATOSERVERAPI_LIBRARY

SOURCES += server.cpp

HEADERS += server.h\
        Server_global.h

LIBS += -L"./xmlrpc" -lxmlrpc_server_abyss++ -lxmlrpc_server++ -lxmlrpc_server_abyss -lxmlrpc_server -lxmlrpc_abyss -lpthread -lxmlrpc++ -lxmlrpc -lxmlrpc_xmlparse -lxmlrpc_xmltok -lxmlrpc_util

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE1E60A81
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Server.dll
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
