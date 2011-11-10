#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environmentsettingsdialog.h"
#include "checkindialog.h"
#include "checkoutdialog.h"
#include "exportdialog.h"
#include "difftool.h"
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
    CheckoutDialog *checkoutDialog = new CheckoutDialog;
    ExportDialog *exportDialog = new ExportDialog;
    DiffTool *diffToolWindow = new DiffTool;


    //Actions
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(setWorkspaceModel(QString)));
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(enableActions()));

    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), checkoutDialog, SLOT(setTitle(QString)));
    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), checkoutDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionCheckout, SIGNAL(triggered()), checkoutDialog, SLOT(show()));

    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), checkinDialog, SLOT(setTitle(QString)));
    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), checkinDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionCheckin, SIGNAL(triggered()), checkinDialog, SLOT(show()));

    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), exportDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionExport, SIGNAL(triggered()), exportDialog, SLOT(show()));

    connect(checkinDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(checkoutDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(ui->actionEnvironment_Settings, SIGNAL(triggered()), environmentSettingsDialog, SLOT(show()));

    connect(ui->actionOpen, SIGNAL(triggered()), diffToolWindow, SLOT(show()));

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
    ui->menuWorkspace->setEnabled(true);
    ui->actionAdd_File_Dir->setEnabled(true);
    ui->actionRemove_File_Dir->setEnabled(true);
    ui->actionUpdate->setEnabled(true);

}
