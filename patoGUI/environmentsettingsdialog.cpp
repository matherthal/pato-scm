#include <QtGui>
#include "mainwindow.h"
#include "environmentsettingsdialog.h"

EnvironmentSettingsDialog::EnvironmentSettingsDialog(QWidget *parent): QDialog(parent)
{
    //Components
    repositoryPathLabel = new QLabel(tr("Repository Path:"));
    repositoryPathEdit = new QLineEdit;
    repositoryPathEdit->setMinimumWidth(380);
    repositoryPathLabel->setBuddy(repositoryPathEdit);
    chooseRepositoryButton = new QPushButton(tr("&Choose"));

    workspacePathLabel = new QLabel(tr("Workspace Path:"));
    workspacePathEdit = new QLineEdit;
    workspacePathLabel->setBuddy(workspacePathEdit);
    chooseWorkspaceButton = new QPushButton(tr("&Choose"));

    userNameLabel = new QLabel(tr("User:"));
    userNameEdit = new QLineEdit;
    userNameLabel->setBuddy(userNameEdit);
    userNameLabel->setVisible(false);
    userNameEdit->setVisible(false);

    userPasswordLabel = new QLabel(tr("Password:"));
    userPasswordEdit = new QLineEdit;
    userPasswordLabel->setBuddy(userPasswordEdit);
    userPasswordLabel->setVisible(false);
    userPasswordEdit->setVisible(false);

    userAuthenticationBox = new QCheckBox(tr("User Authentication"));

    cancelButton = new QPushButton(tr("Cancel"));
    applyButton = new QPushButton(tr("Apply"));

    //Connections
    connect(cancelButton, SIGNAL(clicked()),this, SLOT(close()));
    connect(applyButton, SIGNAL(clicked()),this, SLOT(apply()));

    connect(chooseRepositoryButton, SIGNAL(clicked()), this, SLOT(getRepositoryPath()));
    connect(chooseWorkspaceButton, SIGNAL(clicked()), this, SLOT(getWorkspacePath()));
    connect(userAuthenticationBox, SIGNAL(clicked()),this, SLOT(getAuthentication()));

    //Layout
    QHBoxLayout *line1Layout = new QHBoxLayout;
    line1Layout->addWidget(repositoryPathLabel);
    line1Layout->addWidget(repositoryPathEdit);
    line1Layout->addWidget(chooseRepositoryButton);
    QHBoxLayout *line2Layout = new QHBoxLayout;
    line2Layout->addWidget(workspacePathLabel);
    line2Layout->addWidget(workspacePathEdit);
    line2Layout->addWidget(chooseWorkspaceButton);
    QHBoxLayout *line3Layout = new QHBoxLayout;
    line3Layout->addWidget(userAuthenticationBox);
    line3Layout->addWidget(userNameLabel);
    line3Layout->addWidget(userNameEdit);
    line3Layout->addWidget(userPasswordLabel);
    line3Layout->addWidget(userPasswordEdit);
    line3Layout->addStretch();
    QHBoxLayout *line4Layout = new QHBoxLayout;
    line4Layout->addWidget(applyButton);
    line4Layout->addWidget(cancelButton);
    line4Layout->addStretch();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(line1Layout);
    mainLayout->addLayout(line2Layout);
    mainLayout->addLayout(line3Layout);
    mainLayout->addLayout(line4Layout);
    setLayout(mainLayout);

    //Window properties
    setWindowTitle(tr("Environment Settings"));
    setFixedHeight(sizeHint().height());
}
void EnvironmentSettingsDialog::getRepositoryPath()
{
    QString repositoryPath;

    repositoryPath = QFileDialog::getExistingDirectory(
                this,
                "Choose the Repository Path",
                QString::null,
                QFileDialog::ShowDirsOnly);

    repositoryPathEdit->setText(repositoryPath);
}
void EnvironmentSettingsDialog::getWorkspacePath()
{
    QString workspacePath;

    workspacePath = QFileDialog::getExistingDirectory(
                this,
                "Choose the Workspace Path",
                QString::null,
                QFileDialog::ShowDirsOnly);

    workspacePathEdit->setText(workspacePath);
}
void EnvironmentSettingsDialog::getAuthentication()
{
    //Get the user name and password if the userAuthenticationBox is checked.
    if (userAuthenticationBox->isChecked()) {
        userNameLabel->setVisible(true);
        userNameEdit->setVisible(true);
        userPasswordLabel->setVisible(true);
        userPasswordEdit->setVisible(true);
    } else {
        userNameLabel->setVisible(false);
        userNameEdit->setVisible(false);
        userPasswordLabel->setVisible(false);
        userPasswordEdit->setVisible(false);
    }
}
void EnvironmentSettingsDialog::apply()
{
    if (repositoryPathEdit->text().isEmpty() || workspacePathEdit->text().isEmpty()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Repository and Workspace paths cannot be empty."),
                                          QMessageBox::Ok);
    } if (repositoryPathEdit->text()==workspacePathEdit->text()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Repository and Workspace paths cannot be equal."),
                                          QMessageBox::Ok);

        //    } if (userAuthenticationBox->isChecked() && (userNameEdit->text().isEmpty() || userPasswordEdit->text().isEmpty())) {
        //        QMessageBox msgBox;
        //        msgBox.setText("User name and password cannot be empty.");
        //        msgBox.exec();
    } else {
        //Apply configurations
        emit setWorkspacePath(workspacePathEdit->text());
        emit setRepositoryPath(repositoryPathEdit->text());
        //        emit setUserName(userNameEdit->text());
        //        emit setUserPassword(userPasswordEdit->text());
        this->close();
    }
}
