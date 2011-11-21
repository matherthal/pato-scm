/* 
 * File:   mergeCLI.cpp
 * Author: marapao
 * 
 * Created on November 9, 2011, 3:06 AM
 */

#include "mergeCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include <QString>
#include <QTextStream>

mergeCLI::mergeCLI() {
}

void mergeCLI::setWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString mergeCLI::getWorkspace() const {
    return workspace;
}

void mergeCLI::setRevision2(RevisionKey revision2) {
    this->revision2 = revision2;
}

RevisionKey mergeCLI::getRevision2() const {
    return revision2;
}

void mergeCLI::setPath2(QString path2) {
    this->path2 = path2;
}

QString mergeCLI::getPath2() const {
    return path2;
}

void mergeCLI::setRevision1(RevisionKey revision1) {
    this->revision1 = revision1;
}

RevisionKey mergeCLI::getRevision1() const {
    return revision1;
}

void mergeCLI::setPath1(QString path1) {
    this->path1 = path1;
}

QString mergeCLI::getPath1() const {
    return path1;
}

mergeCLI::mergeCLI(const mergeCLI& orig) {
}

mergeCLI::~mergeCLI() {
}

QList<QString> messageErrorMe(){
    QList<QString> error;

    error.append("Merge command is used to obtain diff and apply over one configuration.");
    error.append("Usage: pato merge --path1 PATH1 --revision1 REVISION1 --path2 PATH2 --revision2 REVISION2 --workspace WORKSPACE");

    return error;
}


void mergeCLI::command(int argc, char** argv){
    
 //treating cases that argc > 1

    QTextStream qout(stdout);

    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
    char* parameter;

    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--path1") == 0) {
            path1 = argv[i + 1];
            qout<<"path1 = "<< path1<<endl;
        } else if (strcmp(parameter, "--path2") == 0) {
            path2 = argv[i + 1];
            qout<<"path2 = "<< path2<<endl;
        } else if (strcmp(parameter, "--revision1") == 0) {
            revision1 = atoi(argv[i + 1]);
            qout<<"revision1 = "<< revision1<<endl;
        } else if (strcmp(parameter, "--revision2") == 0) {
            revision2 = atoi(argv[i + 1]);
            qout<<"revision2 = "<< revision2<<endl;
        } else if (strcmp(parameter, "--workspace") == 0) {
            workspace = argv[i + 1];
            qout<<"workspace = "<< workspace<<endl;
        } else {
            qout << "[ERROR] " << parameter << " don't exist." << endl;
        }
    }

    clientAPI = new PatoClientApi();

    try {
        clientAPI->merge(path1, revision1, path2, revision2, workspace);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorMe();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }
        //qout <<t.Message() << endl;
    }   
}
