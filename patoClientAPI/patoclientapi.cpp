#include "patoclientapi.h"
#include "../patoBase/patotypes.h"
#include "../patoWorkspace/patoworkspace.h"
#include "PatoClientException.h"
#include "statusOutput.h"
#include "updateOutput.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QString>
#include<QList>
#include<QTextStream>
using namespace std;

PatoClientApi::PatoClientApi() {
}

QList<checkoutOutput> PatoClientApi::checkout(RevisionKey revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    QList<checkoutOutput> output;

    //if (revision == "") {
    //        throw (PatoClientException("Invalid revision number."));
    //    } else 
    if (address == "") {
        throw (PatoClientException("The checkout command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The checkout command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkout command needs a password."));
    }

    return output;
}

QList<logOutput> PatoClientApi::log(QString address, QString username, QString password, RevisionKey initialRevision, RevisionKey finalRevision) throw (PatoClientException) {

    QList<logOutput> output;


    if (username == "") {
        throw (PatoClientException("The log command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The log command needs a password."));
        //    } else if (initialInt < -1) {
        //        throw (PatoClientException("Invalid initial revision number."));
    }
    /*else if (finalInt < -1 || finalInt < initialInt) {
        throw (PatoClientException("Invalid initial revision number."));
    }
    */
    return output;
}

QList<checkoutOutput> PatoClientApi::checkin(QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    QList<checkoutOutput> output;

    if (username == "") {
        throw (PatoClientException("The checkin command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkin command needs a password."));
    }

    return output;
}

QList< PatoFileStatus > PatoClientApi::add(QString workspace, QStringList files) throw (PatoClientException)
{
    PatoWorkspace* work = PatoWorkspace::instance();

    if (workspace == "") {
        throw (PatoClientException("The add command needs a workspace."));
    } else if (files.isEmpty()) {
        throw (PatoClientException("The add command needs at least one file to add."));
    }


   return work->add(workspace, files);
}

QList< PatoFileStatus > PatoClientApi::status(QString workspace) throw (PatoClientException) {

    PatoWorkspace* work = PatoWorkspace::instance();

    if (workspace == "")
    {
        throw (PatoClientException("The status command needs a workspace."));
    }

   return work->status();
}

QList<updateOutput> PatoClientApi::update(RevisionKey revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {


    QList<updateOutput> output;


    if (address == "") {
        throw (PatoClientException("The update command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The update command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The update command needs a password."));
    }
    

    return output;
}

void PatoClientApi::merge(QString path1, RevisionKey  revision1, QString path2, RevisionKey revision2, QString workspace) throw (PatoClientException) {
    if (path1 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (workspace == "") {
        throw (PatoClientException("The merge command needs a workspace."));
    } else if (revision1 == "") {
        throw (PatoClientException("The merge command needs a revision."));
    } else if (revision2 == "") {
        throw (PatoClientException("The merge command needs a revision."));
    }

}

void PatoClientApi::diff(QString path1, RevisionKey  revision1, QString path2, RevisionKey  revision2) throw (PatoClientException) {


    if (path1 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (revision1 == "") {
        throw (PatoClientException("The diff command needs a revision."));
    } else if (revision2 == "") {
        throw (PatoClientException("The diff command needs a revision."));
    }


}
