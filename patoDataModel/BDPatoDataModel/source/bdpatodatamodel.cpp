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

    //user operations>
        bool BDPatoDataModel::validateUser(const string& login, const string& password)
        {
            try{
                std::string sqlUser = "select count(*) from usuario where usua_login like '";
                sqlUser.append(login);
                sqlUser.append("' and usua_senha like '");
                sqlUser.append(password);
                sqlUser.append("';");

                CppSQLite3Query resultSet = bancoDados.execQuery(sqlUser.c_str());
                if ( !resultSet.eof() )
                {
                    int countUser = resultSet.getIntField(0);

                    if ( countUser > 0 )
                    {
                       return true;
                    }

                    return false;
                }
            }
            catch (CppSQLite3Exception& error)
            {
                //write the code error in file log
                return false;
            }

            return false;
        }
        //<

        //project operations>
        bool BDPatoDataModel::validateProject( const string& projectName )
        {
            try{
                std::string sqlUser = "select count(*) from projeto where proj_nome like '";
                sqlUser.append(projectName);
                sqlUser.append("';");

                CppSQLite3Query resultSet = bancoDados.execQuery(sqlUser.c_str());
                if ( !resultSet.eof() )
                {
                    int countProject = resultSet.getIntField(0);

                    if ( countProject > 0 )
                    {
                       return true;
                    }

                    return false;
                }
            }
            catch (CppSQLite3Exception& error)
            {
                //write the code error in file log
                return false;
            }

            return false;

        }

        //<

}
