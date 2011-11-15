/* 
 * File:   diffCLI.cpp
 * Author: marapao
 * 
 * Created on November 9, 2011, 3:06 AM
 */

#include "diffCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include <QTextStream>

diffCLI::diffCLI() {
}

void diffCLI::setRevision2(RevisionKey revision2) {
    this->revision2 = revision2;
}

RevisionKey diffCLI::getRevision2() const {
    return revision2;
}

void diffCLI::setPath2(QString path2) {
    this->path2 = path2;
}

QString diffCLI::getPath2() const {
    return path2;
}

void diffCLI::setRevision1(RevisionKey revision1) {
    this->revision1 = revision1;
}

RevisionKey diffCLI::getRevision1() const {
    return revision1;
}

void diffCLI::setPath1(QString path1) {
    this->path1 = path1;
}

QString diffCLI::getPath1() const {
    return path1;
}

diffCLI::diffCLI(const diffCLI& orig) {
}

diffCLI::~diffCLI() {
}

QList<QString> messageErrorDi(){
    QList<QString> error;

    error.append("Diff command is used to obtain differences between configurations.");
    error.append("Usage: pato diff --path1 PATH1 --revision1 REVISION1 --path2 PATH2 --revision2 REVISION2 ");

    return error;
}


void diffCLI::command(int argc, char** argv){
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
            revision1 = argv[i + 1];
            qout<<"revision1 = "<< revision1<<endl;
        } else if (strcmp(parameter, "--revision2") == 0) {
            revision2 = argv[i + 1];
            qout<<"revision2 = "<< revision2<<endl;
        } else {
            qout << "[ERROR] " << parameter << " don't exist." << endl;
        }
    }

    clientAPI = new PatoClientApi();

    try {
        clientAPI->diff(path1, revision1, path2, revision2);
    } catch (PatoClientException& t) {
        QList<QString> ls = messageErrorDi();
        for(int i = 0; i < ls.size(); i++){
            qout<<ls.at(i)<<endl;
        }
        //qout <<t.Message() << endl;
    }
}

