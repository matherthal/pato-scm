#include "bdpatoFS.h"
#include <iostream>

#define PATH_BD "..\\patoDataModel\\BDPatoDataModel\\DataBase\\DataModelBD"
namespace bd {

    BDPatoFS* BDPatoFS::bdPato = NULL;

    BDPatoFS::BDPatoFS()
    {
        //init bd
        initBD();
    }


    BDPatoFS::~BDPatoFS()
    {
        db.close();
        for(int i = 0; i < db.connectionNames().size(); i++)
        {
            QSqlDatabase::removeDatabase(db.connectionNames()[i]);
        }
    }

    BDPatoFS* BDPatoFS::getInstance()
    {
        if ( !bdPato )
            bdPato = new BDPatoFS();

        return bdPato;
    }

    bool BDPatoFS::destroyInstance()
    {
        if ( bdPato )
        {
            delete bdPato;
            bdPato = NULL;

            return true;
        }
        return false;
    }

    bool BDPatoFS::initBD()
    {
        qDebug("conecta no bd");
        if ( db.connectionName().isEmpty() )
        {
            db = QSqlDatabase::addDatabase( "QSQLITE","ConnectionPatoFS" );
            db.setDatabaseName(PATH_BD);
            return db.open();
        }
        return true;
    }

    //sqls

    //nao entendi pra que essa funcao...
    void BDPatoFS::createSqlInsert(const std::string& data, std::string& sql)
    {
        /*
        std::string sqlInsert = "insert into armazenamento ( arma_id, arma_conteudo ) values ( null, '";
        sqlInsert.append(data);
        sqlInsert.append("' ); \n");

        sql.append(sqlInsert);
        */

        //Cria um objeto query
        QSqlQuery query(db);
        QString qdata = QString(data.c_str());

        db.transaction();

        query.prepare("INSERT INTO ARMAZENAMENTO (arma_conteudo) VALUES (:cont)");
        query.bindValue(":cont", qdata);
        query.exec();

        db.commit();

    }

    //saving data
    int BDPatoFS::saveData(const std::string& data)
    {
        int key = -1;

        std::string sqlInsert = "INSERT INTO ARMAZENAMENTO (arma_id, arma_conteudo) VALUES ";
        sqlInsert.append("(null,'");
        sqlInsert.append(data);
        sqlInsert.append("');");

        qDebug() << sqlInsert.c_str();

        QSqlQuery query(db);
        if (query.exec(sqlInsert.c_str())) {
            qDebug()<< "executou a query";
            db.commit();
            //última chave inserida...
            query.exec("SELECT MAX(ARQU_ID) FROM ARMAZENAMENTO");

            if ( query.next() )
                key = query.value(0).toInt();
        }

        return key;

       qDebug() << query.executedQuery();

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
        /*
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
        */

        QString file;
        QSqlQuery query(db);

        query.prepare("SELECT ARMA_CONTEUDO FROM ARMAZENAMENTO WHERE arma_id = :key");
        query.bindValue(":key",idFile);

        query.exec();

        while (query.next()) {
            file = query.value(0).toString();
        }

        data = file.toStdString();

        return true;

    }
    bool BDPatoFS::loadData(const std::vector<int>& vecIdFile, std::vector<std::string>& vecData)
    {
        /*
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
        */

        QSqlQuery query(db);
        QString sqlLoadData = "SELECT arma_conteudo FROM ARMAZENAMENTO WHERE arma_id IN (";

        std::vector<int>::const_iterator itIdFile;
        for( itIdFile = vecIdFile.begin(); itIdFile != vecIdFile.end(); itIdFile++ )
        {
            if ( itIdFile != vecIdFile.begin() )
                sqlLoadData.append(", ");

            std::stringstream OutId;
            OutId << (*itIdFile);

            sqlLoadData.append(OutId.str().c_str());
        }

        sqlLoadData.append(");");

        if (query.exec(sqlLoadData)) {

            while(query.next()) {
                QString s = query.value(0).toString();

                vecData.push_back(s.toStdString());
            }

            return true;
        }
        else {
            return false;
        }
    }

    //delete data
    bool BDPatoFS::deleteData(const std::vector<int>& idFile)
    {
        /*
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
        */

        QSqlQuery query(db);
        QString sqlDelete = "delete from armazenamento where arma_id in (";

        std::vector<int>::const_iterator itIdFile;
        for( itIdFile = idFile.begin(); itIdFile != idFile.end(); itIdFile++ )
        {
            if ( itIdFile != idFile.begin() )
                sqlDelete.append(", ");

            sqlDelete.append((*itIdFile));
        }

        sqlDelete.append(")");

        if (query.exec(sqlDelete)) {
            return true;
        }
        else {
            return false;
        }

    }

    //<

}
