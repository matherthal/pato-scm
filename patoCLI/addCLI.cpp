/* 
 * File:   addCLI.cpp
 * Author: marapao
 * 
 * Created on October 7, 2011, 10:26 AM
 */

#include "addCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include "../patoClientAPI/PatoClientException.h"
#include "utils.h"
#include<iostream>
#include<QtCore/QTextStream>
using namespace std;

addCLI::addCLI() {
}

addCLI::addCLI(const addCLI& orig) {
}

addCLI::~addCLI() {
}

QList<QString> messageError(){
    QList<QString> error;

    error.append("Add command is used to include artifactcs or directories under version control.");
    error.append("Usage: pato add PATH....");

    return error;
}

void addCLI::command(int argc, char** argv) {
    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    QString parameter;

    QTextStream qout(stdout);

    for (int i = 2; i < argc;) {
        parameter = argv[i];

        if (parameter == "--workspace") {
            workspace = argv[i + 1];
            i += 2;
        } else {
            workspace = utils::returnPath(argc, argv);
            qout << workspace << endl;
        }

        for (; i < argc; i++) {
            QString aux = argv[i];
            files.append(aux);
        }
    }
    try {
        clientAPI->add(workspace, files);
    } catch (PatoClientException& t) {

        QList<QString> ls = messageError();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }


    }
}

void addCLI::setFiles(QList<QString> files) {
    this->files = files;
}

QList<QString> addCLI::getFiles() const {
    return files;
}

void addCLI::setWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString addCLI::getWorkspace() const {
    return workspace;
}
