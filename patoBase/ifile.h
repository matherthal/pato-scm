#ifndef IFILE_H
#define IFILE_H

#include <QString>

class IFile
{
public:
    IFile();
    virtual ~IFile();
    virtual bool copy(const QString &newName) =0;
    virtual bool exists() const =0;
    virtual QString fileName() const =0;
    virtual bool remove() =0;
};

#endif // IFILE_H
