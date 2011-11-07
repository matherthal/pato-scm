#include "patoserverapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>



PatoServerApi::PatoServerApi()
{

    dataModel = PatoDataModel::getInstance();
}

void PatoServerApi::checkout(int revision, QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    //last parameter is incompatible!
    //TODO out << dataModel->checkOut(strUsername,strPassword,strPath,revision,filePath) << endl;
}

void PatoServerApi::checkin(QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return;

    string message = NULL;
    string strUsername = username.toStdString();
    string strPath = path.toStdString();

    //first parameter is incompatible!
    //TODO cout << dataModel->checkIn(filePath,strPath,strUsername,message) << endl;
}


