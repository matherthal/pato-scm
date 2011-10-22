#ifndef PATOFS_H
#define PATOFS_H

#include "PatoFS_global.h"
#include <QtSql>

class PATOFSSHARED_EXPORT PatoFS {

private:
    PatoFS();

    static PatoFS* mPatoFS;
    QSqlDatabase db;
public:
    static PatoFS* getInstance();
    static void destroyInstance();
};

#endif // PATOFS_H
