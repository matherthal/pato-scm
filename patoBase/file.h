#ifndef FILE_H
#define FILE_H

#include <QFile>
#include "ifile.h"

class File : public IFile
{
public:
    File();

public:
    File(const QString &name);
    ~File();
    bool copy(const QString &newName);
    bool exists() const;
    QString fileName() const;
    bool remove();

private:
    QFile file;
};

#endif // FILE_H
