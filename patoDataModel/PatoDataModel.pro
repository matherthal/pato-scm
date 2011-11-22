# -------------------------------------------------
# Project created by QtCreator 2011-08-25T11:56:35
# -------------------------------------------------
QT -= gui
QT       += sql

win32: TARGET = ../../output/PatoDataModel
unix: TARGET = $$PWD/../output/PatoDataModel

TEMPLATE = lib
DEFINES += PATODATAMODEL_LIBRARY
SOURCES += patodatamodel.cpp \
    BDPatoDataModel/source/CppSQLite3.cpp \
    BDPatoDataModel/source/bdpatodatamodel.cpp
HEADERS += BDPatoDataModel/source/CppSQLite3.h \
    BDPatoDataModel/source/bdpatodatamodel.h \
    BDPatoDataModel/source/sqlite3.h \
    patodatamodel.h \
    PatoDataModel_global.h \
    BDPatoDataModel/source/CppSQLite3.h \
    BDPatoDataModel/source/bdpatodatamodel.h
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
    maemo5:target.path = /opt/usr/lib
    else:target.path = /usr/lib
    INSTALLS += target
}
symbian:LIBS += -lsqlite3
else:unix|win32:LIBS += -L"../output/" -L$$PWD/BDPatoDataModel/lib/ -L"$$PWD/../patoFS/BDPatoFS/lib" \
    -lsqlite3 -lPatoBase
INCLUDEPATH += $$PWD/BDPatoDataModel/source
DEPENDPATH += $$PWD/BDPatoDataModel/source












