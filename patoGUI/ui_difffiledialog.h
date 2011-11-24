/********************************************************************************
** Form generated from reading UI file 'difffiledialog.ui'
**
** Created: Tue 15. Nov 17:42:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFFILEDIALOG_H
#define UI_DIFFFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DiffFileDialog
{
public:
    QTextEdit *fileTextEdit;
    QLabel *fileOne;
    QLabel *fileTwo;
    QLabel *label;
    QPushButton *OKButton;

    void setupUi(QDialog *DiffFileDialog)
    {
        if (DiffFileDialog->objectName().isEmpty())
            DiffFileDialog->setObjectName(QString::fromUtf8("DiffFileDialog"));
        DiffFileDialog->resize(600, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/diff"), QSize(), QIcon::Normal, QIcon::Off);
        DiffFileDialog->setWindowIcon(icon);
        fileTextEdit = new QTextEdit(DiffFileDialog);
        fileTextEdit->setObjectName(QString::fromUtf8("fileTextEdit"));
        fileTextEdit->setGeometry(QRect(10, 80, 580, 391));
        fileOne = new QLabel(DiffFileDialog);
        fileOne->setObjectName(QString::fromUtf8("fileOne"));
        fileOne->setGeometry(QRect(10, 30, 581, 16));
        fileTwo = new QLabel(DiffFileDialog);
        fileTwo->setObjectName(QString::fromUtf8("fileTwo"));
        fileTwo->setGeometry(QRect(10, 50, 581, 16));
        label = new QLabel(DiffFileDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 10, 46, 13));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        OKButton = new QPushButton(DiffFileDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(520, 490, 75, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/okicon"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon1);

        retranslateUi(DiffFileDialog);

        QMetaObject::connectSlotsByName(DiffFileDialog);
    } // setupUi

    void retranslateUi(QDialog *DiffFileDialog)
    {
        DiffFileDialog->setWindowTitle(QApplication::translate("DiffFileDialog", "Diff File", 0, QApplication::UnicodeUTF8));
        fileOne->setText(QApplication::translate("DiffFileDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        fileTwo->setText(QApplication::translate("DiffFileDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DiffFileDialog", "Diff File", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("DiffFileDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiffFileDialog: public Ui_DiffFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFFILEDIALOG_H
