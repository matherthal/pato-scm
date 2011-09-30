#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkoutdialog.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Creation of the "Checkout Settings" Dialog
    CheckoutDialog *checkoutDialog = new CheckoutDialog;
    connect(checkoutDialog, SIGNAL(setWorkspacePath(QString)), this, SLOT(setWorkspacePath(QString)));

    //Menu components and actions
    QMenu *patoMenu = new QMenu(0);
    patoMenu = menuBar()->addMenu(tr("&Pato-SCM"));

    QAction *checkoutSettingsAct = new QAction("Checkout Settings", this);
    connect(checkoutSettingsAct, SIGNAL(triggered()), checkoutDialog, SLOT(show()));
    patoMenu->addAction(checkoutSettingsAct);

    //Help menu --unfinished
    //    QMenu *helpMenu = new QMenu(0);
    //    helpMenu = menuBar()->addMenu(tr("&Help"));
    //    QAction *contentsAct = new QAction("Contents", this);
    //    connect(contentsAct, SIGNAL(triggered()), this, SLOT(close()));
    //    helpMenu->addAction(contentsAct);
    //    QAction *aboutPatoAct = new QAction("About Pato-SCM", this);
    //    connect(aboutPatoAct, SIGNAL(triggered()), this, SLOT(close()));
    //    helpMenu->addAction(aboutPatoAct);

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
    QTreeView *workspaceTree = new QTreeView();
    workspaceTree->setModel(workspaceModel);
    workspaceTree->setRootIndex(workspaceModel->index(str));

    statusBar()->showMessage(tr("Workspace View"));
    setCentralWidget(workspaceTree);
}
