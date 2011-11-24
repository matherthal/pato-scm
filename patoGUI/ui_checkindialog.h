/********************************************************************************
** Form generated from reading UI file 'checkindialog.ui'
**
** Created: Wed 9. Nov 22:42:48 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINDIALOG_H
#define UI_CHECKINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CheckinDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelRepositoryPath;
    QPushButton *buttonChangeRepository;
    QGroupBox *groupBox_2;
    QTextEdit *messageEdit;
    QPushButton *buttonCancel;
    QPushButton *buttonCheckin;

    void setupUi(QDialog *CheckinDialog)
    {
        if (CheckinDialog->objectName().isEmpty())
            CheckinDialog->setObjectName(QString::fromUtf8("CheckinDialog"));
        CheckinDialog->resize(500, 270);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CheckinDialog->sizePolicy().hasHeightForWidth());
        CheckinDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/checkinincon"), QSize(), QIcon::Normal, QIcon::Off);
        CheckinDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(CheckinDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 471, 71));
        labelRepositoryPath = new QLabel(groupBox);
        labelRepositoryPath->setObjectName(QString::fromUtf8("labelRepositoryPath"));
        labelRepositoryPath->setGeometry(QRect(10, 20, 451, 16));
        QFont font;
        font.setPointSize(10);
        labelRepositoryPath->setFont(font);
        buttonChangeRepository = new QPushButton(groupBox);
        buttonChangeRepository->setObjectName(QString::fromUtf8("buttonChangeRepository"));
        buttonChangeRepository->setGeometry(QRect(390, 40, 75, 23));
        groupBox_2 = new QGroupBox(CheckinDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 471, 131));
        messageEdit = new QTextEdit(groupBox_2);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        messageEdit->setGeometry(QRect(10, 20, 451, 101));
        buttonCancel = new QPushButton(CheckinDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(414, 240, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/cancelicon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCancel->setIcon(icon1);
        buttonCancel->setIconSize(QSize(12, 12));
        buttonCheckin = new QPushButton(CheckinDialog);
        buttonCheckin->setObjectName(QString::fromUtf8("buttonCheckin"));
        buttonCheckin->setGeometry(QRect(330, 240, 75, 23));
        buttonCheckin->setIcon(icon);

        retranslateUi(CheckinDialog);

        QMetaObject::connectSlotsByName(CheckinDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckinDialog)
    {
        CheckinDialog->setWindowTitle(QApplication::translate("CheckinDialog", "Check-in", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CheckinDialog", "Check-in to:", 0, QApplication::UnicodeUTF8));
        labelRepositoryPath->setText(QApplication::translate("CheckinDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonChangeRepository->setText(QApplication::translate("CheckinDialog", "Change", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CheckinDialog", "Message:", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CheckinDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonCheckin->setText(QApplication::translate("CheckinDialog", "Check-in", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckinDialog: public Ui_CheckinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINDIALOG_H
