#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkoutdialog.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeViewWorkspace->setVisible(false);
    ui->labelWorkspace->setVisible(false);
    ui->labelWorkspacePath->setVisible(false);

    //Creation of the "Checkout Settings" Dialog
    CheckoutDialog *checkoutDialog = new CheckoutDialog;

    //Actions
    connect(checkoutDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(setWorkspacePath(QString)));

    connect(ui->actionCheckout_Settings, SIGNAL(triggered()), checkoutDialog, SLOT(show()));

    //Window properties
    setWindowTitle(tr("Pato-SCM"));
    setWindowIcon(QIcon(":/images/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setWorkspacePath(const QString &str)
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
