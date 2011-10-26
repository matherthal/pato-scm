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

    //saving data
    int saveData(const std::string& data);
    bool saveData(const std::vector<std::string>& data, std::vector<int>& vecIdFile);

    //loading data
    bool loadData(const int idFile, std::string& data);
    bool loadData(const std::vector<int>& vecIdFile, std::vector<std::string>& vecData);

};

#endif // PATOFS_H
