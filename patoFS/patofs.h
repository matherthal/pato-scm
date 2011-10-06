#ifndef PATOFS_H
#define PATOFS_H

#include "PatoFS_global.h"
#include <QtSql>

class PATOFSSHARED_EXPORT PatoFS {

private:
    PatoFS();
    ~PatoFS();

    static PatoFS* mPatoFS;
    QSqlDatabase db;

public:

	static PatoFS* getInstance();
	static vod destroyInstance();
};

#endif // PATOFS_H
