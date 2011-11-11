/* 
 * File:   logCLI.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 4:35 PM
 */

#include "logCLI.h"
#include <QList>
#include"../patoBase/patotypes.h"
#include"../patoClientAPI/patoclientapi.h"

logCLI::logCLI() {
}

logCLI::logCLI(const logCLI& orig) {
}

logCLI::~logCLI() {
}

void logCLI::command(int argc, char** argv) {
    //treating cases that argc > 1

    QTextStream qout(stdout);

    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    char* parameter;


    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--initialRevision") == 0) {
            initialRevision = atoi(argv[i + 1]);
        } else if (strcmp(parameter, "--finalRevision") == 0) {
            finalRevision = argv[i + 1];
        } else if (strcmp(parameter, "--username") == 0) {
            username = argv[i + 1];
        } else if (strcmp(parameter, "--password") == 0) {
            password = argv[i + 1];
        } else if (strcmp(parameter, "--address") == 0) {
            address = argv[i + 1];
        } else {
            qout << "[ERROR] " << parameter << " don't exist." << endl;
            return;
        }
    }

    try {
        clientAPI->log(address, username, password, initialRevision, finalRevision);
    } catch (PatoClientException& t) {
        qout <<t.Message() << endl;
    }
}

void logCLI::SetPassword(QString password) {
    this->password = password;
}

QString logCLI::GetPassword() const {
    return password;
}

void logCLI::SetUsername(QString username) {
    this->username = username;
}

QString logCLI::GetUsername() const {
    return username;
}

void logCLI::SetFinalRevision(RevisionKey finalRevision) {
    this->finalRevision = finalRevision;
}

RevisionKey logCLI::GetFinalRevision() const {
    return finalRevision;
}

void logCLI::SetInitialRevision(RevisionKey initialRevision) {
    this->initialRevision = initialRevision;
}

RevisionKey logCLI::GetInitialRevision() const {
    return initialRevision;
}

void logCLI::SetAddress(QString address) {
    this->address = address;
}

QString logCLI::GetAddress() const {
    return address;
}

void logCLI::SetParameters(QList<QString> parameters) {
    this->parameters = parameters;
}

QList<QString> logCLI::GetParameters() const {
    return parameters;
}
