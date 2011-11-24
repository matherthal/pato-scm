/* 
 * File:   statusCLI.cpp
 * Author: marapao
 * 
 * Created on October 10, 2011, 7:26 PM
 */

#include "statusCLI.h"
#include "utils.h"
#include "../patoClientAPI/patoclientapi.h"
#include<iostream>
#include<QtCore/QString>
#include<QtCore/QTextStream>
using namespace std;

statusCLI::statusCLI() {
}

statusCLI::statusCLI(const statusCLI& orig) {
}

statusCLI::~statusCLI() {
}

void statusCLI::SetWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString statusCLI::GetWorkspace() const {
    return workspace;
}

QList<QString> messageErrorST(){
    QList<QString> error;

    error.append("Status command shows the files and directories situation.");
    error.append("These situations can be:");
    error.append(" A  added");
    error.append(" M  modified");
    error.append(" R  removed");
    error.append(" C  clean");
    error.append(" U  unversioned");
    error.append(" ");
    error.append("Usage: pato status [--workspace WORKSPACE]");

    return error;
}


void statusCLI::command(int argc, char** argv) {
    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    QString parameter;

    QTextStream qout(stdout);


    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];


        if (parameter == "--workspace") {
            workspace = argv[i + 1];
        } else {
            workspace = utils::returnPath(argc, argv);
        }

    }

    try {
        clientAPI->status(workspace);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorST();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }

        //qout << t.Message() << endl;
    }

}
