#ifndef DEFAULTLFILEFACTORY_H
#define DEFAULTLFILEFACTORY_H

#include "file.h"
#include "filefactory.h"

class DefaultFileFactory : public FileFactory
{
public:
    DefaultFileFactory();

public:
    IFile* createFile(QString name);
};

#endif // DEFAULTLFILEFACTORY_H
