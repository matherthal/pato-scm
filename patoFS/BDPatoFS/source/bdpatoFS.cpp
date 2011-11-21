#include "bdpatoFS.h"
#include <iostream>

#define PATH_BD "../patoDataModel/BDPatoDataModel/DataBase/DataModelBD.sqlite"
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

        query.prepare("SELECT ARMA_CONTEUDO, ARMA_DELTA_ID FROM ARMAZENAMENTO WHERE arma_id = :key");
        query.bindValue(":key",key.toStdString().c_str());

        if (query.exec()) {

            while (query.next()) {

                data = query.value(0).toString();
                delta_tmp = query.value(1).toString();
            }
        }

        qDebug(key.toStdString().c_str());
        qDebug(data.toStdString().c_str());
        qDebug(delta_tmp.toStdString().c_str());

        if (delta_tmp.isEmpty()) {

            return data.toStdString();

        }

        else {

            //cria arquivo temporario contendo conteudo referente a chave passada
            QString filePath = "./pato_temp/" + key + ".temp";
            QFile completeFile(filePath);

            //abre o arquivo para escrita
            completeFile.open(QIODevice::WriteOnly | QIODevice::Text);

            filePath = "./pato_temp/delta" + delta_tmp + ".temp";
            QFile deltaFile(filePath);

            QTextStream content1(&completeFile);
            QTextStream content2(&deltaFile);

            std::string apply = applyPatch(delta_tmp);

            content1 << apply.c_str();
            content2 << data.toStdString().c_str();

            char* deltaChar = (char*) QFileInfo(deltaFile).absoluteFilePath().toStdString().c_str();
            char* completeChar = (char*) QFileInfo(deltaFile).absoluteFilePath().toStdString().c_str();

            Patch patch(deltaChar, completeChar);

            filePath = "./pato_temp/build_file" + QString::number(ind++) + ".temp";
            QFile newFile(filePath.toStdString().c_str());

            char* patchChar = (char*) QFileInfo(newFile).absoluteFilePath().toStdString().c_str();
            patch.getFile(patchChar);

            newFile.open(QIODevice::ReadOnly);

            QTextStream stream ( &newFile );
            QString buff;
            while( !stream.atEnd()) {
                 buff.append(stream.readLine());
            }

            return buff.toStdString();
        }
    }

    //sqls

    //saving data - return a hash key
    StorageKey BDPatoFS::saveData(const std::string& data)
    {
        //using hash key
        QString key = QString(QCryptographicHash::hash((data.c_str()),QCryptographicHash::Md5).toHex());
        QSqlQuery query(db);

        std::string sqlFileInserted = "SELECT ARMA_CONTEUDO FROM ARMAZENAMENTO WHERE upper(arma_id) like upper('";
        sqlFileInserted.append(key.toStdString());
        sqlFileInserted.append("');");

        if ( query.exec(sqlFileInserted.c_str()) )
        {
            qDebug("rodou query");
            if (query.next()) {
                return key.toStdString();
            }
        }

        std::string sqlInsert = "INSERT INTO ARMAZENAMENTO (arma_id, arma_conteudo) VALUES ";
        sqlInsert.append("('");
        sqlInsert.append(key.toStdString());
        sqlInsert.append("','");
        sqlInsert.append(data);
        sqlInsert.append("');");

        qDebug(sqlInsert.c_str());
        QSqlQuery queryInsert(db);
        if (queryInsert.exec(sqlInsert.c_str()))
        {
            return key.toStdString();
        }
        else {
            return "-1";
        }
    }

    bool BDPatoFS::saveData(const std::vector<std::string>& data, std::vector<StorageKey>& vecIdFile)
    {

        std::vector<std::string>::const_iterator itData;
        for( itData = data.begin(); itData != data.end(); itData++ )
        {
            std::string idFile = saveData((*itData));

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

        query.prepare("SELECT ARMA_DELTA_ID FROM ARMAZENAMENTO WHERE arma_id = :key");
        query.bindValue(":key",idFile.c_str());

        query.exec();

        QString delta_key;
        while (query.next()) {
            delta_key = query.value(0).toString();
        }

        QDir().mkdir("pato_temp");
        data = applyPatch(QString::fromStdString(idFile));

        /*
        query.prepare("SELECT ARMA_CONTEUDO FROM ARMAZENAMENTO WHERE arma_id = :key");
        query.bindValue(":key",idFile.c_str());

        query.exec();

        while (query.next()) {
            file = query.value(0).toString();
        }

        data = file.toStdString();

        */
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

    //delete data
    bool BDPatoFS::deleteData(const std::vector<StorageKey>& idFile)
    {
        if (idFile.empty())
            return false;

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
