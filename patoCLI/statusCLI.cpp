/* 
 * File:   statusCLI.cpp
 * Author: marapao
 * 
 * Created on October 10, 2011, 7:26 PM
 */

#include "statusCLI.h"
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
            qout << "[ERROR] " << parameter << " don't exist." << endl;
            return;
        }

    }


    clientAPI->status(workspace);

}
