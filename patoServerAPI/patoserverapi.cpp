#include "patoserverapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>
#include "../patoBase/patotypes.h"

PatoServerApi* PatoServerApi::patoServerApi = NULL;

PatoServerApi::PatoServerApi()
{

    dataModel = PatoDataModel::getInstance();
    storage = PatoFS::getInstance();
}

PatoServerApi* PatoServerApi::getInstance() {

    if (patoServerApi == NULL)
        patoServerApi = new PatoServerApi();

    return patoServerApi;
}

void PatoServerApi::destroyInstance() {

    if (patoServerApi != NULL) {
        delete patoServerApi;
        patoServerApi = NULL;
    }
}

map<string, string>* PatoServerApi::checkout(int revision, QString path, QString username, QString password) {

    //validating project
    if (!dataModel->validateProject(path.toStdString()))
        return NULL;

    //validating user
    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return NULL;

    //test if the user is authorized
    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return NULL;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    //this map will be filled with file names and file keys (hash code)
    map<string, StorageKey> filePath;

    //filePath is a map that contains file name and its keys (hash code)
    if (!dataModel->checkOut(strUsername, strPassword, strPath,revision, filePath))
            return NULL;

    //file key (hash code)
    vector<StorageKey> key;
    //files content
    vector<string> content;

    //this map contains file names and its content
    map<string, string>::iterator it;
    for ( it=filePath.begin() ; it != filePath.end(); it++ ) {

        //storaging in the vector all file keys
        key.push_back((*it).second);
    }

   //trying to storage dat
    if (!storage->loadData(key, content)) {

       //if an error occurs, return a null pointer
       return NULL;
   }

   vector<string>::iterator cit;
   for ( it = filePath.begin(), cit = content.begin() ; it != filePath.end(); it++, cit++ ) {

       //if success, store in a map the file name (first) and file content (second)
       file[(*it).first] = (*cit);
   }

   //return the map containing file name and file content
   return &file;

}

bool PatoServerApi::checkin(QString project, vector<string>& filePath, vector<string>& fileContent, QString username, QString password, QString message) {

    string msg = message.toStdString();
    string strUsername = username.toStdString();
    string strPw = password.toStdString();
    string strProj = project.toStdString();

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
    storage->saveData(fileContent, fileKey);

    //filling the map with file names (path) and keys to pass to checkIn function
    map<string, StorageKey> filePathKey;

    vector<string>::iterator itPath;
    vector<StorageKey>::iterator itKey;
    for (itPath = filePath.begin(), itKey = fileKey.begin() ; itPath != filePath.end(); ++itPath, ++itKey) {
        filePathKey[(*itPath)] = (*itKey);
    }

    if (!dataModel->checkIn(filePathKey, strProj, strUsername, msg))
        return false;

    return true;
}


