#include "bdpatodatamodel.h"
#include <algorithm>

#define PATH_BD "..\\patoDataModel\\BDPatoDataModel\\DataBase\\DataModelBD.sqlite"

namespace bd {

    BDPatoDataModel* BDPatoDataModel::bdPato = NULL;

    BDPatoDataModel::BDPatoDataModel()
    {
        //init bd
        initBD();
    }

    BDPatoDataModel::~BDPatoDataModel()
    {
        db.close();
        for(int i = 0; i < db.connectionNames().size(); i++)
        {
            QSqlDatabase::removeDatabase(db.connectionNames()[i]);
        }
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

    bool BDPatoDataModel::initBD()
    {
        if ( db.connectionName().isEmpty() )
        {
            db = QSqlDatabase::addDatabase( "QSQLITE","Connection" );
            db.setDatabaseName(PATH_BD);

            qDebug() << PATH_BD;
            qDebug() << db.isOpen();
        }

        return db.open();
    }

    //repository operations>
    bool BDPatoDataModel::saveTransaction( std::string& message, std::string loginUser )
    {
        int userId = getUserId(loginUser);
        std::stringstream outUserId;
        outUserId << userId;

        std::string sqlInsertTransaction = "insert into transacao (tran_id, tran_tipo, usua_id, tran_data, tran_msg) ";
        sqlInsertTransaction.append("values (null, 1, ");
        sqlInsertTransaction.append(outUserId.str());
        sqlInsertTransaction.append(", (SELECT date('now')), '");
        sqlInsertTransaction.append(message);
        sqlInsertTransaction.append("');");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertTransaction.c_str()) )
        {
            qDebug("Executo a query");
            db.commit();
            return true;
        }

