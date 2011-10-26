#ifndef ENVIRONMENTSETTINGSDIALOG_H
#define ENVIRONMENTSETTINGSDIALOG_H
#include <QDialog>

namespace Ui {
class EnvironmentSettingsDialog;
}

class EnvironmentSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnvironmentSettingsDialog(QWidget *parent = 0);
    ~EnvironmentSettingsDialog();

private:
    Ui::EnvironmentSettingsDialog *ui;

signals:
    void setWorkspacePath(const QString &str);
    void setRepositoryPath(const QString &str);
    void setUserName(const QString &str);
    void setUserPassword(const QString &str);
private slots:
    void getRepositoryPath();
    void getWorkspacePath();
    void apply();
};
#endif // ENVIRONMENTSETTINGSDIALOG_H
