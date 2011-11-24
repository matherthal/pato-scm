#ifndef CHECKINDIALOG_H
#define CHECKINDIALOG_H

#include <QDialog>

namespace Ui {
class CheckinDialog;
}

class CheckinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckinDialog(QWidget *parent = 0);
    ~CheckinDialog();
signals:
    void showEnvironmentSettings();
private:
    Ui::CheckinDialog *ui;
public slots:
    void setTitle(const QString &str);
    void setRepositoryPath(const QString &str);
    void changeRepository();
    void checkin();
};

#endif // CHECKINDIALOG_H
