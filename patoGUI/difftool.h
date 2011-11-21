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

signals:
    void stringDiffFile(const QString &str);
    void stringFile1(const QString &str);
    void stringFile2(const QString &str);
private slots:
    void loadFileOne();
    void loadFileTwo();
    void showDiffAB();
    void showDiffBA();
    void openDiffFile();
private:
    Ui::DiffTool *ui;
};

#endif // DIFFTOOL_H
