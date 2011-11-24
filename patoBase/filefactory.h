#ifndef FILEFACTORY_H
#define FILEFACTORY_H

#include "file.h"

class FileFactory
{
public:
    FileFactory();

public:
    virtual IFile* createFile(QString name) = 0;
};

#endif // FILEFACTORY_H
