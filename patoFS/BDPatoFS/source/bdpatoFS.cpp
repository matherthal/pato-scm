#include "bdpatofs.h"

#define PATH_BD "..\\patoDataModel\\BDPatoDataModel\\DataBase\\DataModelBD"
namespace bd {

    BDPatoFS* BDPatoFS::bdPato = NULL;

    BDPatoFS::BDPatoFS()
    {
        //init bd
        initBD();
    }

    BDPatoFS* BDPatoFS::getInstance()
    {
        if ( !bdPato )
            bdPato = new BDPatoFS();

        return bdPato;
    }

    void BDPatoFS::destroyInstance()
    {
        if ( bdPato )
        {
            delete bdPato;
            bdPato = NULL;
        }
    }

    void BDPatoFS::initBD()
    {
        try{
            dataBase.open(PATH_BD);
        }
        catch (CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return;
        }
    }

    //sqls
    void BDPatoFS::createSqlInsert(const std::string& data, std::string& sql)
    {
        std::string sqlInsert = "insert into armazenamento ( arma_id, arma_conteudo ) values ( null, '";
        sqlInsert.append(data);
        sqlInsert.append("' ); \n");

        sql.append(sqlInsert);
    }

    //saving data
    int BDPatoFS::saveData(const std::string& data)
    {
        std::string sqlInsert = "insert into armazenamento ( arma_id, arma_conteudo ) values ( null, '";
        sqlInsert.append(data);
        sqlInsert.append("' );");

        try{

            dataBase.execDML("begin transaction;");
            dataBase.execDML(sqlInsert.c_str());
            dataBase.execDML("commit transaction;");

            std::string sqlMaxId = "select max(arma_id) from armazenamento;";
            CppSQLite3Query resultSet = dataBase.execQuery(sqlMaxId.c_str());
            if ( !resultSet.eof() )
            {
                int maxID = resultSet.getIntField(0);
                return maxID;
            }

            return -1;
        }
        catch(CppSQLite3Exception& e)
        {
            dataBase.execDML("rollback;");
            e.errorMessage();
            return -1;
        }

       return -1;
    }

    bool BDPatoFS::saveData(const std::vector<std::string>& data, std::vector<int>& vecIdFile)
    {
        std::vector<std::string>::const_iterator itData;
        for( itData = data.begin(); itData != data.end(); itData++ )
        {
            int idFile = saveData((*itData));
            if ( idFile == -1 )
            {
                deleteData(vecIdFile);
                return false;
            }
            else
            {
                vecIdFile.push_back(idFile);
            }
        }

        return true;
    }

    //loading data
    bool BDPatoFS::loadData(const int idFile, std::string& data)
    {
        std::stringstream outIDFile;
        outIDFile << idFile;

        std::string sqlFile = "select arma_conteudo from armazenamento where arma_id = ";
        sqlFile.append(outIDFile.str());
        sqlFile.append(";");

        try{
            CppSQLite3Query resultSet = dataBase.execQuery(sqlFile.c_str());
            if ( !resultSet.eof() )
            {
                data = resultSet.getStringField(0);
                return true;
            }

            return false;
        }
        catch(CppSQLite3Exception& e)
        {
            e.errorMessage();
            return false;
        }

        return false;
    }
    bool BDPatoFS::loadData(const std::vector<int>& vecIdFile, std::vector<std::string>& vecData)
    {
        std::string sqlLoadData = "select arma_conteudo from armazenamento where arma_id in (";

        std::vector<int>::const_iterator itIdFile;
        for( itIdFile = vecIdFile.begin(); itIdFile != vecIdFile.end(); itIdFile++ )
        {
            if ( itIdFile != vecIdFile.begin() )
                sqlLoadData.append(", ");

            std::stringstream outIdFile;
            outIdFile << (*itIdFile);

            sqlLoadData.append(outIdFile.str());
        }

        try{
            CppSQLite3Query resultSet = dataBase.execQuery(sqlLoadData.c_str());
            while( !resultSet.eof() )
            {
                std::string data = resultSet.getStringField(0);
                vecData.push_back(data);

                resultSet.nextRow();
            }

            return true;
        }
        catch(CppSQLite3Exception& e)
        {
            e.errorMessage();
            return false;
        }

        return false;
    }

    //delete data
    bool BDPatoFS::deleteData(const std::vector<int>& idFile)
    {
        std::string sqlDelete = "delete from armazenamento where arma_id in (";

        std::vector<int>::const_iterator itIdFile;
        for( itIdFile = idFile.begin(); itIdFile != idFile.end(); itIdFile++ )
        {
            if ( itIdFile != idFile.begin() )
                sqlDelete.append(", ");

            std::stringstream outIdFile;
            outIdFile << (*itIdFile);

            sqlDelete.append(outIdFile.str());
        }

        sqlDelete.append(");");

        try{
            dataBase.execDML(sqlDelete.c_str());
            return true;
        }
        catch(CppSQLite3Exception& e)
        {
            e.errorMessage();
            return false;
        }

        return false;
    }

    //<

}
