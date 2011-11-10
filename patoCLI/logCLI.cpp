/* 
 * File:   logCLI.cpp
 * Author: marapao
 * 
 * Created on November 9, 2011, 1:16 AM
 */

#include "logCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include <QList>
#include <QTextStream>


logCLI::logCLI() {
}

void logCLI::setQuiet(bool quiet) {
    this->quiet = quiet;
}

bool logCLI::isQuiet() const {
    return quiet;
}

void logCLI::setVerbose(bool verbose) {
    this->verbose = verbose;
}

bool logCLI::isVerbose() const {
    return verbose;
}

void logCLI::setPath(QString path) {
    this->path = path;
}

QString logCLI::getPath() const {
    return path;
}

void logCLI::setFinalRevision(QString finalRevision) {
    this->finalRevision = finalRevision;
}

QString logCLI::getFinalRevision() const {
    return finalRevision;
}

void logCLI::setInitialRevision(QString initialRevision) {
    this->initialRevision = initialRevision;
}

QString logCLI::getInitialRevision() const {
    return initialRevision;
}

void logCLI::setAddress(QString address) {
    this->address = address;
}

QString logCLI::getAddress() const {
    return address;
}

void logCLI::setPassword(QString password) {
    this->password = password;
}

QString logCLI::getPassword() const {
    return password;
}

void logCLI::setUsername(QString username) {
    this->username = username;
}

QString logCLI::getUsername() const {
    return username;
}

logCLI::logCLI(const logCLI& orig) {
}

logCLI::~logCLI() {
}

QList<QString> messageErrorLog(){
    QList<QString> error;

    error.append("Log command shows history of artifacts.");
    error.append("Usage: pato log --username USERNAME --password PASSWORD [--initialRevision initial] [--finalRevision final] [--address ADDRESS] ");

    return error;
}


void logCLI::command(int argc, char** argv) {
    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    QString parameter;

    QTextStream qout(stdout);


    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];


        if (parameter == "--address") {
            address = argv[i + 1];
        } else if (parameter == "--username") {
            username = argv[i + 1];
        } 
        else if (parameter == "--password") {
            password = argv[i + 1];
        } 
        else if (parameter == "--initialRevision") {
            initialRevision = argv[i + 1];
        } 
        else if (parameter == "--finalRevision") {
            finalRevision = argv[i + 1];
        } 
    }

    try {
        clientAPI->log(address, username, password, initialRevision, finalRevision);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorLog();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }

        //qout << t.Message() << endl;
    }

}
