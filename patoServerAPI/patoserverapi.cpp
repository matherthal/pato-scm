#include "patoserverapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>


PatoServerApi::PatoServerApi()
{

    dataModel = PatoDataModel::getInstance();
    storage = PatoFS::getInstance();
}

map<string, string>* PatoServerApi::checkout(int revision, QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return NULL;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return NULL;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return NULL;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    if (!dataModel->checkOut(strUsername,strPassword,strPath,revision,filePath))
            return NULL;

    vector<int> key;
    vector<string> content;

    map<string, int>::iterator it;
    for ( it=filePath.begin() ; it != filePath.end(); it++ ) {
        key.push_back((*it).second);
    }

   if (!storage->loadData(key, content))
       return NULL;

   vector<string>::iterator cit;
   for ( it = filePath.begin(), cit = content.begin() ; it != filePath.end(); it++, cit++ ) {

       file[(*it).first] = (*cit);
   }

   return &file;

}

bool PatoServerApi::checkin(QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return false;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return false;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return false;

    string message = NULL;
    string strUsername = username.toStdString();
    string strPath = path.toStdString();

    if (!dataModel->checkIn(filePath, strPath, strUsername,message))
        return false;

    return true;
}


