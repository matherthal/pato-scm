#include "filefactory.h"
#include "patoResourceAbstractFactory.h"
#include "defaultlfilefactory.h"
#include "testfilefactory.h"

PatoResourceAbstractFactory* PatoResourceAbstractFactory::instance = NULL;

PatoResourceAbstractFactory::PatoResourceAbstractFactory(TYPE type)
{
    this->type = type;
    updateFactory();
}

PatoResourceAbstractFactory* PatoResourceAbstractFactory::getInstance()
{
    if (instance == NULL)
    {
        instance = new PatoResourceAbstractFactory(PatoResourceAbstractFactory::DEFAULT);
    }
    return instance;
}

void PatoResourceAbstractFactory::destroy()
{
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
}

void PatoResourceAbstractFactory::setFactoryType(TYPE type)
{
    this->type = type;
    updateFactory();
}

IFile* PatoResourceAbstractFactory::createFile(QString name) {
    return fileFactory->createFile(name);
}

void PatoResourceAbstractFactory::updateFactory()
{
    if (fileFactory != NULL)
    {
        delete fileFactory;
    }

    if (type == PatoResourceAbstractFactory::DEFAULT)
        fileFactory = new DefaultFileFactory();
    else
        fileFactory = new TestFileFactory();
}
