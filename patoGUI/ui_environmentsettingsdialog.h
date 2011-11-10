/********************************************************************************
** Form generated from reading UI file 'environmentsettingsdialog.ui'
**
** Created: Wed 9. Nov 22:42:48 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIRONMENTSETTINGSDIALOG_H
#define UI_ENVIRONMENTSETTINGSDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_EnvironmentSettingsDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelRepositoryPath;
    QLabel *labelWorkspacePath;
    QLineEdit *lineEditRepositoryPath;
    QLineEdit *lineEditWorkspacePath;
    QPushButton *pushButtonChooseRepository;
    QPushButton *pushButtonChooseWorkspace;
    QGroupBox *groupBox_2;
    QLabel *labelUserName;
    QLabel *labelUserPassword;
    QLineEdit *lineEditUserName;
    QLineEdit *lineEditUserPassword;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *EnvironmentSettingsDialog)
    {
        if (EnvironmentSettingsDialog->objectName().isEmpty())
            EnvironmentSettingsDialog->setObjectName(QString::fromUtf8("EnvironmentSettingsDialog"));
        EnvironmentSettingsDialog->resize(550, 330);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/settingsicon"), QSize(), QIcon::Normal, QIcon::Off);
        EnvironmentSettingsDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(EnvironmentSettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 531, 131));
        labelRepositoryPath = new QLabel(groupBox);
        labelRepositoryPath->setObjectName(QString::fromUtf8("labelRepositoryPath"));
        labelRepositoryPath->setGeometry(QRect(10, 20, 91, 16));
        labelWorkspacePath = new QLabel(groupBox);
        labelWorkspacePath->setObjectName(QString::fromUtf8("labelWorkspacePath"));
        labelWorkspacePath->setGeometry(QRect(10, 70, 91, 16));
        lineEditRepositoryPath = new QLineEdit(groupBox);
        lineEditRepositoryPath->setObjectName(QString::fromUtf8("lineEditRepositoryPath"));
        lineEditRepositoryPath->setGeometry(QRect(10, 40, 431, 20));
        lineEditWorkspacePath = new QLineEdit(groupBox);
        lineEditWorkspacePath->setObjectName(QString::fromUtf8("lineEditWorkspacePath"));
        lineEditWorkspacePath->setGeometry(QRect(10, 90, 431, 20));
        pushButtonChooseRepository = new QPushButton(groupBox);
        pushButtonChooseRepository->setObjectName(QString::fromUtf8("pushButtonChooseRepository"));
        pushButtonChooseRepository->setGeometry(QRect(450, 40, 75, 23));
        pushButtonChooseWorkspace = new QPushButton(groupBox);
        pushButtonChooseWorkspace->setObjectName(QString::fromUtf8("pushButtonChooseWorkspace"));
        pushButtonChooseWorkspace->setGeometry(QRect(450, 90, 75, 23));
        groupBox_2 = new QGroupBox(EnvironmentSettingsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 531, 121));
        labelUserName = new QLabel(groupBox_2);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setGeometry(QRect(10, 20, 46, 13));
        labelUserPassword = new QLabel(groupBox_2);
        labelUserPassword->setObjectName(QString::fromUtf8("labelUserPassword"));
        labelUserPassword->setGeometry(QRect(10, 70, 51, 16));
        lineEditUserName = new QLineEdit(groupBox_2);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(10, 40, 151, 20));
        lineEditUserPassword = new QLineEdit(groupBox_2);
        lineEditUserPassword->setObjectName(QString::fromUtf8("lineEditUserPassword"));
        lineEditUserPassword->setGeometry(QRect(10, 90, 151, 20));
        pushButtonApply = new QPushButton(EnvironmentSettingsDialog);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(390, 300, 75, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/okicon"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonApply->setIcon(icon1);
        pushButtonCancel = new QPushButton(EnvironmentSettingsDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(470, 300, 75, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/cancelicon"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        retranslateUi(EnvironmentSettingsDialog);

        QMetaObject::connectSlotsByName(EnvironmentSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *EnvironmentSettingsDialog)
    {
        EnvironmentSettingsDialog->setWindowTitle(QApplication::translate("EnvironmentSettingsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("EnvironmentSettingsDialog", "Default Paths:", 0, QApplication::UnicodeUTF8));
        labelRepositoryPath->setText(QApplication::translate("EnvironmentSettingsDialog", "Repository Path:", 0, QApplication::UnicodeUTF8));
        labelWorkspacePath->setText(QApplication::translate("EnvironmentSettingsDialog", "Workspace Path:", 0, QApplication::UnicodeUTF8));
        pushButtonChooseRepository->setText(QApplication::translate("EnvironmentSettingsDialog", "Choose", 0, QApplication::UnicodeUTF8));
        pushButtonChooseWorkspace->setText(QApplication::translate("EnvironmentSettingsDialog", "Choose", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("EnvironmentSettingsDialog", "User Authentication:", 0, QApplication::UnicodeUTF8));
        labelUserName->setText(QApplication::translate("EnvironmentSettingsDialog", "User:", 0, QApplication::UnicodeUTF8));
        labelUserPassword->setText(QApplication::translate("EnvironmentSettingsDialog", "Password:", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("EnvironmentSettingsDialog", "Apply", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("EnvironmentSettingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EnvironmentSettingsDialog: public Ui_EnvironmentSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIRONMENTSETTINGSDIALOG_H
