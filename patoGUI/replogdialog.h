#ifndef REPLOGDIALOG_H
#define REPLOGDIALOG_H

#include <QDialog>

namespace Ui {
    class RepLogDialog;
}

class RepLogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RepLogDialog(QWidget *parent = 0);
    ~RepLogDialog();

private slots:
    void populatingLogExample();
    void showMessage();
    void showChanges();
private:
    Ui::RepLogDialog *ui;
};

#endif // RepLogDialog_H
