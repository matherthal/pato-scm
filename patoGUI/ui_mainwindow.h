/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 29. Sep 11:35:59 2011
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
    QAction *actionCheckout_Settings;
    QWidget *centralWidget;
    QTreeView *treeViewWorkspace;
    QLabel *labelWorkspace;
    QLabel *labelWorkspacePath;
    QMenuBar *menuBar;
    QMenu *menuPato_SCM;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        actionCheckout_Settings = new QAction(MainWindow);
        actionCheckout_Settings->setObjectName(QString::fromUtf8("actionCheckout_Settings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeViewWorkspace = new QTreeView(centralWidget);
        treeViewWorkspace->setObjectName(QString::fromUtf8("treeViewWorkspace"));
        treeViewWorkspace->setGeometry(QRect(10, 40, 779, 400));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeViewWorkspace->sizePolicy().hasHeightForWidth());
        treeViewWorkspace->setSizePolicy(sizePolicy);
        labelWorkspace = new QLabel(centralWidget);
        labelWorkspace->setObjectName(QString::fromUtf8("labelWorkspace"));
        labelWorkspace->setGeometry(QRect(10, 20, 61, 16));
        labelWorkspacePath = new QLabel(centralWidget);
        labelWorkspacePath->setObjectName(QString::fromUtf8("labelWorkspacePath"));
        labelWorkspacePath->setGeometry(QRect(70, 20, 711, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuPato_SCM = new QMenu(menuBar);
        menuPato_SCM->setObjectName(QString::fromUtf8("menuPato_SCM"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPato_SCM->menuAction());
        menuPato_SCM->addAction(actionCheckout_Settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCheckout_Settings->setText(QApplication::translate("MainWindow", "Checkout Settings", 0, QApplication::UnicodeUTF8));
        labelWorkspace->setText(QApplication::translate("MainWindow", "Workspace:", 0, QApplication::UnicodeUTF8));
        labelWorkspacePath->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuPato_SCM->setTitle(QApplication::translate("MainWindow", "Pato-SCM", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H