#ifndef PATOFS_H
#define PATOFS_H

#include "PatoFS_global.h"
#include <QSqlDatabase>
#include <vector>
#include <string>

class PATOFSSHARED_EXPORT PatoFS {

private:
    PatoFS();

    static PatoFS* mPatoFS;

public:
    static PatoFS* getInstance();
    static bool destroyInstance();

    bool initBD();
    //saving data
    std::string saveData(const std::string& data);
    bool saveData(const std::vector<std::string>& data, std::vector<std::string>& vecIdFile);

    //loading data
    bool loadData(std::string&  idFile, std::string& data);
    bool loadData(const std::vector<std::string>& vecIdFile, std::vector<std::string>& vecData);

};

#endif // PATOFS_H
