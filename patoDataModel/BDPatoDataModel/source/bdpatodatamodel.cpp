#include "bdpatodatamodel.h"

#define PATH_BD "..\\patoDataModel\\BDPatoDataModel\\DataBase\\DataModelBD"
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
            db.commit();
            return true;
        }

        return false;

        /*try{

            dataBase.execDML(sqlInsertTransaction.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return false;
        }*/

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

                removeToken(completePath, '§');
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

        std::string sqlFilePath = "select itco_id from item_configuracao where itco_id in (select itco_id from diretorio d left join proj_item_tran p ";
        sqlFilePath.append(" on p.itco_id = d.dire_id where p.tran_id =");
        sqlFilePath.append(" ");
        sqlFilePath.append(outVersion.str());
        sqlFilePath.append(" order by itco_id) ");
        sqlFilePath.append(" and itco_nome like ((select t.proj_nome from projeto t where t.proj_id = proj_id) || '%%%');");

        QSqlQuery query(db);
        if ( query.exec(sqlFilePath.c_str()) )
        {
            while(query.next())
            {
                int idItemConfig = query.value(0).toInt();
                std::string completePath;
                completePath.append(getNameConfigItem(idItemConfig, project));
                getCompletePath(idItemConfig, project, completePath);
            }

            createMapFile(vecFilePath   , vecIdFile, filePath);
            return true;
        }

        return false;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlFilePath.c_str());
            while ( !resultSet.eof() )
            {
                    std::string path = resultSet.getStringField(0);
                    filePath.push_back(path);

                    resultSet.nextRow();
            }

            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/

    }

    bool BDPatoDataModel::getLog(std::string& project, int version, std::vector<std::string>&  filePath)
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

        std::string sqlLog = "select (select itco_nome from item_configuracao f where f.itco_id = d.itco_id) || '\\' || itco_nome , vers_id ";
        sqlLog.append("from diretorio_item_config d, item_configuracao i, proj_item_tran p ");
        sqlLog.append("where d.dire_id = i.itco_id and i.itco_id = p.itco_id  and p.tran_id = ");

        sqlLog.append(outVersion.str());
        sqlLog.append(" and i.vers_id = ");
        sqlLog.append(outVersion.str());
        sqlLog.append(" and i.proj_id = ");
        sqlLog.append(outProjectId.str());
        sqlLog.append(";");

        QSqlQuery query(db);
        if ( query.exec(sqlLog.c_str()) )
        {
            while ( query.next() )
            {
                QString path = query.value(0).toString();
                filePath.push_back(path.toStdString());
            }

            return true;
        }

        return false;

        /*try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlLog.c_str());
            while ( !resultSet.eof() )
            {
                std::string path = resultSet.getStringField(0);
                filePath.push_back(path);

                resultSet.nextRow();
            }

            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            e.errorMessage();
            return false;
        }

        return false;*/

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
        if ( query.exec(sqlUser.c_str()) )
        {
            if ( query.next() )
                nUserId = query.value(0).toInt();
        }

        return nUserId;
