#include <QtGui>
#include "mainwindow.h"
#include "environmentsettingsdialog.h"
#include "ui_environmentsettingsdialog.h"
#include "../patoClientAPI/patoclientapi.h"

EnvironmentSettingsDialog::EnvironmentSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnvironmentSettingsDialog)
{
    //Start Configurations
    ui->setupUi(this);
    ui->lineEditUserPassword->setEchoMode(QLineEdit::Password);

    //Actions
    connect(ui->pushButtonCancel, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->pushButtonApply, SIGNAL(clicked()),this, SLOT(apply()));

    connect(ui->pushButtonCreateRepository, SIGNAL(clicked()), this, SLOT(createRepository()));
    connect(ui->pushButtonChooseWorkspace, SIGNAL(clicked()), this, SLOT(getWorkspacePath()));


    //Window properties
    setWindowTitle(tr("Environment Settings"));
    setFixedSize(550,330);

}

void EnvironmentSettingsDialog::createRepository()
{
    PatoClientApi api;
    QMessageBox msg;

    QString repoName = ui->lineEditRepositoryPath->text();
    QString repoAddress = api.init(repoName, ui->lineEditUserName->text(), ui->lineEditUserPassword->text());
    if (repoAddress.isEmpty())
        msg.setInformativeText("The creation failed.");
    else
        msg.setInformativeText("Repository criated!");

    msg.exec();
    ui->lineEditRepositoryPath->clear();
    ui->lineEditRepositoryPath->setText(repoAddress);
}

//void EnvironmentSettingsDialog::getRepositoryPath()
//{
//    QString repositoryPath;

//    repositoryPath = QFileDialog::getExistingDirectory(
//                this,
//                "Choose the Repository Path",
//                QString::null,
//                QFileDialog::ShowDirsOnly);

//    ui->lineEditRepositoryPath->setText(repositoryPath);
//}

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
        emit setUserName(ui->lineEditUserName->text());
        emit setUserPassword(ui->lineEditUserPassword->text());
        this->close();
    }
}

EnvironmentSettingsDialog::~EnvironmentSettingsDialog()
{
    delete ui;
}
