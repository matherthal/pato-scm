#ifndef ENVIRONMENTSETTINGSDIALOG_H
#define ENVIRONMENTSETTINGSDIALOG_H
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class EnvironmentSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    EnvironmentSettingsDialog(QWidget *parent = 0);
signals:
    void setWorkspacePath(const QString &str);
    void setRepositoryPath(const QString &str);
    void setUserName(const QString &str);
    void setUserPassword(const QString &str);
private slots:
    void getRepositoryPath();
    void getWorkspacePath();
    void getAuthentication();
    void apply();
private:
    QLabel *repositoryPathLabel;
    QLabel *workspacePathLabel;
    QLabel *userPasswordLabel;
    QLabel *userNameLabel;

    QLineEdit *repositoryPathEdit;
    QLineEdit *workspacePathEdit;
    QLineEdit *userPasswordEdit;
    QLineEdit *userNameEdit;

    QCheckBox *userAuthenticationBox;

    QPushButton *cancelButton;
    QPushButton *applyButton;
    QPushButton *chooseRepositoryButton;
    QPushButton *chooseWorkspaceButton;
};
#endif
