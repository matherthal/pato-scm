/********************************************************************************
** Form generated from reading UI file 'difftool.ui'
**
** Created: Wed 9. Nov 22:56:44 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFTOOL_H
#define UI_DIFFTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffTool
{
public:
    QAction *actionLoad_File_1;
    QAction *actionLoad_File_2;
    QAction *actionOneAgainstTwo;
    QAction *actionTwoAgainstOne;
    QWidget *centralwidget;
    QTableWidget *fileOneTableWidget;
    QTableWidget *fileTwoTableWidget;
    QLabel *fileOneLabel;
    QLabel *fileTwoLabel;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuShow_Differences;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DiffTool)
    {
        if (DiffTool->objectName().isEmpty())
            DiffTool->setObjectName(QString::fromUtf8("DiffTool"));
        DiffTool->setEnabled(true);
        DiffTool->resize(800, 600);
        QFont font;
        font.setPointSize(10);
        DiffTool->setFont(font);
        actionLoad_File_1 = new QAction(DiffTool);
        actionLoad_File_1->setObjectName(QString::fromUtf8("actionLoad_File_1"));
        actionLoad_File_2 = new QAction(DiffTool);
        actionLoad_File_2->setObjectName(QString::fromUtf8("actionLoad_File_2"));
        actionOneAgainstTwo = new QAction(DiffTool);
        actionOneAgainstTwo->setObjectName(QString::fromUtf8("actionOneAgainstTwo"));
        actionTwoAgainstOne = new QAction(DiffTool);
        actionTwoAgainstOne->setObjectName(QString::fromUtf8("actionTwoAgainstOne"));
        centralwidget = new QWidget(DiffTool);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        fileOneTableWidget = new QTableWidget(centralwidget);
        fileOneTableWidget->setObjectName(QString::fromUtf8("fileOneTableWidget"));
        fileOneTableWidget->setEnabled(true);
        fileOneTableWidget->setGeometry(QRect(10, 40, 381, 320));
        fileOneTableWidget->setShowGrid(false);
        fileOneTableWidget->setRowCount(0);
        fileOneTableWidget->setColumnCount(0);
        fileOneTableWidget->horizontalHeader()->setVisible(false);
        fileOneTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        fileOneTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        fileOneTableWidget->horizontalHeader()->setHighlightSections(false);
        fileOneTableWidget->verticalHeader()->setCascadingSectionResizes(true);
        fileOneTableWidget->verticalHeader()->setDefaultSectionSize(30);
        fileOneTableWidget->verticalHeader()->setHighlightSections(false);
        fileTwoTableWidget = new QTableWidget(centralwidget);
        fileTwoTableWidget->setObjectName(QString::fromUtf8("fileTwoTableWidget"));
        fileTwoTableWidget->setEnabled(true);
        fileTwoTableWidget->setGeometry(QRect(410, 40, 381, 320));
        fileTwoTableWidget->setShowGrid(false);
        fileTwoTableWidget->setRowCount(0);
        fileTwoTableWidget->setColumnCount(0);
        fileTwoTableWidget->horizontalHeader()->setVisible(false);
        fileTwoTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        fileTwoTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        fileTwoTableWidget->horizontalHeader()->setHighlightSections(false);
        fileTwoTableWidget->verticalHeader()->setCascadingSectionResizes(true);
        fileTwoTableWidget->verticalHeader()->setDefaultSectionSize(30);
        fileTwoTableWidget->verticalHeader()->setHighlightSections(false);
        fileOneLabel = new QLabel(centralwidget);
        fileOneLabel->setObjectName(QString::fromUtf8("fileOneLabel"));
        fileOneLabel->setGeometry(QRect(10, 20, 381, 16));
        fileTwoLabel = new QLabel(centralwidget);
        fileTwoLabel->setObjectName(QString::fromUtf8("fileTwoLabel"));
        fileTwoLabel->setGeometry(QRect(410, 20, 381, 16));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 370, 341, 171));
        DiffTool->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DiffTool);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 800, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        menubar->setFont(font1);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setEnabled(true);
        menuShow_Differences = new QMenu(menubar);
        menuShow_Differences->setObjectName(QString::fromUtf8("menuShow_Differences"));
        DiffTool->setMenuBar(menubar);
        statusbar = new QStatusBar(DiffTool);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DiffTool->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuShow_Differences->menuAction());
        menuFile->addAction(actionLoad_File_1);
        menuFile->addAction(actionLoad_File_2);
        menuShow_Differences->addAction(actionOneAgainstTwo);
        menuShow_Differences->addAction(actionTwoAgainstOne);

        retranslateUi(DiffTool);

        QMetaObject::connectSlotsByName(DiffTool);
    } // setupUi

    void retranslateUi(QMainWindow *DiffTool)
    {
        DiffTool->setWindowTitle(QApplication::translate("DiffTool", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLoad_File_1->setText(QApplication::translate("DiffTool", "Load File 1", 0, QApplication::UnicodeUTF8));
        actionLoad_File_2->setText(QApplication::translate("DiffTool", "Load File 2", 0, QApplication::UnicodeUTF8));
        actionOneAgainstTwo->setText(QApplication::translate("DiffTool", "File 1 Against File 2", 0, QApplication::UnicodeUTF8));
        actionTwoAgainstOne->setText(QApplication::translate("DiffTool", "File 2 Against File 1", 0, QApplication::UnicodeUTF8));
        fileOneLabel->setText(QApplication::translate("DiffTool", "TextLabel", 0, QApplication::UnicodeUTF8));
        fileTwoLabel->setText(QApplication::translate("DiffTool", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("DiffTool", "File", 0, QApplication::UnicodeUTF8));
        menuShow_Differences->setTitle(QApplication::translate("DiffTool", "Show Differences", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiffTool: public Ui_DiffTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFTOOL_H
