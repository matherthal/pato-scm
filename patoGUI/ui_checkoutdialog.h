/********************************************************************************
** Form generated from reading UI file 'checkoutdialog.ui'
**
** Created: Tue 25. Oct 19:20:42 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CheckoutDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelRepositoryPath;
    QPushButton *buttonChangeRepository;
    QGroupBox *groupBox_2;
    QRadioButton *radioButtonHEAD;
    QRadioButton *radioButtonOther;
    QLabel *labelRevisionNumber;
    QLineEdit *lineEditRevisionNumber;
    QPushButton *buttonCancel;
    QPushButton *buttonCheckout;

    void setupUi(QDialog *CheckoutDialog)
    {
        if (CheckoutDialog->objectName().isEmpty())
            CheckoutDialog->setObjectName(QString::fromUtf8("CheckoutDialog"));
        CheckoutDialog->resize(500, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CheckoutDialog->sizePolicy().hasHeightForWidth());
        CheckoutDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/checkinincon"), QSize(), QIcon::Normal, QIcon::Off);
        CheckoutDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(CheckoutDialog);
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
        groupBox_2 = new QGroupBox(CheckoutDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 471, 111));
        radioButtonHEAD = new QRadioButton(groupBox_2);
        radioButtonHEAD->setObjectName(QString::fromUtf8("radioButtonHEAD"));
        radioButtonHEAD->setGeometry(QRect(10, 20, 82, 17));
        radioButtonOther = new QRadioButton(groupBox_2);
        radioButtonOther->setObjectName(QString::fromUtf8("radioButtonOther"));
        radioButtonOther->setGeometry(QRect(10, 40, 51, 17));
        labelRevisionNumber = new QLabel(groupBox_2);
        labelRevisionNumber->setObjectName(QString::fromUtf8("labelRevisionNumber"));
        labelRevisionNumber->setGeometry(QRect(10, 60, 91, 16));
        lineEditRevisionNumber = new QLineEdit(groupBox_2);
        lineEditRevisionNumber->setObjectName(QString::fromUtf8("lineEditRevisionNumber"));
        lineEditRevisionNumber->setGeometry(QRect(10, 80, 81, 20));
        buttonCancel = new QPushButton(CheckoutDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(414, 220, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/cancelicon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCancel->setIcon(icon1);
        buttonCancel->setIconSize(QSize(12, 12));
        buttonCheckout = new QPushButton(CheckoutDialog);
        buttonCheckout->setObjectName(QString::fromUtf8("buttonCheckout"));
        buttonCheckout->setGeometry(QRect(330, 220, 75, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/checkouticon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCheckout->setIcon(icon2);

        retranslateUi(CheckoutDialog);

        QMetaObject::connectSlotsByName(CheckoutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckoutDialog)
    {
        CheckoutDialog->setWindowTitle(QApplication::translate("CheckoutDialog", "Check-in", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CheckoutDialog", "Check-out from:", 0, QApplication::UnicodeUTF8));
        labelRepositoryPath->setText(QApplication::translate("CheckoutDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonChangeRepository->setText(QApplication::translate("CheckoutDialog", "Change", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CheckoutDialog", "Revision:", 0, QApplication::UnicodeUTF8));
        radioButtonHEAD->setText(QApplication::translate("CheckoutDialog", "HEAD", 0, QApplication::UnicodeUTF8));
        radioButtonOther->setText(QApplication::translate("CheckoutDialog", "Other", 0, QApplication::UnicodeUTF8));
        labelRevisionNumber->setText(QApplication::translate("CheckoutDialog", "Revision Number:", 0, QApplication::UnicodeUTF8));
        lineEditRevisionNumber->setText(QApplication::translate("CheckoutDialog", "0", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CheckoutDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonCheckout->setText(QApplication::translate("CheckoutDialog", "Check-out", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckoutDialog: public Ui_CheckoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
