#ifndef TESTFILEFACTORY_H
#define TESTFILEFACTORY_H

#include "filefactory.h"

class TestFileFactory : public FileFactory
{
public:
    TestFileFactory();

public:
    IFile* createFile(QString name);
};

#endif // TESTFILEFACTORY_H
