/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Fri 11. Nov 14:05:55 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(368, 161);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/icon"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 211, 16));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 121, 141));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(100, 100));
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 30, 221, 91));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setWordWrap(true);
        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 120, 211, 31));
        label_3->setWordWrap(true);

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About Pato-SCM", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "About Pato-SCM", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("AboutDialog", "Pato-SCM is an experimental version control system developed by students at UFF (Lab GC course - 2011/2). ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AboutDialog", "It can't walk, fly or swim, but it has really good intentions.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
