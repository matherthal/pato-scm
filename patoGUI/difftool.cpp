#include "difftool.h"
#include "ui_difftool.h"
#include "diff.h"
#include "diffitem.h"
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

    connect(ui->actionOneAgainstTwo, SIGNAL(triggered()), this, SLOT(showDiffAB()));
    connect(ui->actionTwoAgainstOne, SIGNAL(triggered()), this, SLOT(showDiffBA()));



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
        QFile file2(fileName2);
        if (!file2.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file2);
        //Creating Table
        ui->fileTwoTableWidget->setColumnCount(2);
        ui->fileTwoTableWidget->setColumnWidth(0,15);
        ui->fileTwoTableWidget->setColumnWidth(1,285);
        ui->fileTwoTableWidget->setShowGrid(false);


        //Populating Table
        int row = 0;
        while (!in.atEnd()) {
            ui->fileTwoTableWidget->setRowCount(row+1);
            QTableWidgetItem *newItem = new QTableWidgetItem(in.readLine());
            ui->fileTwoTableWidget->setItem(row, 1, newItem);
            row++;
        }
        file2.close();

    }
}
void DiffTool::showDiffAB()
{
    Diff *diff = new Diff(ui->fileOneLabel->text().toLatin1(),ui->fileTwoLabel->text().toLatin1());
    QTableWidgetItem *itemCleanA = new QTableWidgetItem("");
    QTableWidgetItem *itemCleanB = new QTableWidgetItem("");
    int rowA = 0;
    while (rowA<=ui->fileOneTableWidget->rowCount()) {
        ui->fileOneTableWidget->setItem(rowA, 0, itemCleanA);
        rowA++;
    }
    int rowB = 0;
    while (rowB<=ui->fileTwoTableWidget->rowCount()) {
        ui->fileTwoTableWidget->setItem(rowB, 0, itemCleanB);
        rowB++;
    }
    int i = 0;
    int iniA;
    int endA;
    int iniB;
    int endB;
    QString itemType;
    if (diff->isEmpty() == false) {
        while (diff->getDiffItem(i)!= NULL) {
            itemType = diff->getDiffItem(i)->to_string().at(1);
            if (itemType == "d") {
                QTableWidgetItem *newItemSignalD = new QTableWidgetItem("x");
                //newItemSignalD->setTextColor(QColor (255, 0, 0, 127));
                newItemSignalD->setBackgroundColor(QColor (255, 0, 0, 127));
                newItemSignalD->setFont(QFont ("Arial", 12, QFont::Black));
                iniA = diff->getDiffItem(i)->getFromA();
                endA = diff->getDiffItem(i)->getToA();
                while (iniA<=endA) {
                    ui->fileOneTableWidget->setItem(iniA, 0, newItemSignalD);
                    iniA++;
                }
            }
            if (itemType == "c") {
                QTableWidgetItem *newItemSignalCA = new QTableWidgetItem("!");
                //newItemSignalCA->setTextColor(QColor (255, 215, 0, 127));
                newItemSignalCA->setBackgroundColor(QColor (255, 215, 0, 127));
                newItemSignalCA->setFont(QFont ("Times", 16, QFont::Black));
                iniA = diff->getDiffItem(i)->getFromA();
                endA = diff->getDiffItem(i)->getToA();
                while (iniA<=endA) {
                    ui->fileOneTableWidget->setItem(iniA, 0, newItemSignalCA);
                    iniA++;
                }
                QTableWidgetItem *newItemSignalCB = new QTableWidgetItem("!");
                //newItemSignalCB->setTextColor(QColor (255, 215, 0, 127));
                newItemSignalCB->setFont(QFont ("Times", 16, QFont::Black));
                newItemSignalCB->setBackgroundColor(QColor (255, 215, 0, 127));
                iniB = diff->getDiffItem(i)->getFromB();
                endB = diff->getDiffItem(i)->getToB();
                while (iniB<=endB) {
                    ui->fileTwoTableWidget->setItem(iniB, 0, newItemSignalCB);
                    iniB++;
                }
            }
            if (itemType == "a") {
                QTableWidgetItem *newItemSignalA = new QTableWidgetItem("+");
                //newItemSignalA->setTextColor(QColor (0, 255, 0, 127));
                newItemSignalA->setBackgroundColor(QColor (0, 255, 0, 127));
                newItemSignalA->setFont(QFont ("Arial", 15, QFont::Black));
                iniB = diff->getDiffItem(i)->getFromB();
                endB = diff->getDiffItem(i)->getToB();
                while (iniB<=endB) {
                    ui->fileTwoTableWidget->setItem(iniB, 0, newItemSignalA);
                    iniB++;
                }
            }
            i++;
        }


    }
}
void DiffTool::showDiffBA()
{
    Diff *diff = new Diff(ui->fileTwoLabel->text().toLatin1(),ui->fileOneLabel->text().toLatin1());
    QTableWidgetItem *itemCleanA = new QTableWidgetItem("");
    QTableWidgetItem *itemCleanB = new QTableWidgetItem("");
    int rowA = 0;
    while (rowA<=ui->fileOneTableWidget->rowCount()) {
        ui->fileOneTableWidget->setItem(rowA, 0, itemCleanA);
        rowA++;
    }
    int rowB = 0;
    while (rowB<=ui->fileTwoTableWidget->rowCount()) {
        ui->fileTwoTableWidget->setItem(rowB, 0, itemCleanB);
        rowB++;
    }
    int i = 0;
    int iniA;
    int endA;
    int iniB;
    int endB;
    QString itemType;
    if (diff->isEmpty() == false) {
        while (diff->getDiffItem(i)!= NULL) {
            itemType = diff->getDiffItem(i)->to_string().at(1);
            if (itemType == "d") {
                QTableWidgetItem *newItemSignalD = new QTableWidgetItem("x");
                //newItemSignalD->setTextColor(QColor (255, 0, 0, 127));
                newItemSignalD->setBackgroundColor(QColor (255, 0, 0, 127));
                newItemSignalD->setFont(QFont ("Arial", 12, QFont::Black));
                iniA = diff->getDiffItem(i)->getFromA();
                endA = diff->getDiffItem(i)->getToA();
                while (iniA<=endA) {
                    ui->fileTwoTableWidget->setItem(iniA, 0, newItemSignalD);
                    iniA++;
                }
            }
            if (itemType == "c") {
                QTableWidgetItem *newItemSignalCA = new QTableWidgetItem("!");
                //newItemSignalCA->setTextColor(QColor (255, 215, 0, 127));
                newItemSignalCA->setBackgroundColor(QColor (255, 215, 0, 127));
                newItemSignalCA->setFont(QFont ("Times", 16, QFont::Black));
                iniA = diff->getDiffItem(i)->getFromA();
                endA = diff->getDiffItem(i)->getToA();
                while (iniA<=endA) {
                    ui->fileTwoTableWidget->setItem(iniA, 0, newItemSignalCA);
                    iniA++;
                }
                QTableWidgetItem *newItemSignalCB = new QTableWidgetItem("!");
                //newItemSignalCB->setTextColor(QColor (255, 215, 0, 127));
                newItemSignalCB->setFont(QFont ("Times", 16, QFont::Black));
                newItemSignalCB->setBackgroundColor(QColor (255, 215, 0, 127));
                iniB = diff->getDiffItem(i)->getFromB();
                endB = diff->getDiffItem(i)->getToB();
                while (iniB<=endB) {
                    ui->fileOneTableWidget->setItem(iniB, 0, newItemSignalCB);
                    iniB++;
                }
            }
            if (itemType == "a") {
                QTableWidgetItem *newItemSignalA = new QTableWidgetItem("+");
                //newItemSignalA->setTextColor(QColor (0, 255, 0, 127));
                newItemSignalA->setBackgroundColor(QColor (0, 255, 0, 127));
                newItemSignalA->setFont(QFont ("Arial", 15, QFont::Black));
                iniB = diff->getDiffItem(i)->getFromB();
                endB = diff->getDiffItem(i)->getToB();
                while (iniB<=endB) {
                    ui->fileOneTableWidget->setItem(iniB, 0, newItemSignalA);
                    iniB++;
                }
            }
            i++;
        }


    }
}
