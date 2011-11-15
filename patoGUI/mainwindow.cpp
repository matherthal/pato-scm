#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environmentsettingsdialog.h"
#include "checkindialog.h"
#include "checkoutdialog.h"
#include "exportdialog.h"
#include "aboutdialog.h"
#include "logdialog.h"
#include "replogdialog.h"
#include "browserepdialog.h"
#include "difftool.h"
#include "difffiledialog.h"
//#include "../patoClientAPI/patoclientapi.h"
#include <QtGui>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Start Configurations
    ui->setupUi(this);
    ui->treeViewWorkspace->setVisible(false);
    ui->labelWorkspace->setVisible(false);
    ui->labelWorkspacePath->setVisible(false);

    //Client API
    //PatoClientApi *clientAPI = new PatoClientApi;

    //Creation of the Pato-SCM Dialogs
    EnvironmentSettingsDialog *environmentSettingsDialog = new EnvironmentSettingsDialog;
    CheckinDialog *checkinDialog = new CheckinDialog;
    CheckoutDialog *checkoutDialog = new CheckoutDialog;
    ExportDialog *exportDialog = new ExportDialog;
    DiffTool *diffToolWindow = new DiffTool;
    DiffFileDialog *diffFileDialog = new DiffFileDialog;
    AboutDialog *aboutDialog = new AboutDialog;
    LogDialog *logDialog = new LogDialog;
    RepLogDialog *repLogDialog = new RepLogDialog;
    BrowseRepDialog *browseDialog = new BrowseRepDialog;


    //Actions
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(setWorkspaceModel(QString)));
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(enableActions()));

    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), checkoutDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionCheckout, SIGNAL(triggered()), checkoutDialog, SLOT(show()));
    //connect(ui->actionCheckout, SIGNAL(checkout()), this, SLOT(executeCheckout()));

    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), checkinDialog, SLOT(setTitle(QString)));
    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), checkinDialog, SLOT(setRepositoryPath(QString)));
    connect(ui->actionCheckin, SIGNAL(triggered()), checkinDialog, SLOT(show()));

    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), exportDialog, SLOT(setRepositoryPath(QString)));
    connect(environmentSettingsDialog, SIGNAL(setWorkspacePath(QString)), exportDialog, SLOT(setWorkspacePath(QString)));
    connect(ui->actionExport, SIGNAL(triggered()), exportDialog, SLOT(show()));

    //connect(ui->actionLog, SIGNAL(triggered()), logDialog, SLOT(log()));
    connect(ui->actionLog, SIGNAL(triggered()), logDialog, SLOT(show()));
    connect(ui->actionRepLog, SIGNAL(triggered()), repLogDialog, SLOT(show()));

    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), browseDialog, SLOT(setRepositoryPath(QString)));
    connect(environmentSettingsDialog, SIGNAL(setRepositoryPath(QString)), browseDialog, SLOT(setTitle(QString)));
    connect(ui->actionBrowse, SIGNAL(triggered()), browseDialog, SLOT(show()));

    connect(checkinDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(checkoutDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(exportDialog, SIGNAL(showEnvironmentSettings()), environmentSettingsDialog, SLOT(show()));
    connect(ui->actionEnvironment_Settings, SIGNAL(triggered()), environmentSettingsDialog, SLOT(show()));

    connect(ui->actionOpen, SIGNAL(triggered()), diffToolWindow, SLOT(show()));
    connect(diffToolWindow, SIGNAL(stringDiffFile(QString)), diffFileDialog, SLOT(show()));
    connect(diffToolWindow, SIGNAL(stringDiffFile(QString)), diffFileDialog, SLOT(setDiffFile(QString)));
    connect(diffToolWindow, SIGNAL(stringFile1(QString)), diffFileDialog, SLOT(setDiffFile1(QString)));
    connect(diffToolWindow, SIGNAL(stringFile2(QString)), diffFileDialog, SLOT(setDiffFile2(QString)));

    //connect(ui->actionAdd_File_Dir, SIGNAL(triggered()), this, SLOT(addFile()));
    //connect(ui->actionUpdate, SIGNAL(triggered()), this, SLOT(update()));


    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
    connect(ui->actionAbout_Pato_SCM, SIGNAL(triggered()), aboutDialog, SLOT(show()));

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

    //Workspace in Tree View
    ui->treeViewWorkspace->setModel(workspaceModel);
    ui->treeViewWorkspace->setRootIndex(workspaceModel->index(str));
    ui->treeViewWorkspace->setVisible(true);

//    //Workspace in Table View
//    ui->tableView->setModel(workspaceModel);
//    ui->tableView->setRootIndex(workspaceModel->index(str));
//    ui->tableView->setVisible(true);
//    ui->tableView->setShowGrid(false);
//    ui->labelWorkspace->setVisible(true);
//    ui->labelWorkspacePath->setText(str);
//    ui->labelWorkspacePath->setVisible(true);
}
void MainWindow::enableActions()
{
    ui->actionCheckin->setEnabled(true);
    ui->actionCheckout->setEnabled(true);
    ui->menuWorkspace->setEnabled(true);
    ui->actionAdd_File_Dir->setEnabled(true);
    ui->actionRemove_File_Dir->setEnabled(true);
    ui->actionUpdate->setEnabled(true);
    ui->actionLog->setEnabled(true);
    ui->menuRepository->setEnabled(true);
    ui->actionRepLog->setEnabled(true);
    ui->actionBrowse->setEnabled(true);
    ui->actionExport->setEnabled(true);

}
void MainWindow::help()
{
    QDesktopServices::openUrl(QUrl("http://www.ic.uff.br/~kfigueiredo/patoSCM/help.html", QUrl::TolerantMode));
}
//void MainWindow::executeCheckout()
//{
//    try {
//        clientAPI->checkout(revision, address, username, password, workspace);
//    } catch (PatoClientException& t) {
//        int msgBox = QMessageBox::warning(this, tr("Error"),
//                                          tr("Something has gone wrong..."),
//                                          QMessageBox::Ok);

//    }
//}
//void MainWindow::addFile()
//{
//    QString *file = ui->treeViewWorkspace->currentIndex();
//    try {
//        clientAPI->add(workspace, file);
//    } catch (PatoClientException& t) {
//        int msgBox = QMessageBox::warning(this, tr("Error"),
//                                          tr("Something has gone wrong..."),
//                                          QMessageBox::Ok);

//    }
//}
//void MainWindow::update()
//{
//    try {
//        clientAPI->update(revision, address, username, password, workspace, true);//true = ignorelocalchanges
//    } catch (PatoClientException& t) {
//        int msgBox = QMessageBox::warning(this, tr("Error"),
//                                          tr("Something has gone wrong..."),
//                                          QMessageBox::Ok);

//    }
//}
//void MainWindow::log()
//{
//    try {
//        clientAPI->log(address, username, password, initialRevision, finalRevision);
//    } catch (PatoClientException& t) {
//        int msgBox = QMessageBox::warning(this, tr("Error"),
//                                          tr("Something has gone wrong..."),
//                                          QMessageBox::Ok);

//    }
//}
