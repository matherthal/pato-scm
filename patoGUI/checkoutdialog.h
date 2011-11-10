#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>

namespace Ui {
class CheckoutDialog;
}

class CheckoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckoutDialog(QWidget *parent = 0);
    ~CheckoutDialog();
signals:
    void showEnvironmentSettings();
private:
    Ui::CheckoutDialog *ui;
public slots:
    void setTitle(const QString &str);
    void setRepositoryPath(const QString &str);
    void changeRepository();
    void checkout();
    void enableRevisionNumber();
    void disableRevisionNumber();
};
#endif // CHECKOUTDIALOG_H
