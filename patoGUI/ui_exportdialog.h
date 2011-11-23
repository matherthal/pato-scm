/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created: Tue Nov 22 21:28:19 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ExportDialog
{
public:
    QGroupBox *groupBox;
    QRadioButton *repositoryRadioButton;
    QLabel *labelRepositoryPath;
    QPushButton *buttonChangeRepository;
    QGroupBox *groupBox_2;
    QRadioButton *radioButtonHEAD;
    QRadioButton *radioButtonOther;
    QLabel *labelRevisionNumber;
    QLineEdit *lineEditRevisionNumber;
    QRadioButton *workspaceRadioButton;
    QFrame *line;
    QLabel *labelWorkspacePath;
    QPushButton *buttonChangeWorkspace;
    QPushButton *buttonCancel;
    QPushButton *buttonExport;
    QGroupBox *groupBox_3;
    QLineEdit *lineEditExportPath;
    QPushButton *pushButtonChooseExportPath;

    void setupUi(QDialog *ExportDialog)
    {
        if (ExportDialog->objectName().isEmpty())
            ExportDialog->setObjectName(QString::fromUtf8("ExportDialog"));
        ExportDialog->resize(500, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExportDialog->sizePolicy().hasHeightForWidth());
        ExportDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/exporticon"), QSize(), QIcon::Normal, QIcon::Off);
        ExportDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(ExportDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 481, 311));
        repositoryRadioButton = new QRadioButton(groupBox);
        repositoryRadioButton->setObjectName(QString::fromUtf8("repositoryRadioButton"));
        repositoryRadioButton->setGeometry(QRect(10, 20, 82, 17));
        QFont font;
        font.setPointSize(10);
        repositoryRadioButton->setFont(font);
        labelRepositoryPath = new QLabel(groupBox);
        labelRepositoryPath->setObjectName(QString::fromUtf8("labelRepositoryPath"));
        labelRepositoryPath->setGeometry(QRect(10, 50, 461, 16));
        labelRepositoryPath->setFont(font);
        buttonChangeRepository = new QPushButton(groupBox);
        buttonChangeRepository->setObjectName(QString::fromUtf8("buttonChangeRepository"));
        buttonChangeRepository->setGeometry(QRect(400, 70, 75, 23));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 461, 111));
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
        workspaceRadioButton = new QRadioButton(groupBox);
        workspaceRadioButton->setObjectName(QString::fromUtf8("workspaceRadioButton"));
        workspaceRadioButton->setGeometry(QRect(10, 230, 82, 17));
        workspaceRadioButton->setFont(font);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, 220, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelWorkspacePath = new QLabel(groupBox);
        labelWorkspacePath->setObjectName(QString::fromUtf8("labelWorkspacePath"));
        labelWorkspacePath->setGeometry(QRect(10, 260, 461, 16));
        labelWorkspacePath->setFont(font);
        buttonChangeWorkspace = new QPushButton(groupBox);
        buttonChangeWorkspace->setObjectName(QString::fromUtf8("buttonChangeWorkspace"));
        buttonChangeWorkspace->setGeometry(QRect(400, 280, 75, 23));
        buttonCancel = new QPushButton(ExportDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(420, 390, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/cancelicon"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCancel->setIcon(icon1);
        buttonCancel->setIconSize(QSize(12, 12));
        buttonExport = new QPushButton(ExportDialog);
        buttonExport->setObjectName(QString::fromUtf8("buttonExport"));
        buttonExport->setGeometry(QRect(340, 390, 75, 23));
        buttonExport->setIcon(icon);
        groupBox_3 = new QGroupBox(ExportDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 330, 481, 51));
        lineEditExportPath = new QLineEdit(groupBox_3);
        lineEditExportPath->setObjectName(QString::fromUtf8("lineEditExportPath"));
        lineEditExportPath->setGeometry(QRect(10, 20, 381, 20));
        pushButtonChooseExportPath = new QPushButton(groupBox_3);
        pushButtonChooseExportPath->setObjectName(QString::fromUtf8("pushButtonChooseExportPath"));
        pushButtonChooseExportPath->setGeometry(QRect(400, 20, 75, 23));

        retranslateUi(ExportDialog);

        QMetaObject::connectSlotsByName(ExportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDialog)
    {
        ExportDialog->setWindowTitle(QApplication::translate("ExportDialog", "Check-in", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ExportDialog", "Export from:", 0, QApplication::UnicodeUTF8));
        repositoryRadioButton->setText(QApplication::translate("ExportDialog", "Repository", 0, QApplication::UnicodeUTF8));
        labelRepositoryPath->setText(QApplication::translate("ExportDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonChangeRepository->setText(QApplication::translate("ExportDialog", "Change", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ExportDialog", "Revision:", 0, QApplication::UnicodeUTF8));
        radioButtonHEAD->setText(QApplication::translate("ExportDialog", "HEAD", 0, QApplication::UnicodeUTF8));
        radioButtonOther->setText(QApplication::translate("ExportDialog", "Other", 0, QApplication::UnicodeUTF8));
        labelRevisionNumber->setText(QApplication::translate("ExportDialog", "Revision Number:", 0, QApplication::UnicodeUTF8));
        lineEditRevisionNumber->setText(QApplication::translate("ExportDialog", "0", 0, QApplication::UnicodeUTF8));
        workspaceRadioButton->setText(QApplication::translate("ExportDialog", "Workspace", 0, QApplication::UnicodeUTF8));
        labelWorkspacePath->setText(QApplication::translate("ExportDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonChangeWorkspace->setText(QApplication::translate("ExportDialog", "Change", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("ExportDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonExport->setText(QApplication::translate("ExportDialog", "Export", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ExportDialog", "Export to:", 0, QApplication::UnicodeUTF8));
        pushButtonChooseExportPath->setText(QApplication::translate("ExportDialog", "Choose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportDialog: public Ui_ExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
