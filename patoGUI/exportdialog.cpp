#include <QtGui>
#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    //Actions
    connect(ui->buttonChangeRepository, SIGNAL(clicked()), this, SLOT(changeRepository()));
    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonExport, SIGNAL(clicked()), this, SLOT(confirmExport()));

    connect(ui->radioButtonOther, SIGNAL(clicked()), this, SLOT(enableRevisionNumber()));
    connect(ui->radioButtonHEAD, SIGNAL(clicked()), this, SLOT(disableRevisionNumber()));

    //Start Configurations
    ui->radioButtonHEAD->setChecked(true);
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);

    //Window properties
    setFixedSize(500,310);
    setWindowTitle("Export");
}

ExportDialog::~ExportDialog()
{
    delete ui;
}
void ExportDialog::setRepositoryPath(const QString &str)
{
    ui->labelRepositoryPath->setText(str);
}
void ExportDialog::changeRepository()
{
    emit showEnvironmentSettings();
}
void ExportDialog::enableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setEnabled(true);
    ui->lineEditRevisionNumber->setFocus();
}
void ExportDialog::disableRevisionNumber()
{
    ui->labelRevisionNumber->setEnabled(false);
    ui->lineEditRevisionNumber->setEnabled(false);
}
void ExportDialog::confirmExport()
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
        //Export
    }

}
