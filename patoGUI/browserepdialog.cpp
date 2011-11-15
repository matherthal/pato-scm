#include "browserepdialog.h"
#include "ui_browserepdialog.h"
#include <QDesktopServices>
#include <QtGui>

BrowseRepDialog::BrowseRepDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseRepDialog)
{
    //Start Configurations
    ui->setupUi(this);

    //Window properties
    setFixedSize(800,400);

    //Actions
    connect(ui->OKButton, SIGNAL(clicked()), this, SLOT(close()));

}

BrowseRepDialog::~BrowseRepDialog()
{
    delete ui;
}
void BrowseRepDialog::setTitle(const QString &str)
{
    setWindowTitle("Browse - "+str);
}
void BrowseRepDialog::setRepositoryPath(const QString &str)
{
    ui->repLabel->setText(str);
    QFileSystemModel *repositoryModel = new QFileSystemModel;
    repositoryModel->setRootPath(str);
    ui->repTreeView->setModel(repositoryModel);
    ui->repTreeView->setRootIndex(repositoryModel->index(str));
}

