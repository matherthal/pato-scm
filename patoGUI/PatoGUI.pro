#-------------------------------------------------
#
# Project created by QtCreator 2011-09-20T00:25:25
#
#-------------------------------------------------

QT       += core gui

TARGET = PatoGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    checkindialog.cpp \
    environmentsettingsdialog.cpp \
    checkoutdialog.cpp \
    exportdialog.cpp \
    difftool.cpp \
    aboutdialog.cpp \
    lcs.cpp \
    diffitem.cpp \
    diff.cpp \
    logdialog.cpp \
    replogdialog.cpp \
    browserepdialog.cpp

HEADERS  += mainwindow.h \
    checkindialog.h \
    environmentsettingsdialog.h \
    checkoutdialog.h \
    exportdialog.h \
    difftool.h \
    aboutdialog.h \
    lcs.h \
    diffitem.h \
    diff.h \
    logdialog.h \
    replogdialog.h \
    browserepdialog.h

FORMS    += mainwindow.ui \
    checkindialog.ui \
    environmentsettingsdialog.ui \
    checkoutdialog.ui \
    exportdialog.ui \
    difftool.ui \
    aboutdialog.ui \
    logdialog.ui \
    replogdialog.ui \
    browserepdialog.ui

OTHER_FILES +=

RESOURCES += \
    mainwindow.qrc

LIBS += -L../output/ -lPatoClientApi
