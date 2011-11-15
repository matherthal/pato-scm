/********************************************************************************
** Form generated from reading UI file 'difftool.ui'
**
** Created: Tue 15. Nov 17:50:57 2011
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
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffTool
{
public:
    QAction *actionLoad_File_1;
    QAction *actionLoad_File_2;
    QAction *actionOneAgainstTwo;
    QAction *actionTwoAgainstOne;
    QAction *actionOpenDiffFile;
    QWidget *centralwidget;
    QTableWidget *fileOneTableWidget;
    QTableWidget *fileTwoTableWidget;
    QLabel *fileOneLabel;
    QLabel *fileTwoLabel;
    QLabel *label;
    QLabel *label_2;
    QPushButton *oneTwo;
    QPushButton *twoOne;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuShow_Differences;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DiffTool)
    {
        if (DiffTool->objectName().isEmpty())
            DiffTool->setObjectName(QString::fromUtf8("DiffTool"));
        DiffTool->setEnabled(true);
        DiffTool->resize(842, 635);
        QFont font;
        font.setPointSize(10);
        DiffTool->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/diff"), QSize(), QIcon::Normal, QIcon::Off);
        DiffTool->setWindowIcon(icon);
        actionLoad_File_1 = new QAction(DiffTool);
        actionLoad_File_1->setObjectName(QString::fromUtf8("actionLoad_File_1"));
        actionLoad_File_2 = new QAction(DiffTool);
        actionLoad_File_2->setObjectName(QString::fromUtf8("actionLoad_File_2"));
        actionLoad_File_2->setEnabled(false);
        actionOneAgainstTwo = new QAction(DiffTool);
        actionOneAgainstTwo->setObjectName(QString::fromUtf8("actionOneAgainstTwo"));
        actionOneAgainstTwo->setEnabled(false);
        actionTwoAgainstOne = new QAction(DiffTool);
        actionTwoAgainstOne->setObjectName(QString::fromUtf8("actionTwoAgainstOne"));
        actionTwoAgainstOne->setEnabled(false);
        actionOpenDiffFile = new QAction(DiffTool);
        actionOpenDiffFile->setObjectName(QString::fromUtf8("actionOpenDiffFile"));
        actionOpenDiffFile->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/file"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenDiffFile->setIcon(icon1);
        centralwidget = new QWidget(DiffTool);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        fileOneTableWidget = new QTableWidget(centralwidget);
        fileOneTableWidget->setObjectName(QString::fromUtf8("fileOneTableWidget"));
        fileOneTableWidget->setEnabled(true);
        fileOneTableWidget->setGeometry(QRect(10, 40, 381, 511));
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
        fileTwoTableWidget->setGeometry(QRect(450, 40, 381, 511));
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
        fileTwoLabel->setGeometry(QRect(450, 20, 381, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 5, 41, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 5, 41, 16));
        label_2->setFont(font1);
        oneTwo = new QPushButton(centralwidget);
        oneTwo->setObjectName(QString::fromUtf8("oneTwo"));
        oneTwo->setEnabled(false);
        oneTwo->setGeometry(QRect(400, 210, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/dir"), QSize(), QIcon::Normal, QIcon::Off);
        oneTwo->setIcon(icon2);
        oneTwo->setIconSize(QSize(30, 30));
        twoOne = new QPushButton(centralwidget);
        twoOne->setObjectName(QString::fromUtf8("twoOne"));
        twoOne->setEnabled(false);
        twoOne->setGeometry(QRect(400, 280, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/esq"), QSize(), QIcon::Normal, QIcon::Off);
        twoOne->setIcon(icon3);
        twoOne->setIconSize(QSize(30, 30));
        DiffTool->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DiffTool);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 842, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        menubar->setFont(font2);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setEnabled(true);
        menuShow_Differences = new QMenu(menubar);
        menuShow_Differences->setObjectName(QString::fromUtf8("menuShow_Differences"));
        menuShow_Differences->setEnabled(false);
        DiffTool->setMenuBar(menubar);
        statusbar = new QStatusBar(DiffTool);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DiffTool->setStatusBar(statusbar);
        toolBar = new QToolBar(DiffTool);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        DiffTool->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuShow_Differences->menuAction());
        menuFile->addAction(actionLoad_File_1);
        menuFile->addAction(actionLoad_File_2);
        menuShow_Differences->addAction(actionOneAgainstTwo);
        menuShow_Differences->addAction(actionTwoAgainstOne);
        menuShow_Differences->addSeparator();
        menuShow_Differences->addAction(actionOpenDiffFile);
        toolBar->addAction(actionOpenDiffFile);

        retranslateUi(DiffTool);

        QMetaObject::connectSlotsByName(DiffTool);
    } // setupUi

    void retranslateUi(QMainWindow *DiffTool)
    {
        DiffTool->setWindowTitle(QApplication::translate("DiffTool", "Pato-Diff Tool", 0, QApplication::UnicodeUTF8));
        actionLoad_File_1->setText(QApplication::translate("DiffTool", "Load File 1", 0, QApplication::UnicodeUTF8));
        actionLoad_File_2->setText(QApplication::translate("DiffTool", "Load File 2", 0, QApplication::UnicodeUTF8));
        actionOneAgainstTwo->setText(QApplication::translate("DiffTool", "File 1 Against File 2", 0, QApplication::UnicodeUTF8));
        actionTwoAgainstOne->setText(QApplication::translate("DiffTool", "File 2 Against File 1", 0, QApplication::UnicodeUTF8));
        actionOpenDiffFile->setText(QApplication::translate("DiffTool", "Open Diff File", 0, QApplication::UnicodeUTF8));
        fileOneLabel->setText(QApplication::translate("DiffTool", "TextLabel", 0, QApplication::UnicodeUTF8));
        fileTwoLabel->setText(QApplication::translate("DiffTool", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DiffTool", "File 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DiffTool", "File 2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        oneTwo->setToolTip(QApplication::translate("DiffTool", "File 1 Against File 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        oneTwo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        oneTwo->setText(QString());
#ifndef QT_NO_TOOLTIP
        twoOne->setToolTip(QApplication::translate("DiffTool", "File 1 Against File 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        twoOne->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        twoOne->setText(QString());
        menuFile->setTitle(QApplication::translate("DiffTool", "File", 0, QApplication::UnicodeUTF8));
        menuShow_Differences->setTitle(QApplication::translate("DiffTool", "Show Differences", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("DiffTool", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiffTool: public Ui_DiffTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFTOOL_H
