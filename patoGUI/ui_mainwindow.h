/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Nov 22 21:28:18 2011
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
#include <QtGui/QTableView>
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
    QAction *actionBrowse;
    QAction *actionRepLog;
    QAction *actionLog;
    QWidget *centralWidget;
    QTreeView *treeViewWorkspace;
    QLabel *labelWorkspace;
    QLabel *labelWorkspacePath;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuPato_SCM;
    QMenu *menuHelp;
    QMenu *menuWorkspace;
    QMenu *menuPatoOthers;
    QMenu *menuRepository;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QToolBar *workspaceToolBar;
    QToolBar *diffToolBar;
    QToolBar *helpToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/icons/diff"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon9);
        actionBrowse = new QAction(MainWindow);
        actionBrowse->setObjectName(QString::fromUtf8("actionBrowse"));
        actionBrowse->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/icons/browse"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrowse->setIcon(icon10);
        actionRepLog = new QAction(MainWindow);
        actionRepLog->setObjectName(QString::fromUtf8("actionRepLog"));
        actionRepLog->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/icons/log"), QSize(), QIcon::Normal, QIcon::Off);
        actionRepLog->setIcon(icon11);
        actionLog = new QAction(MainWindow);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionLog->setEnabled(false);
        actionLog->setIcon(icon11);
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
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 19, 781, 406));
        tableView->verticalHeader()->setVisible(false);
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
        menuPatoOthers = new QMenu(menuBar);
        menuPatoOthers->setObjectName(QString::fromUtf8("menuPatoOthers"));
        menuRepository = new QMenu(menuBar);
        menuRepository->setObjectName(QString::fromUtf8("menuRepository"));
        menuRepository->setEnabled(false);
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
        workspaceToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, workspaceToolBar);
        diffToolBar = new QToolBar(MainWindow);
        diffToolBar->setObjectName(QString::fromUtf8("diffToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, diffToolBar);
        helpToolBar = new QToolBar(MainWindow);
        helpToolBar->setObjectName(QString::fromUtf8("helpToolBar"));
        helpToolBar->setLayoutDirection(Qt::RightToLeft);
        MainWindow->addToolBar(Qt::TopToolBarArea, helpToolBar);

        menuBar->addAction(menuPato_SCM->menuAction());
        menuBar->addAction(menuWorkspace->menuAction());
        menuBar->addAction(menuRepository->menuAction());
        menuBar->addAction(menuPatoOthers->menuAction());
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
        menuWorkspace->addAction(actionLog);
        menuPatoOthers->addAction(actionOpen);
        menuRepository->addAction(actionBrowse);
        menuRepository->addAction(actionRepLog);
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
        workspaceToolBar->addAction(actionLog);
        diffToolBar->addAction(actionBrowse);
        diffToolBar->addAction(actionOpen);
        helpToolBar->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "Pato-SCM", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QApplication::translate("MainWindow", "Ready", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCheckout->setText(QApplication::translate("MainWindow", "Check-out", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCheckout->setStatusTip(QApplication::translate("MainWindow", "Get revisions from the repository to the workspace", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCheckin->setText(QApplication::translate("MainWindow", "Check-in", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCheckin->setStatusTip(QApplication::translate("MainWindow", "Send the local changes to the repository", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionEnvironment_Settings->setText(QApplication::translate("MainWindow", "Environment Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionEnvironment_Settings->setStatusTip(QApplication::translate("MainWindow", "Pato-SCM environment settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionExport->setStatusTip(QApplication::translate("MainWindow", "Export project from the workspace or repository", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionHelp->setStatusTip(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAbout_Pato_SCM->setText(QApplication::translate("MainWindow", "About Pato-SCM", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAbout_Pato_SCM->setStatusTip(QApplication::translate("MainWindow", "About Pato-SCM", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAdd_File_Dir->setText(QApplication::translate("MainWindow", "Add File/Dir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAdd_File_Dir->setStatusTip(QApplication::translate("MainWindow", "Start to control the selected file or dir", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRemove_File_Dir->setText(QApplication::translate("MainWindow", "Remove File/Dir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionRemove_File_Dir->setStatusTip(QApplication::translate("MainWindow", "Stop controlling the selected file or dir", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUpdate->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionUpdate->setStatusTip(QApplication::translate("MainWindow", "Update the workspace with the new repository changes (Alert: Discart the local changes)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open Pato-Diff Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "Open Pato-Diff Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBrowse->setToolTip(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBrowse->setStatusTip(QApplication::translate("MainWindow", "Browse project at repository", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRepLog->setText(QApplication::translate("MainWindow", "Repository Log", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionRepLog->setStatusTip(QApplication::translate("MainWindow", "See revisions log from repository", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionLog->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionLog->setStatusTip(QApplication::translate("MainWindow", "Show revisions log", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        treeViewWorkspace->setToolTip(QApplication::translate("MainWindow", "Workspace View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelWorkspace->setToolTip(QApplication::translate("MainWindow", "Workspace Path", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelWorkspace->setText(QApplication::translate("MainWindow", "Workspace:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelWorkspacePath->setToolTip(QApplication::translate("MainWindow", "Workspace Path", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelWorkspacePath->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuPato_SCM->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        menuPato_SCM->setTitle(QApplication::translate("MainWindow", "Pato-SCM", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuWorkspace->setTitle(QApplication::translate("MainWindow", "Workspace", 0, QApplication::UnicodeUTF8));
        menuPatoOthers->setTitle(QApplication::translate("MainWindow", "Pato-Diff Tool", 0, QApplication::UnicodeUTF8));
        menuRepository->setTitle(QApplication::translate("MainWindow", "Repository", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QApplication::translate("MainWindow", "Ready", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        workspaceToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        diffToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        helpToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
