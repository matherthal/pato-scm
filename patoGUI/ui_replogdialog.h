/********************************************************************************
** Form generated from reading UI file 'replogdialog.ui'
**
** Created: Tue 15. Nov 14:48:10 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLOGDIALOG_H
#define UI_REPLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_RepLogDialog
{
public:
    QPushButton *buttonOK;
    QPushButton *buttonRefresh;
    QTableWidget *logTable;
    QLabel *label;
    QTextEdit *messageTextEdit;
    QTextEdit *filesTextEdit;
    QLabel *label_2;

    void setupUi(QDialog *RepLogDialog)
    {
        if (RepLogDialog->objectName().isEmpty())
            RepLogDialog->setObjectName(QString::fromUtf8("RepLogDialog"));
        RepLogDialog->resize(800, 440);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RepLogDialog->sizePolicy().hasHeightForWidth());
        RepLogDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/log"), QSize(), QIcon::Normal, QIcon::Off);
        RepLogDialog->setWindowIcon(icon);
        buttonOK = new QPushButton(RepLogDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setGeometry(QRect(720, 410, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/okicon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOK->setIcon(icon1);
        buttonOK->setIconSize(QSize(12, 12));
        buttonRefresh = new QPushButton(RepLogDialog);
        buttonRefresh->setObjectName(QString::fromUtf8("buttonRefresh"));
        buttonRefresh->setGeometry(QRect(360, 370, 75, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/update"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRefresh->setIcon(icon2);
        logTable = new QTableWidget(RepLogDialog);
        if (logTable->columnCount() < 4)
            logTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        logTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        logTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        logTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        logTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        logTable->setObjectName(QString::fromUtf8("logTable"));
        logTable->setGeometry(QRect(10, 10, 780, 192));
        logTable->setGridStyle(Qt::NoPen);
        logTable->setSortingEnabled(true);
        logTable->setCornerButtonEnabled(false);
        logTable->setColumnCount(4);
        logTable->verticalHeader()->setVisible(false);
        logTable->verticalHeader()->setDefaultSectionSize(29);
        logTable->verticalHeader()->setHighlightSections(false);
        logTable->verticalHeader()->setMinimumSectionSize(19);
        label = new QLabel(RepLogDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 51, 16));
        messageTextEdit = new QTextEdit(RepLogDialog);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(10, 230, 385, 131));
        filesTextEdit = new QTextEdit(RepLogDialog);
        filesTextEdit->setObjectName(QString::fromUtf8("filesTextEdit"));
        filesTextEdit->setGeometry(QRect(400, 230, 390, 131));
        label_2 = new QLabel(RepLogDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 210, 51, 16));

        retranslateUi(RepLogDialog);

        QMetaObject::connectSlotsByName(RepLogDialog);
    } // setupUi

    void retranslateUi(QDialog *RepLogDialog)
    {
        RepLogDialog->setWindowTitle(QApplication::translate("RepLogDialog", "Repository Log", 0, QApplication::UnicodeUTF8));
        buttonOK->setText(QApplication::translate("RepLogDialog", "OK", 0, QApplication::UnicodeUTF8));
        buttonRefresh->setText(QApplication::translate("RepLogDialog", "Refresh", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = logTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RepLogDialog", "Revision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = logTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RepLogDialog", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = logTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RepLogDialog", "Author", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = logTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RepLogDialog", "Message", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RepLogDialog", "Message:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RepLogDialog", "Changes:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RepLogDialog: public Ui_RepLogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLOGDIALOG_H
