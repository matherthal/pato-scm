#ifndef BDPatoFS_H
#define BDPatoFS_H

#include "../../PatoFS_global.h"
#include "../../../patoBase/patotypes.h"
#include "../../../patoAlgorithms/diff.h";
#include "../../../patoAlgorithms/patch.h";

//#include "CppSQLite3.h"

#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

using namespace std;

namespace bd {
class PATOFSSHARED_EXPORT BDPatoFS
{
private:
    BDPatoFS();
    virtual ~BDPatoFS();

public:

    //singleton´s pattern functions>
    static BDPatoFS* getInstance();
    static bool destroyInstance();
    //<

    //init bd
    bool initBD();

    //saving data
    std::string saveData(const std::string& data, std::string& key_last_version);
    bool saveData(const std::vector<std::string>& data, std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecDeltaIdFile);

    //loading data
    bool loadData(std::string& idFile, std::string& data);
    bool loadData(const std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecData);

    //apply the patch algorithm recursively
    std::string applyPatch(QString key);

    //delete data
    bool deleteData(const std::vector<StorageKey>& idFile);

    //insert a content in the data base, with its pointer to delta
    std::string insertDataQuery(std::string data, std::string delta);

private:

    //singleton´s pattern variable
    static BDPatoFS *bdPato;
    QSqlDatabase db;



    //CppSQLite3DB dataBase;
};

}

#endif // BDPatoFS_H
