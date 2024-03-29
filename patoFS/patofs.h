#ifndef PATOFS_H
#define PATOFS_H

#include "PatoFS_global.h"
#include <QSqlDatabase>
#include <vector>
#include <string>
#include "../patoBase/patotypes.h"

class PATOFSSHARED_EXPORT PatoFS {

private:
    PatoFS();

    static PatoFS* mPatoFS;

public:
    static PatoFS* getInstance();
    static bool destroyInstance();

    bool initBD();
    //saving data
    std::string saveData(const std::string& data, std::string& key_last_version, std::map<std::string, std::string> idUpate);
    bool saveData(const std::vector<std::string>& data, std::vector<StorageKey>& vecIdFile, std::vector<StorageKey>& vecDeltaIdFile, std::map<std::string, std::string>& idUpdate);

    //loading data
    bool loadData(StorageKey&  idFile, std::string& data);
    bool loadData(const std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecData);

};

#endif // PATOFS_H
