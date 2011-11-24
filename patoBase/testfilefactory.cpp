#include "ifile.h"
#include "testfilefactory.h"

#include "mockfile.h"

TestFileFactory::TestFileFactory()
{
}

IFile* TestFileFactory::createFile(QString name)
{
    return new MockFile();
}
