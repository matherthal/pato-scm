#include "patoserverapi.h"
#include "../patoDataModel/patodatamodel.h"
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

bool PatoServerApi::checkOut(QString path, QString username, QString password, int revision,
                             std::map<std::string, std::string>& filesCheckOut)
{

    //validating project
    if (!PatoDataModel::getInstance()->validateProject(path.toStdString()))
        return false;

    //validating user
    if (!PatoDataModel::getInstance()->validateUser(username.toStdString(),password.toStdString()))
        return false;

    //test if the user is authorized
    if (!PatoDataModel::getInstance()->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return false;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    //clear content of checkout´s map
    filesCheckOut.clear();

    //this map will be filled with file names and file keys (hash code)
    map<string, StorageKey> filePath;

    //filePath is a map that contains file name and its keys (hash code)
    if (!PatoDataModel::getInstance()->checkOut(strUsername, strPassword, strPath,revision, filePath))
        return false;

    //file key (hash code)
    vector<StorageKey> key;
    //files content

    //this map contains file names and its content
    map<string, string>::iterator it;
    for ( it=filePath.begin() ; it != filePath.end(); it++ ) {

        //storaging in the vector all file keys
        key.push_back((*it).second);
    }

   //trying to storage dat
    std::vector<std::string> content;
    if (!PatoFS::getInstance()->loadData(key, content)) {

       //if an error occurs, return a null pointer
       return false;
   }

   vector<string>::iterator cit;
   for ( it = filePath.begin(), cit = key.begin() ; it != filePath.end(); it++, cit++ ) {

       //if success, store in a map the file name (first) and file content (second)
       std::string conteudo;
       PatoFS::getInstance()->loadData(it->second, conteudo);
       filesCheckOut[(*it).first] = conteudo;
   }

   return true;

}

bool PatoServerApi::checkIn(QString project, QString username, QString password, QString message,
                            std::map<std::string, std::string>& filesCheckIn)
{

    string msg = message.toStdString();
    string strUsername = username.toStdString();
    string strPw = password.toStdString();
    string strProj = project.toStdString();

    //validating project
    if (!PatoDataModel::getInstance()->validateProject(strProj))
        return false;

    //validating user
    if (!PatoDataModel::getInstance()->validateUser(strUsername, strPw))
        return false;

    //test if a user is authorized
    if (!PatoDataModel::getInstance()->validateUserProject(strUsername, strPw, strProj))
        return false;

    //this function will fill the fileKey vector with all file keys
    vector<StorageKey> fileKey;
    std::vector<std::string> fileContent;
    std::map<std::string, std::string>::iterator itMap;

    for( itMap = filesCheckIn.begin(); itMap != filesCheckIn.end(); itMap++ )
    {
        fileContent.push_back(itMap->second);
    }

    PatoFS::getInstance()->saveData(fileContent, fileKey);

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

    if (!PatoDataModel::getInstance()->checkIn(filePathKey, strProj, strUsername, msg))
        return false;

    return true;
}

bool PatoServerApi::showLog(QString project, QString username, QString password, QString& message, int version,
             std::map<std::string, std::string>& filesLog)
{
    string strUsername = username.toStdString();
    string strPw = password.toStdString();
    string strProj = project.toStdString();

    message = PatoDataModel::getInstance()->getLogMessage(version).c_str();

    return PatoDataModel::getInstance()->showLog(strUsername, strPw, strProj, version, filesLog );
}