/*
        try{

            CppSQLite3Query resultSet = dataBase.execQuery(sqlUser.c_str());
            if ( !resultSet.eof() )
            {
                int userId = resultSet.getIntField(0);
                return userId;
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


    bool BDPatoDataModel::insertProjectElement(std::string& filePath, std::string& project)
    {
        std::string folderInserted = getFolderInserted(filePath, project);
        if ( !folderInserted.empty() )
        {
            folderInserted.append("§");
        }
        else
            folderInserted = filePath;

        int lastVersion = getLastAvailableVersion();
        std::stringstream outLastVersion;
        outLastVersion << lastVersion;

        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlInsert = "insert into item_configuracao(itco_id, vers_id, itco_nome, proj_id) ";
        sqlInsert.append("values (null, ");
        sqlInsert.append(outLastVersion.str());
        sqlInsert.append(", '");
        sqlInsert.append(folderInserted);
        sqlInsert.append("', ");
        sqlInsert.append(outProjectId.str());
        sqlInsert.append(");");

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
        }

        return false;*/
    }

    bool BDPatoDataModel::insertRelationElement(std::string& project, std::string& element, std::string& previousElement)
    {
        if ( previousElement.empty() )
                return false;

        int lastFolder = getLastElement(project, element);
        std::stringstream outLastFolder;
        outLastFolder << lastFolder;

        int lastElement = getLastElement(project, previousElement);
        std::stringstream outLastElement;
        outLastElement << lastElement;

        std::string sqlInsertRelationElement = "insert into diretorio_item_config( diic_id, dire_id, itco_id ) values( null, ";
        sqlInsertRelationElement.append(outLastFolder.str());
        sqlInsertRelationElement.append(", ");
        sqlInsertRelationElement.append(outLastElement.str());
        sqlInsertRelationElement.append(");");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertRelationElement.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;

        /*try{

                dataBase.execDML(sqlInsertRelationElement.c_str());
                return true;

        }
        catch(CppSQLite3Exception& e)
        {
                //write code error in file log
                e.errorMessage();
                return false;
        }

        return false;*/
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

    bool BDPatoDataModel::insertFile(std::string& filePath, std::string& project, int idFile)
    {
        insertProjectElement(filePath, project);

        int lastProjectElement = getLastProjectElement(project);
        std::stringstream outLastProjectElement;
        outLastProjectElement << lastProjectElement;

        std::string sqlInsertFile = "insert into arquivo( arqu_id, arqu_cd_armazenamento, arqu_id_arq_antigo, arqu_removido ) ";
        sqlInsertFile.append("values (");
        sqlInsertFile.append(outLastProjectElement.str());
        sqlInsertFile.append(", ");
        std::stringstream outIdFile;
        outIdFile << idFile;
        sqlInsertFile.append(outIdFile.str());
        sqlInsertFile.append(", null, null);");

        QSqlQuery query(db);
        if ( query.exec(sqlInsertFile.c_str()) )
        {
            db.commit();
            return true;
        }

        return false;

        /*try{

            dataBase.execDML(sqlInsertFile.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/
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

    bool BDPatoDataModel::insertFolder(std::string& filePath, std::string& project)
    {
        insertProjectElement(filePath, project);

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

        return false;*/
    }
    //<

    //Relation Project version with elements>
    bool BDPatoDataModel::insertRelationProjectElementTransaction(std::string& project)
    {
        std::stringstream outMaxVersion;
        int maxVersion = getLastAvailableVersion();
        outMaxVersion << maxVersion;

        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlMaxVersionFiles = "SELECT  I.ITCO_ID ";
        sqlMaxVersionFiles.append("FROM ITEM_CONFIGURACAO I ");
        sqlMaxVersionFiles.append("WHERE I.PROJ_ID = ");
        sqlMaxVersionFiles.append(outProjectId.str());
        sqlMaxVersionFiles.append(" AND VERS_ID = (SELECT MAX(VERS_ID) FROM ITEM_CONFIGURACAO WHERE I.ITCO_NOME = ITCO_NOME );");

        std::string sqlInsertRelation;
        QSqlQuery query(db);
        if ( query.exec(sqlMaxVersionFiles.c_str()) )
        {
            while ( query.next() )
            {
                int elementId = query.value(0).toInt();

                std::stringstream outElementId;
                outElementId << elementId;

                std::string sqlInsert = "insert into proj_item_tran(PRIT_ID, PROJ_ID, ITCO_ID, TRAN_ID) ";
                sqlInsert.append("values ( null, ");
                sqlInsert.append(outProjectId.str());
                sqlInsert.append(", ");
                sqlInsert.append(outElementId.str());
                sqlInsert.append(", ");
                sqlInsert.append(outMaxVersion.str());
                sqlInsert.append("); \n");

                //sqlInsertRelation.append(sqlInsert);

                QSqlQuery queryTransaction(db);
                if ( queryTransaction.exec(sqlInsert.c_str()) )
                {
                    db.commit();
                }
                else
                    return false;

            }
        }

        return false;

        /*try{
            std::string sqlInsertRelation;
            CppSQLite3Query resultSet = dataBase.execQuery(sqlMaxVersionFiles.c_str());
            while ( !resultSet.eof() )
            {
                int elementId = resultSet.getIntField(0);
                std::stringstream outElementId;
                outElementId << elementId;

                std::string sqlInsert = "insert into proj_item_tran(PRIT_ID, PROJ_ID, ITCO_ID, TRAN_ID) ";
                sqlInsert.append("values ( null, ");
                sqlInsert.append(outProjectId.str());
                sqlInsert.append(", ");
                sqlInsert.append(outElementId.str());
                sqlInsert.append(", ");
                sqlInsert.append(outMaxVersion.str());
                sqlInsert.append(");");

                sqlInsertRelation.append(sqlInsert);

                resultSet.nextRow();
            }

            return insertRelationProjectTransaction(sqlInsertRelation);
        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;*/

    }

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

}
