#ifndef BDPatoFS_H
#define BDPatoFS_H

#include "PatoFs_global.h"

#include "CppSQLite3.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace bd {
class PATOFSSHARED_EXPORT BDPatoFS
{
private:
    BDPatoFS();

public:

    //singleton´s pattern functions>
    static BDPatoFS* getInstance();
    static void destroyInstance();
    //<

    //init bd
    void initBD();

    //sqls
    void createSqlInsert(const std::string& data, std::string& sql);

    //saving data
    int saveData(const std::string& data);
    bool saveData(const std::vector<std::string>& data, std::vector<int>& vecIdFile);

    //loading data
    bool loadData(const int idFile, std::string& data);
    bool loadData(const std::vector<int>& vecIdFile, std::vector<std::string>& vecData);

    //delete data
    bool deleteData(const std::vector<int>& idFile);

private:

    //singleton´s pattern variable
    static BDPatoFS *bdPato;

    CppSQLite3DB dataBase;
};

}

#endif // BDPatoFS_H
