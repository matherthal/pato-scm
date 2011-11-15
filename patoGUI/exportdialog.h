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
    void setWorkspacePath(const QString &str);
    void changePath();
    void confirmExport();
    void enableRevisionNumber();
    void disableRevisionNumber();
    void getExportPath();
    void enableWorkspaceOptions();
    void enableRepositoryOptions();
};
#endif // EXPORTDIALOG_H
