#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QDialog>

namespace Ui {
    class LogDialog;
}

class LogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogDialog(QWidget *parent = 0);
    ~LogDialog();

private slots:
    void populatingLogExample();
    void showMessage();
    void showChanges();
private:
    Ui::LogDialog *ui;
};

#endif // LOGDIALOG_H
