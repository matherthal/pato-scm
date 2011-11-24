#include "checkindialog.h"
#include "ui_checkindialog.h"

CheckinDialog::CheckinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckinDialog)
{
    ui->setupUi(this);

    //Actions
    connect(ui->buttonChangeRepository, SIGNAL(clicked()), this, SLOT(changeRepository()));
    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->buttonCheckin, SIGNAL(clicked()), this, SLOT(checkin()));

    //Window properties
    setFixedSize(500,270);
}

CheckinDialog::~CheckinDialog()
{
    delete ui;
}
void CheckinDialog::setTitle(const QString &str)
{
    setWindowTitle("Check-in - "+str);
}
void CheckinDialog::setRepositoryPath(const QString &str)
{
    ui->labelRepositoryPath->setText(str);
}
void CheckinDialog::changeRepository()
{
    emit showEnvironmentSettings();
}
void CheckinDialog::checkin()
{
    //Checkin
}
