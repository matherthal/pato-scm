#ifndef DIFFTOOL_H
#define DIFFTOOL_H

#include <QMainWindow>

namespace Ui {
    class DiffTool;
}

class DiffTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit DiffTool(QWidget *parent = 0);
    ~DiffTool();

private slots:
    void loadFileOne();
    void loadFileTwo();
    void showDiffAB();
    void showDiffBA();
private:
    Ui::DiffTool *ui;
};

#endif // DIFFTOOL_H
