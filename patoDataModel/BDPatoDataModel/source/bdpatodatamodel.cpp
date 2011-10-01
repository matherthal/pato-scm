#include "bdpatodatamodel.h"

#define PATH_BD "\\BDPatoDataModel\\DataBase"
namespace bd {

    BDPatoDataModel* BDPatoDataModel::bdPato = NULL;

    BDPatoDataModel::BDPatoDataModel()
    {
        //init bd
        initBD();
    }

    BDPatoDataModel* BDPatoDataModel::getInstance()
    {
        if ( !bdPato )
            bdPato = new BDPatoDataModel();

        return bdPato;
    }

    void BDPatoDataModel::destroyInstance()
    {
        if ( bdPato )
        {
            delete bdPato;
            bdPato = NULL;
        }
    }

    void BDPatoDataModel::initBD()
    {
        try{
            bancoDados.open(PATH_BD);
        }
        catch (CppSQLite3Exception& error)
        {
            //write the code error in file log
            return;
        }
    }


}
