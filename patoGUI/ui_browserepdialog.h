/********************************************************************************
** Form generated from reading UI file 'browserepdialog.ui'
**
** Created: Tue Nov 22 21:28:19 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEREPDIALOG_H
#define UI_BROWSEREPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_BrowseRepDialog
{
public:
    QTreeView *repTreeView;
    QPushButton *OKButton;
    QLabel *label;
    QLabel *repLabel;

    void setupUi(QDialog *BrowseRepDialog)
    {
        if (BrowseRepDialog->objectName().isEmpty())
            BrowseRepDialog->setObjectName(QString::fromUtf8("BrowseRepDialog"));
        BrowseRepDialog->resize(800, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/browse"), QSize(), QIcon::Normal, QIcon::Off);
        BrowseRepDialog->setWindowIcon(icon);
        repTreeView = new QTreeView(BrowseRepDialog);
        repTreeView->setObjectName(QString::fromUtf8("repTreeView"));
        repTreeView->setGeometry(QRect(10, 29, 780, 321));
        OKButton = new QPushButton(BrowseRepDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(717, 370, 75, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/okicon"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon1);
        label = new QLabel(BrowseRepDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        repLabel = new QLabel(BrowseRepDialog);
        repLabel->setObjectName(QString::fromUtf8("repLabel"));
        repLabel->setGeometry(QRect(90, 10, 701, 16));
        QFont font1;
        font1.setPointSize(10);
        repLabel->setFont(font1);

        retranslateUi(BrowseRepDialog);

        QMetaObject::connectSlotsByName(BrowseRepDialog);
    } // setupUi

    void retranslateUi(QDialog *BrowseRepDialog)
    {
        BrowseRepDialog->setWindowTitle(QApplication::translate("BrowseRepDialog", "Browse", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("BrowseRepDialog", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BrowseRepDialog", "Repository:", 0, QApplication::UnicodeUTF8));
        repLabel->setText(QApplication::translate("BrowseRepDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BrowseRepDialog: public Ui_BrowseRepDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEREPDIALOG_H
