#include <QtGui>
#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    //Actions
    connect(ui->buttonChangeRepository, SIGNAL(clicked()), this, SLOT(changePath()));
    connect(ui->buttonChangeWorkspace, SIGNAL(clicked()), this, SLOT(changePath()));
    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonExport, SIGNAL(clicked()), this, SLOT(confirmExport()));

    connect(ui->radioButtonOther, SIGNAL(clicked()), this, SLOT(enableRevisionNumber()));
    connect(ui->radioButtonHEAD, SIGNAL(clicked()), this, SLOT(disableRevisionNumber()));

    connect(ui->repositoryRadioButton, SIGNAL(clicked()), this, SLOT(enableRepositoryOptions()));
    connect(ui->workspaceRadioButton, SIGNAL(clicked()), this, SLOT(enableWorkspaceOptions()));

    connect(ui->pushButtonChooseExportPath, SIGNAL(clicked()), this, SLOT(getExportPath()));

    //Start Configurations
    ui->groupBox_2->setEnabled(false);
    ui->labelRepositoryPath->setEnabled(false);
    ui->labelWorkspacePath->setEnabled(false);
    ui->buttonChangeRepository->setEnabled(false);
    ui->buttonChangeWorkspace->setEnabled(false);
    ui->radioButtonHEAD->setChecked(true);
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);

    //Window properties
    setFixedSize(500,430);
    setWindowTitle("Export");
}

ExportDialog::~ExportDialog()
{
    delete ui;
}
void ExportDialog::setRepositoryPath(const QString &str)
{
    ui->labelRepositoryPath->setText(str);
}
void ExportDialog::setWorkspacePath(const QString &str)
{
    ui->labelWorkspacePath->setText(str);
}
void ExportDialog::changePath()
{
    emit showEnvironmentSettings();
}
void ExportDialog::enableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setFocus();
}
void ExportDialog::disableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);
}
void ExportDialog::enableRepositoryOptions()
{
    ui->groupBox_2->setEnabled(true);
    ui->labelRepositoryPath->setEnabled(true);
    ui->buttonChangeRepository->setEnabled(true);
    ui->labelWorkspacePath->setEnabled(false);
    ui->buttonChangeWorkspace->setEnabled(false);
    ui->workspaceRadioButton->setChecked(false);

}
void ExportDialog::enableWorkspaceOptions()
{
    ui->groupBox_2->setEnabled(false);
    ui->labelRepositoryPath->setEnabled(false);
    ui->buttonChangeRepository->setEnabled(false);
    ui->labelWorkspacePath->setEnabled(true);
    ui->buttonChangeWorkspace->setEnabled(true);
    ui->repositoryRadioButton->setChecked(false);
}
void ExportDialog::confirmExport()
{
    if (ui->radioButtonOther->isChecked() && ui->lineEditRevisionNumber->text().isEmpty()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("You must inform a revision number or select HEAD."),
                                          QMessageBox::Ok);
        ui->lineEditRevisionNumber->setFocus();
    }
    else if (ui->radioButtonOther->isChecked() && ui->lineEditRevisionNumber->text()=="0") {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Invalid revision number!"),
                                          QMessageBox::Ok);
        ui->lineEditRevisionNumber->setFocus();
    } else {
        //Export
    }

}
void ExportDialog::getExportPath()
{
    QString exportPath;

    exportPath = QFileDialog::getExistingDirectory(
                this,
                "Choose the Export Path",
                QString::null,
                QFileDialog::ShowDirsOnly);

    ui->lineEditExportPath->setText(exportPath);
}