        return false;
    }

    int BDPatoDataModel::getLastAvailableVersion()
    {
        int nLastVersion = -1;
        std::string sqlLastAvailableVersion = "select max(tran_id) from transacao;";
        QSqlQuery query(db);
        if ( query.exec(sqlLastAvailableVersion.c_str()) )
        {

            while ( query.next() )
            {
                nLastVersion = query.value(0).toInt();
            }
        }

        return nLastVersion;
/*
        try{

                CppSQLite3Query resultSet = dataBase.execQuery(sqlLastAvailableVersion.c_str());
                if ( !resultSet.eof() )
                {
                        int lastVersion = resultSet.getIntField(0);
                        return lastVersion;
                }

        }
        catch(CppSQLite3Exception& e)
        {
                //write code error in file log
                e.errorMessage();
                return -1;
        }

        return -1;*/

    }

    std::string BDPatoDataModel::getNameConfigItem(int idItemConfig, std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::stringstream outIdItemConfig;
        outIdItemConfig << idItemConfig;

        std::string sqlNameItem = "select itco_nome from item_configuracao where itco_id =";
        sqlNameItem.append(" ");
        sqlNameItem.append(outIdItemConfig.str());
        sqlNameItem.append(" and proj_id = ");
        sqlNameItem.append(outProjectId.str());
        sqlNameItem.append(";");

        std::string nameItemConfig;
        QSqlQuery query(db);
        if ( query.exec(sqlNameItem.c_str()))
        {
            if ( query.next() )
                nameItemConfig = query.value(0).toString().toStdString();
        }

        return nameItemConfig;
    }

    int BDPatoDataModel::getFileIdStored(std::string& nameFile)
    {
        std::string sqlIdStoredFile = "select arqu_cd_armazenamento from arquivo a left join item_configuracao i on a.arqu_id = i.itco_id where  i.itco_nome like '";
        sqlIdStoredFile.append(nameFile);
        sqlIdStoredFile.append("';");

        int idStoredFile = 0;
        QSqlQuery query(db);
        if ( query.exec(sqlIdStoredFile.c_str()) )
        {
            if ( query.next() )
                idStoredFile = query.value(0).toInt();
        }

        return idStoredFile;
    }

    void BDPatoDataModel::getCompletePath(int idItemConfig, std::string& project, std::string& completePath)
    {
        std::stringstream outIdItemConfig;
        outIdItemConfig << idItemConfig;

        std::string sqlFilePath = "select dire_id from diretorio_item_config where itco_id =";
        sqlFilePath.append(" ");
        sqlFilePath.append(outIdItemConfig.str());
        sqlFilePath.append(";");

        int idDiretorioItemConfig = -1;
        QSqlQuery query(db);
        if ( query.exec(sqlFilePath.c_str()) )
        {
            bool bCompletou = true;
            while(query.next())
            {
                bCompletou = false;
                idDiretorioItemConfig = query.value(0).toInt();
                std::string pathNameTemp = getNameConfigItem(idDiretorioItemConfig, project);
                if ( !pathNameTemp.empty() )
                {
                    std::string completePathTemp = completePath;
                    completePathTemp.append("\\");
                    completePathTemp.append(pathNameTemp);
                    getCompletePath(idDiretorioItemConfig, project, completePathTemp);
                }
            }

            if ( bCompletou )
            {
                if ( isFile(completePath) )
                {
                    std::string nameFile = getLastFolder(completePath);
                    int idStoredFile = getFileIdStored(nameFile);
                    vecIdFile.push_back(idStoredFile);
                }
                else
                     vecIdFile.push_back(0);

                removeToken(completePath, '�');
                vecFilePath.push_back(completePath);
            }

        }

        return;

    }



    bool BDPatoDataModel::getFilePath(std::string& project, int version, std::map<std::string, int>& filePath)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::stringstream outVersion;
        if ( version == -1 )
        {
            int lastVersion = getLastAvailableVersion();
            outVersion << lastVersion;
        }
        else
            outVersion << version;

        std::string sqlFilePath = "select (select itco_nome from item_configuracao where itco_id = p.itco_id) || ";
        sqlFilePath.append("(select arqu_nome from arquivo where arqu_id = p.arqu_id), ");
        sqlFilePath.append("(select arqu_cd_armazenamento from arquivo where arqu_id = p.arqu_id) ");
        sqlFilePath.append("from proj_item_tran p where p.tran_id = ");
        sqlFilePath.append(outVersion.str());
        sqlFilePath.append(";");
        vecFilePath.clear();
        vecIdFile.clear();

        vecFilePath.clear();
        vecIdFile.clear();
        QSqlQuery query(db);
        if ( query.exec(sqlFilePath.c_str()) )
        {
            while(query.next())
            {
                vecFilePath.push_back(query.value(0).toString().toStdString());
                vecIdFile.push_back(query.value(1).toInt());
            }

            createMapFile(vecFilePath   , vecIdFile, filePath);
            return true;
        }

        return false;
    }

    bool BDPatoDataModel::getLog(std::string& project, int version, std::map<std::string, int>&  filePath)
    {
        std::stringstream outVersion;
        if ( version == -1 )
        {
            int lastVersion = getLastAvailableVersion();
            outVersion << lastVersion;
        }
        else
            outVersion << version;


        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlLog = "select (select itco_nome from item_configuracao where itco_id = p.itco_id) || ";
        sqlLog.append("(select arqu_nome from arquivo where arqu_id = p.arqu_id), ");
        sqlLog.append("(select arqu_cd_armazenamento from arquivo where arqu_id = p.arqu_id), ");
        sqlLog.append("(select arqu_status from arquivo where arqu_id = p.arqu_id) ");
        sqlLog.append("from proj_item_tran p where p.tran_id = ");
        sqlLog.append(outVersion.str());
        sqlLog.append(" and prit_in_transaction = 1;");

        vecFilePath.clear();
        vecIdFile.clear();

        QSqlQuery query(db);
        if ( query.exec(sqlLog.c_str()) )
        {
            while ( query.next() )
            {
                std::string path = query.value(0).toString().toStdString();
                path.append("�");
                path.append(query.value(2).toString().toStdString());
                vecFilePath.push_back(path);
                vecIdFile.push_back(query.value(1).toInt());
            }

            createMapFile(vecFilePath, vecIdFile, filePath);
        return false;
    }
//<

//user operations>
    bool BDPatoDataModel::validateUser(const string& login, const string& password)
    {
        std::string sqlUser = "select count(*) from usuario where usua_login like '";
        sqlUser.append(login);
        sqlUser.append("' and usua_senha like '");
        sqlUser.append(password);
        sqlUser.append("';");

        QSqlQuery query(db);
        if ( query.exec(sqlUser.c_str()) )
        {
            if( query.next() )
            {
                int nCountUser = query.value(0).toInt();
                if ( nCountUser > 0 )
                    return true;

                return false;
            }
        }

        return false;
        /*
        try{
            std::string sqlUser = "select count(*) from usuario where usua_login like '";
            sqlUser.append(login);
            sqlUser.append("' and usua_senha like '");
            sqlUser.append(password);
            sqlUser.append("';");

            CppSQLite3Query resultSet = dataBase.execQuery(sqlUser.c_str());
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
        catch (CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/
    }

    bool BDPatoDataModel::validateUserProject( const std::string& login, const std::string& password, const std::string& project )
    {
        std::string sqlUserProject = "select count(*) from usuario u, projeto_usuario pu, projeto p where u.usua_id = pu.usua_id and ";
        sqlUserProject.append("pu.proj_id = p.proj_id and ");
        sqlUserProject.append("upper(p.proj_nome) like upper('");
        sqlUserProject.append(project);
        sqlUserProject.append("') and ");
        sqlUserProject.append("upper(u.usua_login) like upper('");
        sqlUserProject.append(login);
        sqlUserProject.append("') and ");
        sqlUserProject.append("upper(u.usua_senha) like upper('");
        sqlUserProject.append(password);
        sqlUserProject.append("');");

        QSqlQuery query(db);
        if ( query.exec(sqlUserProject.c_str()) )
        {
            if ( query.next() )
            {
                int nCountUserProject = query.value(0).toInt();
                if ( nCountUserProject > 0 )
                    return true;

                return false;
            }
        }

        return false;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlUserProject.c_str());
            if ( !resultSet.eof() )
            {
                int countUserProject = resultSet.getIntField(0);
                if ( countUserProject > 0 )
                {
                        return true;
                }

                return false;
            }
        }
        catch(CppSQLite3Exception& e)
        {
            //write error in file log
            e.errorMessage();
            return false;
        }

        return true;*/
    }

    int BDPatoDataModel::getUserId(std::string& loginUser)
    {
        std::string sqlUser = "select usua_id from usuario where upper(usua_login) like upper('";
        sqlUser.append(loginUser);
        sqlUser.append("');");

        int nUserId = -1;
        QSqlQuery query(db);
        qDebug(sqlUser.c_str());
        qDebug() << query.exec(sqlUser.c_str());
        if ( query.exec(sqlUser.c_str()) )
        {
            if ( query.next() )
                nUserId = query.value(0).toInt();
        }

        return nUserId;
    }

    //<

    //project operations>
    bool BDPatoDataModel::validateProject( const string& projectName )
    {
        std::string sqlUser = "select count(*) from projeto where proj_nome like '";
        sqlUser.append(projectName);
        sqlUser.append("';");

        QSqlQuery query(db);
        if ( query.exec(sqlUser.c_str()) )
        {
            if ( query.next() )
            {
                int nCount = query.value(0).toInt();
                if (nCount > 0)
                    return true;

                return false;
            }
        }

        return false;
  /*      try{
            std::string sqlUser = "select count(*) from projeto where proj_nome like '";
            sqlUser.append(projectName);
            sqlUser.append("';");

            CppSQLite3Query resultSet = dataBase.execQuery(sqlUser.c_str());
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
        catch (CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/

    }

    int BDPatoDataModel::getProjectId(std::string& project)
    {
        std::string sqlProjectId = "select proj_id from projeto where upper(proj_nome) like upper('";
        sqlProjectId.append(project);
        sqlProjectId.append("');");

        int nProjectId = -1;
        QSqlQuery query(db);
        if ( query.exec(sqlProjectId.c_str()) )
        {
            if ( query.next() )
            {
                nProjectId = query.value(0).toInt();
            }
        }

        return nProjectId;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlProjectId.c_str());
            if ( !resultSet.eof() )
            {
                    int projectId = resultSet.getIntField(0);
                    return projectId;
            }

        }
        catch(CppSQLite3Exception& e)
        {
            //write code erro in file log
            e.errorMessage();
            return -1;
        }

        return -1;*/

    }
    //<

    //IC operations>

    std::string BDPatoDataModel::getFolderInserted(std::string& folderToInsert, std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlFolderInsert = "select itco_nome from item_configuracao where upper(itco_nome) like upper('";
        sqlFolderInsert.append(folderToInsert);
        sqlFolderInsert.append("%%%') and proj_id = ");
        sqlFolderInsert.append(outProjectId.str());
        sqlFolderInsert.append(" order by itco_nome desc;");

        std::string folderInserted;

        QSqlQuery query(db);
        if ( query.exec(sqlFolderInsert.c_str()) )
        {
            if ( query.next() )
            {
                folderInserted = query.value(0).toString().toStdString();
            }
        }

        return folderInserted;
    }


    bool BDPatoDataModel::insertFolder(std::string& filePath, std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        int lastVersionFolder = getLastVersionFolder(filePath);
        if ( lastVersionFolder > - 1 )
        {
            lastVersionFolder++;
        }
        else
        {
            lastVersionFolder = 1;
        }

        std::stringstream outLastVersionFolder;
        outLastVersionFolder << lastVersionFolder;


        std::string sqlInsert = "insert into item_configuracao(itco_id, vers_id, itco_nome, itco_status, proj_id) ";
        sqlInsert.append("values (null, ");
        sqlInsert.append(outLastVersionFolder.str());
        sqlInsert.append(", '");
        sqlInsert.append(filePath);
        sqlInsert.append("', ");
        sqlInsert.append(lastVersionFolder == 1 ? "'I', " : "'M', ");
        sqlInsert.append(outProjectId.str());
        sqlInsert.append(", ");
        sqlInsert.append(lastVersionFolder == 1 ? "'I', " : "'M'");
        sqlInsert.append(");");

        QSqlQuery query(db);
        if ( query.exec(sqlInsert.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;
    }

    int BDPatoDataModel::getLastVersionFolder(std::string& filePath)
    {
        int lastVersion = -1;

        std::string sqlVersionFolder = "select vers_id from item_configuracao where itco_nome like '";
        sqlVersionFolder.append(filePath);
        sqlVersionFolder.append("';");

        QSqlQuery query(db);
        if ( query.exec(sqlVersionFolder.c_str()) )
        {
            if ( query.next() )
            {
                lastVersion = query.value(0).toInt();
            }
        }

        return lastVersion;
    }

    int BDPatoDataModel::getLastVersionFolder(std::string& filePath)
    {
        int lastVersion = -1;

        std::string sqlVersionFolder = "select vers_id from item_configuracao where itco_nome like '";
        sqlVersionFolder.append(filePath);
        sqlVersionFolder.append("';");

        QSqlQuery query(db);
        if ( query.exec(sqlVersionFolder.c_str()) )
        {
            if ( query.next() )
            {
                lastVersion = query.value(0).toInt();
            }
        }

        return lastVersion;
    }

    bool BDPatoDataModel::insertRelationElement(std::string& project, std::string& path, std::string& file)
    {
        if ( path.empty() || file.empty() )
                return false;

        int lastFolder = getIdLastFolder(path);
        std::stringstream outLastFolder;
        outLastFolder << lastFolder;

        int IdProject = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << IdProject;

        qDebug(file.c_str());
        int lastIdFile = getIdLastFile(file);
        std::stringstream outLastIdFile;
        outLastIdFile << lastIdFile;

        int lastVersion = getLastAvailableVersion();
        std::stringstream outLastVersion;
        outLastVersion << lastVersion;

        std::string sqlInsertRelationElement = "insert into proj_item_tran( prit_id, proj_id, itco_id, arqu_id, tran_id , prit_in_transaction) values( null, ";
        sqlInsertRelationElement.append(outProjectId.str());
        sqlInsertRelationElement.append(", ");
        sqlInsertRelationElement.append(outLastFolder.str());
        sqlInsertRelationElement.append(", ");
        sqlInsertRelationElement.append(outLastIdFile.str());
        sqlInsertRelationElement.append(", ");
        sqlInsertRelationElement.append(outLastVersion.str());
        sqlInsertRelationElement.append(",1);");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertRelationElement.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;        
    }

    int BDPatoDataModel::getLastElement( std::string& project, std::string& element )
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlLastElement = "select max(itco_id) from item_configuracao where upper(itco_nome) like upper('";
        sqlLastElement.append(element);
        sqlLastElement.append("%%%') and proj_id = ");
        sqlLastElement.append(outProjectId.str());
        sqlLastElement.append(";");

        int nLastElement = -1;
        QSqlQuery query(db);
        if ( query.exec(sqlLastElement.c_str()) )
        {
            if ( query.next() )
                nLastElement = query.value(0).toInt();
        }

        return nLastElement;
        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlLastElement.c_str());
            if ( !resultSet.eof() )
            {
                    int lastElement = resultSet.getIntField(0);
                    return lastElement;
            }
        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return -1;
        }

        return -1;*/
    }

    int BDPatoDataModel::getLastProjectElement(std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlLastProjectElement = "select max(itco_id) from item_configuracao where proj_id = ";
        sqlLastProjectElement.append(outProjectId.str());
        sqlLastProjectElement.append(";");

        int nMaxProjectElement = -1;
        QSqlQuery query(db);
        if ( query.exec(sqlLastProjectElement.c_str()) )
        {
            if ( query.next() )
                nMaxProjectElement = query.value(0).toInt();
        }

        return nMaxProjectElement;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlLastProjectElement.c_str());
            if ( !resultSet.eof() )
            {
                    int lastProjectElement = resultSet.getIntField(0);
                    return lastProjectElement;
            }

        }
        catch(CppSQLite3Exception& e)
        {
                //write code erro in file log
                e.errorMessage();
                return -1;
        }

        return -1;*/
    }




    //<

    //file operations>
    bool BDPatoDataModel::isFile(std::string &path)
    {
        int posTokenFile = path.find(".");
        bool bFile = false;
        if ( posTokenFile != -1 )
            bFile = true;

        return bFile;
    }

    bool BDPatoDataModel::getPathsLastVersion()
    {
        int lastTransaction = getLastAvailableVersion();
        if ( lastTransaction > 1 )
            lastTransaction--;

        std::stringstream outLastTransaction;
        outLastTransaction << lastTransaction;

        std::string sqlFindPath = "select ( select i.itco_nome from item_configuracao i where i.itco_id = p.itco_id ) || ";
        sqlFindPath.append("(select a.arqu_nome from arquivo a where a.arqu_id = p.arqu_id) from proj_item_tran p where ");
        sqlFindPath.append("p. tran_id = ");
        sqlFindPath.append(outLastTransaction.str());

        listPathLastVersion.clear();

        QSqlQuery query(db);
        if ( query.exec(sqlFindPath.c_str()))
        {
            while ( query.next() )
            {
                std::string bdCompletePath = query.value(0).toString().toStdString();
                listPathLastVersion.push_back(bdCompletePath);
            }
        }

        return !listPathLastVersion.empty();
    }

    bool BDPatoDataModel::findPathLastVersion(std::string& path)
    {
        if ( listPathLastVersion.empty() )
            return false;

        std::list<std::string>::iterator itPath = std::find(listPathLastVersion.begin(), listPathLastVersion.end(), path);
        if ( itPath == listPathLastVersion.end() )
            return false;

        return true;
    }

    int BDPatoDataModel::getLastVersionFile(std::string& file)
    {
        int lastVersionFile = -1;

        std::string sqlFileVersion = "select vers_id from arquivo where upper(arqu_nome) like upper('";
        sqlFileVersion.append(file);
        sqlFileVersion.append("');");

        QSqlQuery query(db);
        if ( query.exec(sqlFileVersion.c_str()))
        {
            if ( query.next() )
            {
                lastVersionFile = query.value(0).toInt();
            }
        }

        return lastVersionFile;
    }

    bool BDPatoDataModel::insertFile(std::string& path, std::string& file, /*std::string& project,*/ int idFile)
    {
        std::string strStatus;
        if ( findPathLastVersion(path+file) )
            strStatus = "M";
        else
            strStatus = "I";

        std::string sqlInsertFile = "insert into arquivo( arqu_id, arqu_cd_armazenamento, arqu_nome, vers_id, arqu_status ) ";
        sqlInsertFile.append("values (null, ");

        std::stringstream outIdFile;
        outIdFile << idFile;

        int lastVersionFile = -1;
        if  ( strStatus == "M" )
        {
            lastVersionFile = getLastVersionFile(file);
            lastVersionFile++;
        }
        else
            lastVersionFile = 1;


        std::stringstream outVersionFile;
        outVersionFile << lastVersionFile;

        sqlInsertFile.append(outIdFile.str());
        sqlInsertFile.append(", '");
        sqlInsertFile.append(file);
        sqlInsertFile.append("', ");

        sqlInsertFile.append(outRemovido.str());
        sqlInsertFile.append(", ");
        sqlInsertFile.append(outVersionFile.str());
        sqlInsertFile.append(", '");
        sqlInsertFile.append(strStatus);
        sqlInsertFile.append("'');");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertFile.c_str()) )
        {
            db.commit();

            removePathPreviousTransaction(std::string(path+file));
            return true;
        }

        return false;
    }

    int BDPatoDataModel::getIdLastFile(std::string& file)
    {
        std::string strSqlLastFile = "select max(arqu_id) from arquivo where upper(arqu_nome) like ";
        strSqlLastFile.append("upper('");
        strSqlLastFile.append(file);
        strSqlLastFile.append("');");

        int idLastFile =  -1;

        QSqlQuery query(db);
        if ( query.exec(strSqlLastFile.c_str() ) )
        {
            if ( query.next() )
                idLastFile = query.value(0).toInt();
        }

        return idLastFile;
    }

    void BDPatoDataModel::createMapFile(std::vector<std::string>& _mergedPath, std::vector<int>& _mergedIdFile, std::map<std::string,int>& _filePath)
    {
        for( unsigned int i = 0; i < _mergedPath.size(); i++ )
        {
                _filePath.insert(std::make_pair<std::string,int>(_mergedPath[i], _mergedIdFile[i]));
        }
    }


    //<

    //folder operations>
    std::string BDPatoDataModel::getLastFolder(std::string& path)
    {
        int posBarra = path.rfind("\\");
        std::string lastElement;
        lastElement = path.substr(posBarra+1, path.length()-posBarra);
        return lastElement;
    }

    int BDPatoDataModel::getIdLastFolder(std::string& path)
    {
        int idFolder = -1;

        std::string sqlVersionFolder = "select max(itco_id) from item_configuracao where itco_nome like '";
        sqlVersionFolder.append(path);
        sqlVersionFolder.append("';");

        QSqlQuery query(db);
        if ( query.exec(sqlVersionFolder.c_str()) )
        {
            if ( query.next() )
            {
                idFolder = query.value(0).toInt();
            }
        }

        return idFolder;
    }

    bool BDPatoDataModel::hasFolderInsert(std::string& folder, std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlFolderInsert = "select count(*) from item_configuracao where upper(itco_nome) like upper('";
        sqlFolderInsert.append(folder);
        sqlFolderInsert.append("') and vers_id = (select max(tran_id) from transacao) and proj_id = ");
        sqlFolderInsert.append(outProjectId.str());
        sqlFolderInsert.append(";");

        QSqlQuery query(db);
        if ( query.exec(sqlFolderInsert.c_str()) )
        {
            if ( query.next() )
            {
                int nCount = query.value(0).toInt();
                if ( nCount > 0 )
                    return true;

                return false;
            }
        }

        return false;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlFolderInsert.c_str());
            if ( !resultSet.eof() )
            {
                int countFolderInsert = resultSet.getIntField(0);
                if ( countFolderInsert > 0 )
                {
                        return true;
                }

                return false;
            }

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/
    }

    /*bool BDPatoDataModel::insertFolder(std::string& filePath, std::string& project)
    {
        //insertProjectElement(filePath, project);

        int lastProjectElement = getLastProjectElement(project);
        std::stringstream outLastProjectElement;
        outLastProjectElement << lastProjectElement;

        std::string sqlInsertFolder = "insert into diretorio( dire_id ) ";
        sqlInsertFolder.append("values (");
        sqlInsertFolder.append(outLastProjectElement.str());
        sqlInsertFolder.append(");");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertFolder.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;

        /*try{

            dataBase.execDML(sqlInsertFolder.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;
    }*/
    //<

    //Relation Project version with elements>
    bool BDPatoDataModel::insertRelationProjectElementTransaction(std::string& project)
    {
        int previousVersion = -1;
        int maxVersion = getLastAvailableVersion();
        if ( maxVersion == -1 )
            return false;
        else
            if ( maxVersion > 1)
                previousVersion = maxVersion - 1;

        std::stringstream outPreviousVersion;
        outPreviousVersion << previousVersion;

        std::stringstream outMaxVersion;

        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        if ( maxVersion == 1 )
        sqlInsertRelationElement.append(");");
        {
            std::string sqlInsertRelationElement = "insert into proj_item_tran( prit_id, proj_id, itco_id, arqu_id, tran_id , prit_in_transaction) ";
            sqlInsertRelationElement.append("(select null, proj_id, itco_id, arqu_id, ");
            sqlInsertRelationElement.append(outMaxVersion.str());
            sqlInsertRelationElement.append(", 0 from proj_tem_tran where tran_id = ");
            sqlInsertRelationElement.append(outPreviousVersion.str());
            sqlInsertRelationElement.append(");");
            qDebug(sqlInsertRelationElement.c_str());
            QSqlQuery query(db);
            query.exec(sqlInsertRelationElement.c_str());
            db.commit();
        }
        else
        {
            std::string sqlLastVersion = "select p.itco_id,(select itco_nome from item_configuracao where itco_id = p.itco_id),";
            sqlLastVersion.append("p.arqu_id, (select arqu_nome from arquivo where arqu_id = p.arqu_id) ");
            sqlLastVersion.append("from proj_item_tran p where p.tran_id = ");
            sqlLastVersion.append(outPreviousVersion.str());
            sqlLastVersion.append(";");
            qDebug(sqlLastVersion.c_str());
            QSqlQuery queryLastVersion(db);
            if ( queryLastVersion.exec(sqlLastVersion.c_str()) )
                while ( queryLastVersion.next() )
                {
                    std::string pathPreviousVersion = queryLastVersion.value(1).toString().toStdString();
                    pathPreviousVersion.append(queryLastVersion.value(3).toString().toStdString());
                    qDebug(pathPreviousVersion.c_str());
                    if ( findPathLastVersion(pathPreviousVersion) )
                    {
                        qDebug("achou");
                        std::string sqlInsertRelationElement = "insert into proj_item_tran( prit_id, proj_id, itco_id, arqu_id, tran_id , prit_in_transaction) ";
                        sqlInsertRelationElement.append("values (null, ");
                        sqlInsertRelationElement.append(outProjectId.str());
                        sqlInsertRelationElement.append(", ");
                        sqlInsertRelationElement.append(queryLastVersion.value(0).toString().toStdString());
                        sqlInsertRelationElement.append(", ");
                        sqlInsertRelationElement.append(queryLastVersion.value(2).toString().toStdString());
                        sqlInsertRelationElement.append(", ");
                        sqlInsertRelationElement.append(outMaxVersion.str());
                        sqlInsertRelationElement.append(", 0);");
                        qDebug(sqlInsertRelationElement.c_str());
                        QSqlQuery query(db);
                        query.exec(sqlInsertRelationElement.c_str());
                        db.commit();
                    }
                }

            }
            return true;
    }

        return false;
    bool BDPatoDataModel::insertRelationProjectTransaction(const std::string& sqlInsert)
    {
        QSqlQuery query(db);
        if ( query.exec(sqlInsert.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;
        /*try{

            dataBase.execDML(sqlInsert.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }*/
    }
    void BDPatoDataModel::removePathPreviousTransaction(std::string path)
    {
        listPathLastVersion.remove(path);
    }


    //<

    //>String operations
    void BDPatoDataModel::removeToken(std::string& path, char token)
    {
        int pos = path.find(token);
        while( pos > -1 )
        {
                path.erase(pos,1);
                pos = path.find(token);
        }
    }

    //<

    bool BDPatoDataModel::clear()
    {
        listPathLastVersion.clear();
        return true;
    }
}
