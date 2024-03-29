#include "patoserverapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>


PatoServerApi* PatoServerApi::patoServerApi = NULL;

PatoServerApi::PatoServerApi()
{

}

PatoServerApi::~PatoServerApi()
{
    PatoServerApi::destroyInstance();
}

PatoServerApi* PatoServerApi::getInstance() {

    if (patoServerApi == NULL)
        patoServerApi = new PatoServerApi();

    return patoServerApi;
}

void PatoServerApi::destroyInstance() {

    if (patoServerApi != NULL) {

        PatoDataModel::destroyInstance();
        PatoFS::destroyInstance();

        delete patoServerApi;
        patoServerApi = NULL;
    }
}

int PatoServerApi::checkOut(QString path, QString username, QString password, int revision,
                             std::map<std::string, std::string>& filesCheckOut)
{
    //validating project
    if (!PatoDataModel::getInstance()->validateProject(path.toStdString()))
        return -1;

    //validating user
    if (!PatoDataModel::getInstance()->validateUser(username.toStdString(),password.toStdString()))
        return -1;

    //test if the user is authorized
    if (!PatoDataModel::getInstance()->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return -1;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    //clear content of checkout's map
    filesCheckOut.clear();

    //this map will be filled with file names and file keys (hash code)
    map<string, StorageKey> filePath;

    //filePath is a map that contains file name and its keys (hash code)
    int retCheckOut = PatoDataModel::getInstance()->checkOut(strUsername, strPassword, strPath,revision, filePath);
    if ( retCheckOut == -1)
        return -1;

    //file key (hash code)
    vector<StorageKey> key;
    //files content

    //this map contains file names and its content
    map<string, string>::iterator it;
    for ( it=filePath.begin() ; it != filePath.end(); it++ ) {

        //storaging in the vector all file keys
        key.push_back((*it).second);
    }

    /*
    //trying to storage dat
    std::vector<std::string> content;
    if (!PatoFS::getInstance()->loadData(key, content)) {

       //if an error occurs, return a null pointer
       return false;
    }
    */

    /*
    if(filePath.empty())
        qDebug("FERROU!");
    else {

        for (it = filePath.begin(); it != filePath.end(); it++)
            qDebug() << "mapa:" << it->first.c_str() << " e " << it->second.c_str();
    }
    */

    vector<string>::iterator cit;
    for ( it = filePath.begin(), cit = key.begin() ; it != filePath.end(); it++, cit++ ) {

       //if success, store in a map the file name (first) and file content (second)
       std::string conteudo;
       //qDebug() << "API server: Parametros do checkin (FS):" << it->second.c_str() << " e " << conteudo.c_str() << " !!";
       PatoFS::getInstance()->loadData(it->second, conteudo);
       filesCheckOut[(*it).first] = conteudo;
    }

    return retCheckOut;
}

bool PatoServerApi::checkIn(QString project, QString username, QString password, QString message,
                            std::map<std::string, std::string>& filesCheckIn)
{
    string msg = message.toStdString();
    string strUsername = username.toStdString();
    string strPw = password.toStdString();
    string strProj = project.toStdString();

    //storage and versioning model references
    PatoFS* storage = PatoFS::getInstance();
    PatoDataModel* dataModel = PatoDataModel::getInstance();

    //validating project
    if (!dataModel->validateProject(strProj))
        return false;

    //validating user
    if (!dataModel->validateUser(strUsername, strPw))
        return false;

    //test if a user is authorized
    if (!dataModel->validateUserProject(strUsername, strPw, strProj))
        return false;

    //this function will fill the fileKey vector with all file keys
    vector<StorageKey> fileKey;
    std::vector<std::string> fileContent;
    std::vector<std::string> deltaKey; //for each file, key for its last version
    std::map<std::string, std::string>::iterator itMap;

    for( itMap = filesCheckIn.begin(); itMap != filesCheckIn.end(); itMap++ )
    {
        fileContent.push_back(itMap->second);

        //get the last version key from data model
        std::vector<std::string> vecCodeStorage; //contains all versions key (last position contains the last version)
        std::string path = itMap->first; //contains the file path (complete)

        dataModel->getCodStorage(path, vecCodeStorage);

        //put the last version key in a vector (for each file)
        if (!vecCodeStorage.empty()) {
            deltaKey.push_back(vecCodeStorage.back());
        }
        else {
            deltaKey.push_back(string(""));
        }
    }

    //qDebug("salvando conteudo no armazenamento...");

    std::map<std::string, std::string> idUpdate;
    //for each file, its content, key (will be fill) and deltaKey (key of last version)
    storage->saveData(fileContent, fileKey, deltaKey, idUpdate);

    std::map<std::string, std::string>::iterator itUpdate;
    for (itUpdate = idUpdate.begin(); itUpdate != idUpdate.end(); itUpdate++) {
        std::string old_key = itUpdate->first;
        std::string new_key = itUpdate->second;
        PatoDataModel::getInstance()->updateCodStorageFile(old_key, new_key);
    }

    vector<StorageKey>::iterator itFileKey;
    if ( fileKey.empty() )
        return false;

    //filling the map with file names (path) and keys to pass to checkIn function
    map<string, StorageKey> filePathKey;

    std::map<std::string, std::string>::iterator itPath;
    vector<StorageKey>::iterator itKey;
    for (itPath = filesCheckIn.begin(), itKey = fileKey.begin() ; itPath != filesCheckIn.end(); ++itPath, ++itKey) {
        filePathKey[itPath->first] = (*itKey);
    }

    if (!dataModel->checkIn(filePathKey, strProj, strUsername, msg))
        return false;

    return true;
}

bool PatoServerApi::showLog(QString project, QString username, QString password, int version,
             PatoLog& log)
{
    string strUsername = username.toStdString();
    string strPw = password.toStdString();
    string strProj = project.toStdString();

    return PatoDataModel::getInstance()->showLog(strUsername, strPw, strProj, version, log );
}

bool PatoServerApi::showLogPathFile(QString& project, QString userLogin, QString password,
                                    QString &path, std::vector<PatoLog>& vecLog)
{
    string strPath = path.toStdString();
    string strProject = project.toStdString();
    string strUsername = userLogin.toStdString();
    string strPw = password.toStdString();

    return PatoDataModel::getInstance()->showLogPathFile(strProject, strUsername, strPw, strPath, vecLog);
}

bool PatoServerApi::validateProject(QString& project)
{
    std::string strProject = project.toStdString();
    return PatoDataModel::getInstance()->validateProject(strProject);
}

bool PatoServerApi::createProject(QString& project)
{
    std::string strProject = project.toStdString();
    return PatoDataModel::getInstance()->createProject(strProject);
}

bool PatoServerApi::validateUser(QString& userLogin, QString& userPass)
{
    std::string strUserLogin = userLogin.toStdString();
    std::string strUserPass = userPass.toStdString();
    return PatoDataModel::getInstance()->validateUser(strUserLogin, strUserPass);
}

bool PatoServerApi::createUser(QString& userName, QString& userLogin, QString& userPass)
{
    std::string strUserName = userName.toStdString();
    std::string strUserLogin = userLogin.toStdString();
    std::string strUserPass = userPass.toStdString();
    return PatoDataModel::getInstance()->createUser(strUserName, strUserLogin, strUserPass);
}

bool PatoServerApi::addUserProject(QString& user, QString project)
{
    std::string strUser = user.toStdString();
    std::string strProject = project.toStdString();
    return PatoDataModel::getInstance()->addUserProject(strUser, strProject);
}


