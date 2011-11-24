#include "difffiledialog.h"
#include "ui_difffiledialog.h"

DiffFileDialog::DiffFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiffFileDialog)
{
    //Window properties
    setFixedSize(600,520);

    //Start Configurations
    ui->setupUi(this);

    //Actions
    connect(ui->OKButton, SIGNAL(clicked()), this, SLOT(close()));
}

DiffFileDialog::~DiffFileDialog()
{
    delete ui;
}
void DiffFileDialog::setDiffFile(const QString &str)
{
    ui->fileTextEdit->setText(str);
}
void DiffFileDialog::setDiffFile1(const QString &str)
{
    ui->fileOne->setText(str);
}
void DiffFileDialog::setDiffFile2(const QString &str)
{
    ui->fileTwo->setText(str);
}

