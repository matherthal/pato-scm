#ifndef BROWSEREPDIALOG_H
#define BROWSEREPDIALOG_H

#include <QDialog>

namespace Ui {
class BrowseRepDialog;
}

class BrowseRepDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseRepDialog(QWidget *parent = 0);
    ~BrowseRepDialog();

public slots:
    void setTitle(const QString &str);
    void setRepositoryPath(const QString &str);
private:
    Ui::BrowseRepDialog *ui;
};

#endif // BROWSEREPDIALOG_H
