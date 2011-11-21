#ifndef DIFFFILEDIALOG_H
#define DIFFFILEDIALOG_H

#include <QDialog>

namespace Ui {
    class DiffFileDialog;
}

class DiffFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiffFileDialog(QWidget *parent = 0);
    ~DiffFileDialog();
public slots:
    void setDiffFile(const QString &str);
    void setDiffFile1(const QString &str);
    void setDiffFile2(const QString &str);
private:
    Ui::DiffFileDialog *ui;
};

#endif // DIFFFILEDIALOG_H
