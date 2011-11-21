/* 
 * File:   checkin.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 9:02 PM
 */

#include <QtCore/QString>
#include "checkinCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include <string.h>
#include <iostream>
#include <QTextStream>
using namespace std;

checkinCLI::checkinCLI() {

    address = "";
    username = "";
    password = "";
    workspace = "";
}

QList<QString> messageErrorCI(){
    QList<QString> error;

    error.append("Checkin command is used to send changes from your workcopy to the repository.");
    error.append("Usage: pato checkin --username USERNAME --password PASSWORD [--workspace WORKSPACE]");

    return error;
}


void checkinCLI::command(int argc, char** argv) {
    //treating cases that argc > 1

    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    char* parameter;
    QTextStream qout(stdout);
    
    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--username") == 0) {
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

    try {
        clientAPI->checkin(address, username, password, workspace);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorCI();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }

        //qout << t.Message() << endl;
    }

}

void checkinCLI::setPassword(QString password) {
    this->password = password;
}

QString checkinCLI::getPassword() const {
    return password;
}

void checkinCLI::setUsername(QString username) {
    this->username = username;
}

QString checkinCLI::getUsername() const {
    return username;
}

void checkinCLI::setAddress(QString address) {
    this->address = address;
}

QString checkinCLI::getAddress() const {
    return address;
}

void checkinCLI::setWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString checkinCLI::getWorkspace() const {
    return workspace;
}

checkinCLI::checkinCLI(const checkinCLI& orig) {
}

checkinCLI::~checkinCLI() {
}

