#include "replogdialog.h".h"
#include "ui_replogdialog.h"

RepLogDialog::RepLogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RepLogDialog)
{
    //Window properties
    setFixedSize(800,440);

    //Start Configurations
    ui->setupUi(this);
    this->populatingLogExample();

    //Actions
    connect(ui->buttonOK, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->logTable, SIGNAL(clicked(QModelIndex)), this, SLOT(showMessage()));
    connect(ui->logTable, SIGNAL(clicked(QModelIndex)), this, SLOT(showChanges()));

}

RepLogDialog::~RepLogDialog()
{
    delete ui;
}
void RepLogDialog::populatingLogExample()
{
    ui->logTable->setRowCount(5);
    ui->logTable->setColumnWidth(0,80);
    QTableWidgetItem *rev1 = new QTableWidgetItem("5");
    QTableWidgetItem *rev2 = new QTableWidgetItem("4");
    QTableWidgetItem *rev3 = new QTableWidgetItem("3");
    QTableWidgetItem *rev4 = new QTableWidgetItem("2");
    QTableWidgetItem *rev5 = new QTableWidgetItem("1");
    rev1->setTextAlignment(Qt::AlignCenter);
    rev2->setTextAlignment(Qt::AlignCenter);
    rev3->setTextAlignment(Qt::AlignCenter);
    rev4->setTextAlignment(Qt::AlignCenter);
    rev5->setTextAlignment(Qt::AlignCenter);
    ui->logTable->setItem(0, 0, rev1);
    ui->logTable->setItem(1, 0, rev2);
    ui->logTable->setItem(2, 0, rev3);
    ui->logTable->setItem(3, 0, rev4);
    ui->logTable->setItem(4, 0, rev5);
    ui->logTable->setColumnWidth(1,130);
    QTableWidgetItem *d1 = new QTableWidgetItem("16/11/2011, 09:00:00");
    QTableWidgetItem *d2 = new QTableWidgetItem("15/11/2011, 08:26:01");
    QTableWidgetItem *d3 = new QTableWidgetItem("14/11/2011, 20:12:20");
    QTableWidgetItem *d4 = new QTableWidgetItem("13/11/2011, 17:45:03");
    QTableWidgetItem *d5 = new QTableWidgetItem("12/11/2011, 03:30:47");
    d1->setTextAlignment(Qt::AlignCenter);
    d2->setTextAlignment(Qt::AlignCenter);
    d3->setTextAlignment(Qt::AlignCenter);
    d4->setTextAlignment(Qt::AlignCenter);
    d5->setTextAlignment(Qt::AlignCenter);
    ui->logTable->setItem(0, 1, d1);
    ui->logTable->setItem(1, 1, d2);
    ui->logTable->setItem(2, 1, d3);
    ui->logTable->setItem(3, 1, d4);
    ui->logTable->setItem(4, 1, d5);
    ui->logTable->setColumnWidth(2,80);
    QTableWidgetItem *a1 = new QTableWidgetItem("Karen");
    QTableWidgetItem *a2 = new QTableWidgetItem("UserXPTO");
    QTableWidgetItem *a3 = new QTableWidgetItem("Karen");
    QTableWidgetItem *a4 = new QTableWidgetItem("Karen");
    QTableWidgetItem *a5 = new QTableWidgetItem("UserXPTO");
    ui->logTable->setItem(0, 2, a1);
    ui->logTable->setItem(1, 2, a2);
    ui->logTable->setItem(2, 2, a3);
    ui->logTable->setItem(3, 2, a4);
    ui->logTable->setItem(4, 2, a5);
    ui->logTable->setColumnWidth(3,488);
    QTableWidgetItem *m1 = new QTableWidgetItem("Tale detraxit adversarium ius, sit.");
    QTableWidgetItem *m2 = new QTableWidgetItem("Lorem ipsum dolor sit amet, an eum alia molestiae. Eos quem sanctus sapientem an. No sit stet accommodare, duo in mutat torquatos inciderint. Eu nemore inermis eum. Dicat repudiandae sit ne, qui ex augue elaboraret.");
    QTableWidgetItem *m3 = new QTableWidgetItem("Dicta fuisset ex his.");
    QTableWidgetItem *m4 = new QTableWidgetItem("Pro minim veritus.");
    QTableWidgetItem *m5 = new QTableWidgetItem("Essent forensibus ea eos, et dolor eruditi insolens ius. Inani affert mea in, ea quis soluta vim. Vocent voluptatibus at pro. Ei fabulas inciderint per. Eos cu malorum percipitur, in ius dolore postea omittam, ullum utinam in vel. Possim malorum mandamus vix ea, veri pertinacia ad vix.");
    ui->logTable->setItem(0, 3, m1);
    ui->logTable->setItem(1, 3, m2);
    ui->logTable->setItem(2, 3, m3);
    ui->logTable->setItem(3, 3, m4);
    ui->logTable->setItem(4, 3, m5);

}
void RepLogDialog::showMessage()
{
    QTableWidgetItem *item = ui->logTable->currentItem();
    if (item->column() == 3) {
        ui->messageTextEdit->setText(item->text());
    }
    else {
        int row = item->row();
        ui->messageTextEdit->setText(ui->logTable->item(row, 3)->text());
    }
}
void RepLogDialog::showChanges()
{
    QTableWidgetItem *item = ui->logTable->currentItem();
    int row = item->row();
    QString changes;
    switch (row){
    case 4: changes = "+  file1.cpp \n+  file1.h";
        break;
    case 3: changes = "!  file1.cpp \n!  file1.h";
        break;
    case 2: changes = "!  file1.cpp \n!  file1.h \n+ file2.cpp \n+ file2.h";
        break;
    case 1: changes = "-  file1.cpp \n-  file1.h \n! file2.cpp \n! file2.h";
        break;
    case 0: changes = "!  file2.cpp";
        break;
    }
    ui->filesTextEdit->setText(changes);
}
