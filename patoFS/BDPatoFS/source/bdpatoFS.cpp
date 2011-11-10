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
        if ( db.connectionName().isEmpty() )
        {
            db = QSqlDatabase::addDatabase( "QSQLITE","ConnectionPatoFS" );
            db.setDatabaseName(PATH_BD);
            return db.open();
        }
        return true;
    }

    //sqls

    //saving data - return a hash key
    std::string BDPatoFS::saveData(const std::string& data)
    {
        //using hash key
        QString key = QString(QCryptographicHash::hash((data.c_str()),QCryptographicHash::Md5).toHex());

        std::string sqlInsert = "INSERT INTO ARMAZENAMENTO (arma_id, arma_conteudo) VALUES ";
        sqlInsert.append("(");
        sqlInsert.append(key.toStdString());
        sqlInsert.append(",'");
        sqlInsert.append(data);
        sqlInsert.append("');");

        QSqlQuery query(db);

        if (query.exec(sqlInsert.c_str())) {
            return key.toStdString();
        }
        else
            return "-1";
    }

    bool BDPatoFS::saveData(const std::vector<std::string>& data, std::vector<std::string>& vecIdFile)
    {

        std::vector<std::string>::const_iterator itData;
        for( itData = data.begin(); itData != data.end(); itData++ )
        {
            std::string idFile = saveData((*itData));

            if ( idFile.compare("-1") )
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
    bool BDPatoFS::loadData(std::string& idFile, std::string& data)
    {
        QString file;
        QSqlQuery query(db);

        query.prepare("SELECT ARMA_CONTEUDO FROM ARMAZENAMENTO WHERE arma_id = :key");
        query.bindValue(":key",idFile.c_str());

        query.exec();

        while (query.next()) {
            file = query.value(0).toString();
        }

        data = file.toStdString();

        return true;

    }
    bool BDPatoFS::loadData(const std::vector<std::string>& vecIdFile, std::vector<std::string>& vecData)
    {
        QSqlQuery query(db);
        QString sqlLoadData = "SELECT arma_conteudo FROM ARMAZENAMENTO WHERE arma_id IN (";

        std::vector<std::string>::const_iterator itIdFile;
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
    bool BDPatoFS::deleteData(const std::vector<std::string>& idFile)
    {
        QSqlQuery query(db);
        QString sqlDelete = "delete from armazenamento where arma_id in (";

        std::vector<std::string>::const_iterator itIdFile;
        for( itIdFile = idFile.begin(); itIdFile != idFile.end(); itIdFile++ )
        {
            if ( itIdFile != idFile.begin() )
                sqlDelete.append(", ");

            sqlDelete.append((*itIdFile).c_str());
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
