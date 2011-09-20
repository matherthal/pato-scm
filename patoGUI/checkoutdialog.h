#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class CheckoutDialog : public QDialog
{
    Q_OBJECT
public:
    CheckoutDialog(QWidget *parent = 0);
signals:
    void setWorkspacePath(const QString &str);
private slots:
    void getRepositoryPath();
    void getWorkspacePath();
    void getAuthentication();
    void checkout();
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
    QPushButton *checkoutButton;
    QPushButton *chooseRepositoryButton;
    QPushButton *chooseWorkspaceButton;
};
#endif

