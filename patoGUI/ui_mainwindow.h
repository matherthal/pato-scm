/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 9. Nov 22:42:48 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCheckout;
    QAction *actionCheckin;
    QAction *actionEnvironment_Settings;
    QAction *actionExport;
    QAction *actionHelp;
    QAction *actionAbout_Pato_SCM;
    QAction *actionAdd_File_Dir;
    QAction *actionRemove_File_Dir;
    QAction *actionUpdate;
    QAction *actionOpen;
    QWidget *centralWidget;
    QTreeView *treeViewWorkspace;
    QLabel *labelWorkspace;
    QLabel *labelWorkspacePath;
    QMenuBar *menuBar;
    QMenu *menuPato_SCM;
    QMenu *menuHelp;
    QMenu *menuWorkspace;
    QMenu *menuPato_Diff_Tool;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QToolBar *workspaceToolBar;
    QToolBar *helpToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/icon"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionCheckout = new QAction(MainWindow);
        actionCheckout->setObjectName(QString::fromUtf8("actionCheckout"));
        actionCheckout->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/checkouticon"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheckout->setIcon(icon1);
        QFont font;
        font.setPointSize(9);
        actionCheckout->setFont(font);
        actionCheckin = new QAction(MainWindow);
        actionCheckin->setObjectName(QString::fromUtf8("actionCheckin"));
        actionCheckin->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/checkinincon"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheckin->setIcon(icon2);
        actionCheckin->setFont(font);
        actionEnvironment_Settings = new QAction(MainWindow);
        actionEnvironment_Settings->setObjectName(QString::fromUtf8("actionEnvironment_Settings"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/settingsicon"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnvironment_Settings->setIcon(icon3);
        actionEnvironment_Settings->setFont(font);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/exporticon"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon4);
        actionExport->setFont(font);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/help"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon5);
        actionHelp->setIconVisibleInMenu(true);
        actionAbout_Pato_SCM = new QAction(MainWindow);
        actionAbout_Pato_SCM->setObjectName(QString::fromUtf8("actionAbout_Pato_SCM"));
        actionAbout_Pato_SCM->setIcon(icon);
        actionAbout_Pato_SCM->setIconVisibleInMenu(true);
        actionAdd_File_Dir = new QAction(MainWindow);
        actionAdd_File_Dir->setObjectName(QString::fromUtf8("actionAdd_File_Dir"));
        actionAdd_File_Dir->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icons/addfile"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_File_Dir->setIcon(icon6);
        actionRemove_File_Dir = new QAction(MainWindow);
        actionRemove_File_Dir->setObjectName(QString::fromUtf8("actionRemove_File_Dir"));
        actionRemove_File_Dir->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icons/remfile"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_File_Dir->setIcon(icon7);
        actionUpdate = new QAction(MainWindow);
        actionUpdate->setObjectName(QString::fromUtf8("actionUpdate"));
        actionUpdate->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/icons/update"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpdate->setIcon(icon8);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeViewWorkspace = new QTreeView(centralWidget);
        treeViewWorkspace->setObjectName(QString::fromUtf8("treeViewWorkspace"));
        treeViewWorkspace->setGeometry(QRect(10, 19, 779, 421));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeViewWorkspace->sizePolicy().hasHeightForWidth());
        treeViewWorkspace->setSizePolicy(sizePolicy);
        treeViewWorkspace->setStyleSheet(QString::fromUtf8(""));
        labelWorkspace = new QLabel(centralWidget);
        labelWorkspace->setObjectName(QString::fromUtf8("labelWorkspace"));
        labelWorkspace->setGeometry(QRect(10, 0, 81, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelWorkspace->setFont(font1);
        labelWorkspacePath = new QLabel(centralWidget);
        labelWorkspacePath->setObjectName(QString::fromUtf8("labelWorkspacePath"));
        labelWorkspacePath->setGeometry(QRect(90, 0, 691, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setItalic(false);
        labelWorkspacePath->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        menuBar->setFont(font3);
        menuPato_SCM = new QMenu(menuBar);
        menuPato_SCM->setObjectName(QString::fromUtf8("menuPato_SCM"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuWorkspace = new QMenu(menuBar);
        menuWorkspace->setObjectName(QString::fromUtf8("menuWorkspace"));
        menuWorkspace->setEnabled(false);
        menuPato_Diff_Tool = new QMenu(menuBar);
        menuPato_Diff_Tool->setObjectName(QString::fromUtf8("menuPato_Diff_Tool"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(24, 24));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        workspaceToolBar = new QToolBar(MainWindow);
        workspaceToolBar->setObjectName(QString::fromUtf8("workspaceToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, workspaceToolBar);
        helpToolBar = new QToolBar(MainWindow);
        helpToolBar->setObjectName(QString::fromUtf8("helpToolBar"));
        helpToolBar->setLayoutDirection(Qt::RightToLeft);
        helpToolBar->setIconSize(QSize(18, 18));
        MainWindow->addToolBar(Qt::TopToolBarArea, helpToolBar);

        menuBar->addAction(menuPato_SCM->menuAction());
        menuBar->addAction(menuWorkspace->menuAction());
        menuBar->addAction(menuPato_Diff_Tool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuPato_SCM->addAction(actionEnvironment_Settings);
        menuPato_SCM->addSeparator();
        menuPato_SCM->addAction(actionCheckin);
        menuPato_SCM->addAction(actionCheckout);
        menuPato_SCM->addSeparator();
        menuPato_SCM->addAction(actionExport);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout_Pato_SCM);
        menuWorkspace->addAction(actionAdd_File_Dir);
        menuWorkspace->addAction(actionRemove_File_Dir);
        menuWorkspace->addSeparator();
        menuWorkspace->addAction(actionUpdate);
        menuPato_Diff_Tool->addAction(actionOpen);
        mainToolBar->addAction(actionEnvironment_Settings);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCheckin);
        mainToolBar->addAction(actionCheckout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExport);
        workspaceToolBar->addAction(actionAdd_File_Dir);
        workspaceToolBar->addAction(actionRemove_File_Dir);
        workspaceToolBar->addSeparator();
        workspaceToolBar->addAction(actionUpdate);
        helpToolBar->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCheckout->setText(QApplication::translate("MainWindow", "Check-out", 0, QApplication::UnicodeUTF8));
        actionCheckin->setText(QApplication::translate("MainWindow", "Check-in", 0, QApplication::UnicodeUTF8));
        actionEnvironment_Settings->setText(QApplication::translate("MainWindow", "Environment Settings", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionAbout_Pato_SCM->setText(QApplication::translate("MainWindow", "About Pato-SCM", 0, QApplication::UnicodeUTF8));
        actionAdd_File_Dir->setText(QApplication::translate("MainWindow", "Add File/Dir", 0, QApplication::UnicodeUTF8));
        actionRemove_File_Dir->setText(QApplication::translate("MainWindow", "Remove File/Dir", 0, QApplication::UnicodeUTF8));
        actionUpdate->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        labelWorkspace->setText(QApplication::translate("MainWindow", "Workspace:", 0, QApplication::UnicodeUTF8));
        labelWorkspacePath->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuPato_SCM->setTitle(QApplication::translate("MainWindow", "Pato-SCM", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuWorkspace->setTitle(QApplication::translate("MainWindow", "Workspace", 0, QApplication::UnicodeUTF8));
        menuPato_Diff_Tool->setTitle(QApplication::translate("MainWindow", "Pato-Diff Tool", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        workspaceToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        helpToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
