/********************************************************************************
** Form generated from reading UI file 'logdialog.ui'
**
** Created: Tue 15. Nov 14:50:13 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGDIALOG_H
#define UI_LOGDIALOG_H

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

class Ui_LogDialog
{
public:
    QPushButton *buttonOK;
    QTableWidget *logTable;
    QLabel *label;
    QTextEdit *messageTextEdit;
    QTextEdit *filesTextEdit;
    QLabel *label_2;

    void setupUi(QDialog *LogDialog)
    {
        if (LogDialog->objectName().isEmpty())
            LogDialog->setObjectName(QString::fromUtf8("LogDialog"));
        LogDialog->resize(800, 410);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogDialog->sizePolicy().hasHeightForWidth());
        LogDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/log"), QSize(), QIcon::Normal, QIcon::Off);
        LogDialog->setWindowIcon(icon);
        buttonOK = new QPushButton(LogDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setGeometry(QRect(720, 380, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/okicon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOK->setIcon(icon1);
        buttonOK->setIconSize(QSize(12, 12));
        logTable = new QTableWidget(LogDialog);
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
        label = new QLabel(LogDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 51, 16));
        messageTextEdit = new QTextEdit(LogDialog);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(10, 230, 385, 131));
        filesTextEdit = new QTextEdit(LogDialog);
        filesTextEdit->setObjectName(QString::fromUtf8("filesTextEdit"));
        filesTextEdit->setGeometry(QRect(400, 230, 390, 131));
        label_2 = new QLabel(LogDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 210, 51, 16));

        retranslateUi(LogDialog);

        QMetaObject::connectSlotsByName(LogDialog);
    } // setupUi

    void retranslateUi(QDialog *LogDialog)
    {
        LogDialog->setWindowTitle(QApplication::translate("LogDialog", "Log", 0, QApplication::UnicodeUTF8));
        buttonOK->setText(QApplication::translate("LogDialog", "OK", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = logTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LogDialog", "Revision", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = logTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LogDialog", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = logTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LogDialog", "Author", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = logTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LogDialog", "Message", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LogDialog", "Message:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogDialog", "Changes:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogDialog: public Ui_LogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGDIALOG_H
