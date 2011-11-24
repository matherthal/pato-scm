/* 
 * File:   checkout.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:19 PM
 */

#include "checkoutCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include<stdlib.h>
#include <string.h>
#include<iostream>
#include<QtCore/QTextStream>
using namespace std;

QList<QString> messageErrorCO(){
    QList<QString> error;

    error.append("Checkout command is used to obtain one configuration from a repository.");
    error.append("Usage: pato checkout --address ADDRESS --username USERNAME --password PASSWORD [--revision REVISION][--workspace WORKSPACE]");

    return error;
}


void checkoutCLI::command(int argc, char** argv) {
    //treating cases that argc > 1

    QTextStream qout(stdout);

    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    char* parameter;

    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--revision") == 0) {
            revision = atoi(argv[i + 1]);
        } else if (strcmp(parameter, "--username") == 0) {
            username = argv[i + 1];
        } else if (strcmp(parameter, "--password") == 0) {
            password = argv[i + 1];
        } else if (strcmp(parameter, "--address") == 0) {
            address = argv[i + 1];
        } else if (strcmp(parameter, "--workspace") == 0) {
            workspace = argv[i + 1];
        } else {
            cout << "[ERROR] " << parameter << " don't exist." << endl;
            return;
        }
    }

    clientAPI = new PatoClientApi();

    try {
        clientAPI->checkout(revision, address, username, password, workspace);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorCO();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }

        //qout <<t.Message() << endl;
    }



}

void checkoutCLI::setPassword(QString password) {
    this->password = password;
}

QString checkoutCLI::getPassword() const {
    return password;
}

void checkoutCLI::setUsername(QString username) {
    this->username = username;
}

QString checkoutCLI::getUsername() const {
    return username;
}

void checkoutCLI::setAddress(QString address) {
    this->address = address;
}

QString checkoutCLI::getAddress() const {
    return address;
}

void checkoutCLI::setWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString checkoutCLI::getWorkspace() const {
    return workspace;
}

void checkoutCLI::setRevision(RevisionKey  revision) {
    this->revision = revision;
}

RevisionKey  checkoutCLI::getRevision() const {
    return revision;
}

checkoutCLI::checkoutCLI() {
    revision = -1;
    workspace = "";
    username = "";
    password = "";
    address = "";

}

checkoutCLI::checkoutCLI(const checkoutCLI& orig) {
}

checkoutCLI::~checkoutCLI() {
}

