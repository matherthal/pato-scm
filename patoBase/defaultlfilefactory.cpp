#include "defaultlfilefactory.h"

DefaultFileFactory::DefaultFileFactory()
{
}

IFile* DefaultFileFactory::createFile(QString name)
{
    return new File(name);
}
