#ifndef BDPATODATAMODEL_H
#define BDPATODATAMODEL_H

#include "PatoDataModel_global.h"

#include "CppSQLite3.h"

#include <string>

using namespace std;

namespace bd {
class PATODATAMODELSHARED_EXPORT BDPatoDataModel
{
private:
    BDPatoDataModel();

public:

    //singletonīs pattern functions>
    static BDPatoDataModel* getInstance();
    static void destroyInstance();
    //<

    //init bd
    void initBD();

private:

    //singletonīs pattern variable
    static BDPatoDataModel *bdPato;

    CppSQLite3DB bancoDados;
};

}

#endif // BDPATODATAMODEL_H
