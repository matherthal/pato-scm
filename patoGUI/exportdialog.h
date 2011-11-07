#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>

namespace Ui {
    class ExportDialog;
}

class ExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDialog(QWidget *parent = 0);
    ~ExportDialog();

private:
    Ui::ExportDialog *ui;
signals:
    void showEnvironmentSettings();
public slots:
    void setRepositoryPath(const QString &str);
    void changeRepository();
    void confirmExport();
    void enableRevisionNumber();
    void disableRevisionNumber();
};
#endif // EXPORTDIALOG_H
