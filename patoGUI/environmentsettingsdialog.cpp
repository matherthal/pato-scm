#include <QtGui>
#include "mainwindow.h"
#include "environmentsettingsdialog.h"
#include "ui_environmentsettingsdialog.h"

EnvironmentSettingsDialog::EnvironmentSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnvironmentSettingsDialog)
{
    ui->setupUi(this);
    ui->lineEditUserPassword->setEchoMode(QLineEdit::Password);

    //Connections
    connect(ui->pushButtonCancel, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->pushButtonApply, SIGNAL(clicked()),this, SLOT(apply()));

    connect(ui->pushButtonChooseRepository, SIGNAL(clicked()), this, SLOT(getRepositoryPath()));
    connect(ui->pushButtonChooseWorkspace, SIGNAL(clicked()), this, SLOT(getWorkspacePath()));


    //Window properties
    setWindowTitle(tr("Environment Settings"));
    setFixedSize(550,330);

}

void EnvironmentSettingsDialog::getRepositoryPath()
{
    QString repositoryPath;

    repositoryPath = QFileDialog::getExistingDirectory(
                this,
                "Choose the Repository Path",
                QString::null,
                QFileDialog::ShowDirsOnly);

    ui->lineEditRepositoryPath->setText(repositoryPath);
}
void EnvironmentSettingsDialog::getWorkspacePath()
{
    QString workspacePath;

    workspacePath = QFileDialog::getExistingDirectory(
                this,
                "Choose the Workspace Path",
                QString::null,
                QFileDialog::ShowDirsOnly);

    ui->lineEditWorkspacePath->setText(workspacePath);
}
void EnvironmentSettingsDialog::apply()
{
    if (ui->lineEditRepositoryPath->text().isEmpty() || ui->lineEditWorkspacePath->text().isEmpty()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Repository and Workspace paths cannot be empty."),
                                          QMessageBox::Ok);
    } else if (ui->lineEditRepositoryPath->text()==ui->lineEditWorkspacePath->text()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Repository and Workspace paths cannot be equal."),
                                          QMessageBox::Ok);

    } else {
        //Apply configurations
        emit setWorkspacePath(ui->lineEditWorkspacePath->text());
        emit setRepositoryPath(ui->lineEditRepositoryPath->text());
        //        emit setUserName(userNameEdit->text());
        //        emit setUserPassword(userPasswordEdit->text());
        this->close();
    }
}

EnvironmentSettingsDialog::~EnvironmentSettingsDialog()
{
    delete ui;
}
