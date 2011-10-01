#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environmentsettingsdialog.h"
#include "checkindialog.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeViewWorkspace->setVisible(false);
    ui->labelWorkspace->setVisible(false);
    ui->labelWorkspacePath->setVisible(false);

    //Creation of the Pato-SCM Dialogs
    EnvironmentSettingsDialog *environmentSettingsDialog = new EnvironmentSettingsDialog;
    CheckinDialog *checkinDialog = new CheckinDialog;


    //Actions
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(setWorkspaceModel(QString)));
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(enableActions()));
    connect(ui->actionCheckout, SIGNAL(triggered()), this, SLOT(checkout()));

    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), checkinDialog, SLOT(setTitle(QString)));
    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), checkinDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionCheckin, SIGNAL(triggered()), checkinDialog, SLOT(show()));

    connect(checkinDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(ui->actionEnvironment_Settings, SIGNAL(triggered()), environmentSettingsDialog, SLOT(show()));

    //Window properties
    setWindowTitle(tr("Pato-SCM"));
    setFixedSize(800,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setWorkspaceModel(const QString &str)
{
    //Creation of the model view of the workspace
    QFileSystemModel *workspaceModel = new QFileSystemModel;
    workspaceModel->setRootPath(str);

    ui->treeViewWorkspace->setModel(workspaceModel);
    ui->treeViewWorkspace->setRootIndex(workspaceModel->index(str));
    ui->treeViewWorkspace->setVisible(true);

    ui->labelWorkspace->setVisible(true);

    ui->labelWorkspacePath->setText(str);
    ui->labelWorkspacePath->setVisible(true);
}
void MainWindow::enableActions()
{
    ui->actionCheckin->setEnabled(true);
    ui->actionCheckout->setEnabled(true);
}
void MainWindow::checkout()
{
    //Checkout
}
