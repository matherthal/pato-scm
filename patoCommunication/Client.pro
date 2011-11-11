#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T11:41:17
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = ../output/Client
TEMPLATE = lib

DEFINES += PATOCOMMUNICATION_LIBRARY

SOURCES += client.cpp

HEADERS += client.h\
        Client_global.h

LIBS += -L"./xmlrpc" -lxmlrpc_client++ -lxmlrpc_client -lxmlrpc++ -lxmlrpc -lxmlrpc_xmlparse -lxmlrpc_xmltok -lxmlrpc_util -lcurl -lxmlrpc_packetsocket

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE164B091
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PatoCommunication.dll
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
