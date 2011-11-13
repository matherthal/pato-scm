#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(close()));

    setFixedSize(368,161);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
