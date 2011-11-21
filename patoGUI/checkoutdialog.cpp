#include <QtGui>
#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"

CheckoutDialog::CheckoutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckoutDialog)
{
    //Start Configurations
    ui->setupUi(this);
    ui->radioButtonHEAD->setChecked(true);
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);

    //Actions
    connect(ui->buttonChangeRepository, SIGNAL(clicked()), this, SLOT(changeRepository()));
    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonCheckout, SIGNAL(clicked()), this, SLOT(checkout()));

    connect(ui->radioButtonOther, SIGNAL(clicked()), this, SLOT(enableRevisionNumber()));
    connect(ui->radioButtonHEAD, SIGNAL(clicked()), this, SLOT(disableRevisionNumber()));


    //Window properties
    setFixedSize(500,250);
    setWindowTitle("Check-out");
}

CheckoutDialog::~CheckoutDialog()
{
    delete ui;
}
void CheckoutDialog::setRepositoryPath(const QString &str)
{
    ui->labelRepositoryPath->setText(str);
}
void CheckoutDialog::changeRepository()
{
    emit showEnvironmentSettings();
}
void CheckoutDialog::enableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setFocus();
}
void CheckoutDialog::disableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);
}
void CheckoutDialog::checkout()
{
    if (ui->radioButtonOther->isChecked() && ui->lineEditRevisionNumber->text().isEmpty()) {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("You must inform a revision number or select HEAD."),
                                          QMessageBox::Ok);
        ui->lineEditRevisionNumber->setFocus();
    }
    else if (ui->radioButtonOther->isChecked() && ui->lineEditRevisionNumber->text()=="0") {
        int msgBox = QMessageBox::warning(this, tr("Error"),
                                          tr("Invalid revision number!"),
                                          QMessageBox::Ok);
        ui->lineEditRevisionNumber->setFocus();
    } else {
        //Checkout
        //emit setRevisionNumber(ui->lineEditRevisionNumber->text());
        //emit checkout();
    }

}
