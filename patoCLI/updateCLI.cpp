/* 
 * File:   updateCLI.cpp
 * Author: marapao
 * 
 * Created on October 7, 2011, 10:40 AM
 */

#include "updateCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include<stdlib.h>
#include<iostream>
#include<QtCore/QString>
#include<QtCore/QTextStream>
using namespace std;

updateCLI::updateCLI() {
}

updateCLI::updateCLI(const updateCLI& orig) {
}

updateCLI::~updateCLI() {
}

void updateCLI::command(int argc, char** argv) {
    QString parameter;
    PatoClientApi* clientAPI;

    QTextStream qout(stdout);
    
    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (parameter == "--revision") {
            revision = argv[i + 1];
        } else if (parameter == "--username") {
            username = argv[i + 1];
        } else if (parameter == "--password") {
            password = argv[i + 1];
        } else if (parameter == "--address") {
            address = argv[i + 1];
        } else if (parameter == "--workspace") {
            workspace = argv[i + 1];
        } else {
            qout << "[ERROR] " << parameter << " don't exist." << endl;
            return;
        }
    }

    clientAPI = new PatoClientApi();

    clientAPI->update(revision, address, username, password, workspace);
}

void updateCLI::SetAddress(QString address) {
    this->address = address;
}

QString updateCLI::GetAddress() const {
    return address;
}

void updateCLI::SetPassword(QString password) {
    this->password = password;
}

QString updateCLI::GetPassword() const {
    return password;
}

void updateCLI::SetUsername(QString username) {
    this->username = username;
}

QString updateCLI::GetUsername() const {
    return username;
}

void updateCLI::SetRevision(QString revision) {
    this->revision = revision;
}

QString updateCLI::GetRevision() const {
    return revision;
}

void updateCLI::SetWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString updateCLI::GetWorkspace() const {
    return workspace;
}

