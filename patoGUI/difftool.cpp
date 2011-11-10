#include "difftool.h"
#include "ui_difftool.h"
#include <QtGui>

DiffTool::DiffTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DiffTool)
{
    ui->setupUi(this);
    ui->fileOneLabel->setVisible(false);
    ui->fileTwoLabel->setVisible(false);

    //Actions
    connect(ui->actionLoad_File_1, SIGNAL(triggered()), this, SLOT(loadFileOne()));
    connect(ui->actionLoad_File_2, SIGNAL(triggered()), this, SLOT(loadFileTwo()));

    connect(ui->actionOneAgainstTwo, SIGNAL(triggered()), this, SLOT(showDiff()));
    connect(ui->actionTwoAgainstOne, SIGNAL(triggered()), this, SLOT(showDiff()));

    //Window properties
    setWindowTitle(tr("Pato-Diff Tool"));
    setFixedSize(800,600);

}

DiffTool::~DiffTool()
{
    delete ui;
}
void DiffTool::loadFileOne()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        ui->fileOneLabel->setText(fileName);
        ui->fileOneLabel->setVisible(true);

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        //Creating Table
        ui->fileOneTableWidget->setColumnCount(2);
        ui->fileOneTableWidget->setColumnWidth(0,15);
        ui->fileOneTableWidget->setColumnWidth(1,285);
        ui->fileOneTableWidget->setShowGrid(false);


        //Populating Table
        int row = 0;
        while (!in.atEnd()) {
            ui->fileOneTableWidget->setRowCount(row+1);
            QTableWidgetItem *newItemSignal = new QTableWidgetItem("+");
            newItemSignal->setTextColor(QColor (255, 0, 0, 127));
            newItemSignal->setFont(QFont ("Times", 16, QFont::Black));
            ui->fileOneTableWidget->setItem(row, 0, newItemSignal);
            QTableWidgetItem *newItem = new QTableWidgetItem(in.readLine());
            ui->fileOneTableWidget->setItem(row, 1, newItem);
            row++;
        }
        file.close();
    }
}
void DiffTool::loadFileTwo()
{
    QString fileName2 = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                     tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName2 != "") {
        ui->fileTwoLabel->setText(fileName2);
        ui->fileTwoLabel->setVisible(true);
        QFile file(fileName2);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        //Creating Table
        ui->fileTwoTableWidget->setColumnCount(2);
        ui->fileTwoTableWidget->setColumnWidth(0,15);
        ui->fileTwoTableWidget->setColumnWidth(1,285);
        ui->fileTwoTableWidget->setShowGrid(false);


        //Populating Table
        int row = 0;
        while (!in.atEnd()) {
            ui->fileTwoTableWidget->setRowCount(row+1);
            QTableWidgetItem *newItemSignal = new QTableWidgetItem("+");
            newItemSignal->setTextColor(QColor (255, 0, 0, 127));
            newItemSignal->setFont(QFont ("Times", 16, QFont::Black));
            ui->fileTwoTableWidget->setItem(row, 0, newItemSignal);
            QTableWidgetItem *newItem = new QTableWidgetItem(in.readLine());
            ui->fileTwoTableWidget->setItem(row, 1, newItem);
            row++;
        }
        file.close();
    }
}
void DiffTool::showDiff()
{
    //vazio
}
