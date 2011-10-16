/* 
 * File:   addCLI.cpp
 * Author: marapao
 * 
 * Created on October 7, 2011, 10:26 AM
 */

#include "addCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include<iostream>
#include<QtCore/QTextStream>
using namespace std;

addCLI::addCLI() {
}

addCLI::addCLI(const addCLI& orig) {
}

addCLI::~addCLI() {
}

void addCLI::command(int argc, char** argv) {
    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    QString parameter;
    
    QTextStream qout(stdout);
    
    for (int i = 2; i < argc; ) {
        parameter = argv[i];

        
        if (parameter == "--workspace") {
            workspace = argv[i + 1];
            i += 2;
        }else {
            qout << "[ERROR] " << parameter << " don't exist." << endl;
            return;
        }
        
        for(; i < argc; i++){
            QString aux = argv[i];
            files.append(aux);
        }
    }


    clientAPI->add(workspace, files);

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