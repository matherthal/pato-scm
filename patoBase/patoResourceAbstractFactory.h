#ifndef PATORESOURCEABSTRACTFACTORY_H
#define PATORESOURCEABSTRACTFACTORY_H

#include <QObject>
#include "filefactory.h"
#include "file.h"

class PatoResourceAbstractFactory : public QObject
{
    Q_OBJECT

public:
    enum TYPE
    {
        DEFAULT,
        TEST
    };

    PatoResourceAbstractFactory(TYPE type);

    static PatoResourceAbstractFactory* getInstance();
    static void destroy();

    void setFactoryType(TYPE type);

public:
    IFile* createFile(QString name);

signals:

public slots:

private:
    void updateFactory();

private:
    static PatoResourceAbstractFactory *instance;
    TYPE type;
    FileFactory *fileFactory;
};

#endif // PATORESOURCEABSTRACTFACTORY_H
