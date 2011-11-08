#include "patoclientapi.h"
#include "PatoClientException.h"
//#include "../patoWorkspace/patoworkspace.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QDebug>
using namespace std;

PatoClientApi::PatoClientApi() {
//    this->pworkSpace = new PatoWorkspace;
}

//void PatoClientApi::setPworkSpace(PatoWorkspace pworkSpace) {
//    this->pworkSpace = pworkSpace;
//}
//
//PatoWorkspace PatoClientApi::getPworkSpace() const {
//    return pworkSpace;
//}

void PatoClientApi::checkout(int revision, QString address, QString username, QString password, QString workspace) throw(PatoClientException){

    if (revision < -1) {
        throw (PatoClientException("Invalid revision number." ));
    } else if (address == "") {
        throw (PatoClientException("The checkout command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The checkout command needs an username." ));
    } else if (password == "") {
        throw (PatoClientException("The checkout command needs a password."));
    } else if (workspace == "") {
        throw (PatoClientException("The checkout command needs a workspace."));
    }

}

void PatoClientApi::checkin(QString address, QString username, QString password, QString workspace) throw(PatoClientException){


    if (address == "") {
        throw (PatoClientException("The checkin command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The checkin command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkin command needs a password."));
        return;
    } else if (workspace == "") {
        throw (PatoClientException("The checkin command needs a workspace."));
        return;
    }

}

void PatoClientApi::add(QString workspace, QList<QString> files) throw (PatoClientException) {

    if (workspace == "") {
        throw (PatoClientException("The add command needs a workspace."));
    } else if (files.isEmpty()) {
        throw (PatoClientException("The add command needs at least one file to add."));
        return;
    }

    
//    for (int i = 0; i < files.size(); ++i) {
//        qout<<files.at(i)<<endl;
////        pworkSpace.add(workspace, files.at(i));
//
//    }

}

void PatoClientApi::status(QString workspace) throw(PatoClientException) {

    if (workspace == "") {
        throw (PatoClientException("The status command needs a workspace."));
        return;
    }

}

void PatoClientApi::update(QString revision, QString address, QString username, QString password, QString workspace) throw(PatoClientException)  {



    bool* conversao;
    int revisionInt = revision.toInt(conversao, 10);



    if (revision == revision.null) {
        throw (PatoClientException("revision is null!!!"));
    }

    if (revisionInt < -1) {
        throw (PatoClientException("Invalid revision number."));
    } else if (address == "") {
        throw (PatoClientException("The update command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The update command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The update command needs a password."));
    } else if (workspace == "") {
        throw (PatoClientException("The update command needs a workspace."));
    }

}

void PatoClientApi::merge(QString path1, int revision1, QString path2, int revision2, QString workspace) throw(PatoClientException) {
    if (path1 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (workspace == "") {
        throw (PatoClientException("The merge command needs a workspace."));
    } else if (revision1 >= 0) {
        throw (PatoClientException("The merge command needs a revision."));
    } else if (revision2 >= 0) {
        throw (PatoClientException("The merge command needs a revision."));
    }

}

void PatoClientApi::diff(QString path1, int revision1, QString path2, int revision2) throw(PatoClientException) {

      if (path1 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (revision1 >= 0) {
        throw (PatoClientException("The diff command needs a revision."));
    } else if (revision2 >= 0) {
        throw (PatoClientException("The diff command needs a revision."));
    }

}