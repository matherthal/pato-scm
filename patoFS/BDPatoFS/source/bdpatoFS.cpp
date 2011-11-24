#include "bdpatoFS.h"
#include <iostream>

#define PATH_BD "../patoDataModel/BDPatoDataModel/DataBase/DataModelBD.sqlite"
#define PATO_TEMP_FOLDER "../output/pato_temp"

//#define PATH_BD "DataModelBD.sqlite"
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
            db.setDatabaseName(QDir::toNativeSeparators(PATH_BD));

            return db.open();
        }
        return true;
    }

    //apply the file delta recursively until reach a complete file
    std::string BDPatoFS::applyPatch(QString key) {

        QSqlQuery query(db);
        static int ind = 0;

        QString data;
        QString delta_tmp;

        //query pega o conteudo e a chave para o delta do arquivo
        std::string strSql = "SELECT ARMA_CONTEUDO, ARMA_DELTA_ID FROM ARMAZENAMENTO WHERE arma_id like '";
        strSql.append(key.toStdString().c_str());
        strSql.append("';");

        if (query.exec(strSql.c_str())) {

            while (query.next()) {

                data = query.value(0).toString();
                delta_tmp = query.value(1).toString();
            }
        }

        if (delta_tmp.isEmpty()) {

            return data.toStdString();
        }

        else {


            //chama recursao, passando chave do arquivo delta
            std::string apply = applyPatch(delta_tmp);


            Patch patch(apply, data.toStdString());
            std::string buff = patch.to_string();

            qDebug(buff.c_str());


            return buff;
        }
    }

    //sqls

    //saving data - return a hash key
    StorageKey BDPatoFS::saveData(const std::string& data, std::string& key_last_version)
    {
        QSqlQuery query(db);

        QString last_content;
        QString last_delta;

        qDebug(key_last_version.c_str());

        if (!key_last_version.empty()) {

            std::string key_delta_old = key_last_version;

            qDebug("key nao vazia");
            std::string strSql = "select arma_conteudo, arma_delta_id from aramazenamento where arma_id like '";
            strSql.append(key_last_version);
            strSql.append("';");

            qDebug(strSql.c_str());

            if ( query.exec(strSql.c_str()) ) {

                while (query.next()) {
                    last_content = query.value(0).toString();
                    last_delta = query.value(1).toString();
                }
            }

            Diff diff(last_content.toStdString(), data);
            std::string delta = diff.to_delta_string();
            qDebug(delta.c_str());

            //insert delta content in the data base in the data base
            key_last_version = insertDataQuery(delta, last_delta.toStdString());

            //delete the old content
            std::vector<StorageKey> v;
            v.push_back(key_delta_old);
            deleteData(v);
        }

        //insert the current version content in the data base
        return insertDataQuery(data, key_last_version);

    }

    bool BDPatoFS::saveData(const std::vector<std::string>& data, std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecDeltIdFile)
    {

        std::vector<std::string>::const_iterator itData;
        std::vector<std::string>::iterator itDelta;
        for( itData = data.begin(), itDelta = vecDeltIdFile.begin(); itData != data.end(); itData++, itDelta++)
        {

            std::string idFile = saveData((*itData), (*itDelta));

            if ( idFile == "-1" )
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
    bool BDPatoFS::loadData(StorageKey& idFile, std::string& data)
    {
        QString file;
        QSqlQuery query(db);

        qDebug(idFile.c_str());
        //chama funcao recursiva que monta o arquivo, buscando seus deltas e versao completa
        data = applyPatch(QString::fromStdString(idFile));

        return true;

    }

    bool BDPatoFS::loadData(const std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecData)
    {
        QSqlQuery query(db);
        std::string sqlLoadData = "select arma_conteudo, arma_delta_id from armazenamento where ";
        sqlLoadData.append("arma_id in('");

        std::vector<std::string>::const_iterator itIdFile;
        for( itIdFile = vecIdFile.begin(); itIdFile != vecIdFile.end(); itIdFile++ )
        {
            if ( itIdFile != vecIdFile.begin() )
                sqlLoadData.append("', '");

            sqlLoadData.append((*itIdFile));
        }

        sqlLoadData.append("');");

        std::vector<StorageKey> vecDelta;
        if (query.exec(sqlLoadData.c_str())) {

            while(query.next()) {
                QString s = query.value(0).toString();
                vecData.push_back(s.toStdString());
                QString keyDelta = query.value(1).toString();

                qDebug(s.toStdString().c_str());
                qDebug(keyDelta.toStdString().c_str());
                vecDelta.push_back(keyDelta.toStdString());
            }

            return true;
        }
        else {
            return false;
        }
    }

    //insert a content in the data base, with a pointer to its last version (delta)
    std::string BDPatoFS::insertDataQuery(std::string data, std::string delta) {

        QSqlQuery query(db);
        //using hash key
        QString key = QString(QCryptographicHash::hash((data.c_str()),QCryptographicHash::Md5).toHex());

        std::string sqlFileInserted = "SELECT ARMA_CONTEUDO FROM ARMAZENAMENTO WHERE upper(arma_id) like upper('";
        sqlFileInserted.append(key.toStdString());
        sqlFileInserted.append("');");

        qDebug(sqlFileInserted.c_str());
        if ( query.exec(sqlFileInserted.c_str()) )
        {
            if (query.next()) {
                return key.toStdString();
            }
        }

        std::string sqlInsert = "INSERT INTO ARMAZENAMENTO (arma_id, arma_conteudo, arma_delta_id) VALUES ";
        sqlInsert.append("('");
        sqlInsert.append(key.toStdString());
        sqlInsert.append("','");
        sqlInsert.append(data);
        sqlInsert.append("','");
        if (!delta.empty())
            sqlInsert.append(delta);
        else
            sqlInsert.append("NULL");
        sqlInsert.append("');");


        //qDebug(sqlInsert.c_str());
        QSqlQuery queryInsert(db);
        if (queryInsert.exec(sqlInsert.c_str()))
        {
            return key.toStdString();
        }
        else {
            return "-1";
        }
    }


    //delete data
    bool BDPatoFS::deleteData(const std::vector<StorageKey>& idFile)
    {
        if (idFile.empty())
            return false;

        QSqlQuery query(db);
        QString sqlDelete = "delete from armazenamento where arma_id in ('";


        std::vector<std::string>::const_iterator itIdFile;
        for( itIdFile = idFile.begin(); itIdFile != idFile.end(); itIdFile++ )
        {
            if ( itIdFile != idFile.begin() )
                sqlDelete.append("', '");

            sqlDelete.append((*itIdFile).c_str());
        }

        sqlDelete.append("')");

        qDebug(sqlDelete.toStdString().c_str());
        if (query.exec(sqlDelete)) {
            return true;
        }
        else {
            return false;
        }

    }

    //<

}
