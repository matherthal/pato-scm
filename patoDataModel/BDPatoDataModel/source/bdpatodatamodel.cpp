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
            dataBase.open(PATH_BD);
        }
        catch (CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return;
        }
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

        try{

            dataBase.execDML(sqlInsertTransaction.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write the code error in file log
            e.errorMessage();
            return false;
        }

    }

    int BDPatoDataModel::getLastAvailableVersion()
    {
        std::string sqlLastAvailableVersion = "select max(tran_id) from transacao;";

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

        return -1;

    }


    bool BDPatoDataModel::getFilePath(std::string& project, int version, std::vector<std::string>& filePath)
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

        std::string sqlFilePath = "select (select itco_nome from item_configuracao f where f.itco_id = d.itco_id) || '\\' || itco_nome ";
        sqlFilePath.append("from diretorio_item_config d, item_configuracao i, proj_item_tran p ");
        sqlFilePath.append("where d.dire_id = i.itco_id and i.itco_id = p.itco_id and p.tran_id = ");
        sqlFilePath.append(outVersion.str());
        sqlFilePath.append(" and i.proj_id = ");
        sqlFilePath.append(outProjectId.str());
        sqlFilePath.append(";");

        try{

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

        return false;

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

        try{

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

        return false;

    }
//<

//user operations>
    bool BDPatoDataModel::validateUser(const string& login, const string& password)
    {
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

        return false;
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

        try{

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

        return true;
    }

    int BDPatoDataModel::getUserId(std::string& loginUser)
    {
        std::string sqlUser = "select usua_id from usuario where upper(usua_login) like upper('";
        sqlUser.append(loginUser);
        sqlUser.append("');");

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

        return -1;
    }

    //<

    //project operations>
    bool BDPatoDataModel::validateProject( const string& projectName )
    {
        try{
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

        return false;

    }

    int BDPatoDataModel::getProjectId(std::string& project)
    {
        std::string sqlProjectId = "select proj_id from projeto where upper(proj_nome) like upper('";
        sqlProjectId.append(project);
        sqlProjectId.append("');");

        try{

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

        return -1;

    }
    //<

    //IC operations>
    bool BDPatoDataModel::insertProjectElement(std::string& filePath, std::string& project)
    {
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
        sqlInsert.append(filePath);
        sqlInsert.append("', ");
        sqlInsert.append(outProjectId.str());
        sqlInsert.append(");");

        try{

            dataBase.execDML(sqlInsert.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;
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

        try{

                dataBase.execDML(sqlInsertRelationElement.c_str());
                return true;

        }
        catch(CppSQLite3Exception& e)
        {
                //write code error in file log
                e.errorMessage();
                return false;
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
        sqlLastElement.append("') and proj_id = ");
        sqlLastElement.append(outProjectId.str());
        sqlLastElement.append(";");

        try{

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

        return -1;
    }

    int BDPatoDataModel::getLastProjectElement(std::string& project)
    {
        int projectId = getProjectId(project);
        std::stringstream outProjectId;
        outProjectId << projectId;

        std::string sqlLastProjectElement = "select max(itco_id) from item_configuracao where proj_id = ";
        sqlLastProjectElement.append(outProjectId.str());
        sqlLastProjectElement.append(";");

        try{

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

        return -1;
    }




    //<

    //file operations>
    bool BDPatoDataModel::insertFile(std::string& filePath, std::string& project)
    {
        insertProjectElement(filePath, project);

        int lastProjectElement = getLastProjectElement(project);
        std::stringstream outLastProjectElement;
        outLastProjectElement << lastProjectElement;

        std::string sqlInsertFile = "insert into arquivo( arqu_id, arqu_cd_armazenamento, arqu_id_arq_antigo, arqu_removido ) ";
        sqlInsertFile.append("values (");
        sqlInsertFile.append(outLastProjectElement.str());
        sqlInsertFile.append(", null, null, 0);");

        try{

            dataBase.execDML(sqlInsertFile.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }

        return false;
    }

    //<

    //folder operations>
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

        try{

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

        return false;
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

        try{

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
        try{
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

        return false;

    }

    bool BDPatoDataModel::insertRelationProjectTransaction(const std::string& sqlInsert)
    {
        try{

            dataBase.execDML(sqlInsert.c_str());
            return true;

        }
        catch(CppSQLite3Exception& e)
        {
            //write code error in file log
            e.errorMessage();
            return false;
        }
    }


    //<

}
