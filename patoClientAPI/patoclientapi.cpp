#include "patoclientapi.h"
#include "../patoBase/patotypes.h"
#include "../patoWorkspace/patoworkspace.h"
#include "../patoServerAPI/patoserverapi.h"
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

QString PatoClientApi::init(QString repoName, QString username, QString password)
{
    QString repoAddress = "http://hardcoded.com/" + repoName;
    QStringList files;
    RevisionKey revision;

    PatoServerApi *serverApi = PatoServerApi::getInstance();
    bool succeded = serverApi->createProject(repoName);
    if (!succeded)
        return "";

    serverApi->createUser(username, username, password);
    succeded = serverApi->addUserProject(username, repoName);
    if (!succeded)
        return "";

    PatoWorkspace *workspace = PatoWorkspace::instance();
    succeded = workspace->create(repoName, files, repoAddress, revision);
    if (!succeded)
        return "";

    return repoAddress;
}

QList<checkoutOutput> PatoClientApi::checkout(RevisionKey revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    std::map<std::string, std::string> mapp;
    QList<checkoutOutput> output;
    if (address == "") {
        throw (PatoClientException("The checkout command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The checkout command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkout command needs a password."));
    }

    PatoVersionReturn versionParams;// = communication->checkout( address, username, password, revision);

    PatoWorkspace* work = PatoWorkspace::instance();
    PatoServerApi* server = PatoServerApi::getInstance();

    if ( PatoWorkspace::exists(workspace) )
    {
        work->cleanCopy( versionParams, false);
    }
    else
    {
        work->create( versionParams );
    }

    server->checkOut(address, username, password, revision, mapp);

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

QList< PatoFileStatus > PatoClientApi::checkin(QString address, QString username, QString password, QString workspace) throw (PatoClientException)
{
    if (username == "") {
        throw (PatoClientException("The checkin command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkin command needs a password."));
    }

    PatoWorkspace* work = PatoWorkspace::instance();
    PatoChangeSet myChanges = work->changes();

    //RevisionKey newRev = communication->checkin(address, username, password, myChanges);
    //work->setRevision( newRev ); //set new revision as commiting.
    return myChanges.status();
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

    work->setPath(workspace);

    if (workspace == "")
    {
        throw (PatoClientException("The status command needs a workspace."));
    }

   return work->status();
}

QList< PatoFileStatus > PatoClientApi::update(RevisionKey revision, QString address, QString username, QString password, QString workspace, bool ignoreLocalChanges) throw (PatoClientException) {


    QList<updateOutput> output;


    if (address == "") {
        throw (PatoClientException("The update command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The update command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The update command needs a password."));
    }

    PatoWorkspace* work = PatoWorkspace::instance();
    PatoChangeSet changes;// = communication->getChangeSet( work->revision(), revision );
    work->update( changes, ignoreLocalChanges );

    return changes.status();
}

void PatoClientApi::merge(QString path1, RevisionKey  revision1, QString path2, RevisionKey revision2, QString workspace) throw (PatoClientException) {
    if (path1 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (workspace == "") {
        throw (PatoClientException("The merge command needs a workspace."));
    } else if (revision1 < -1 ) {
        throw (PatoClientException("The merge command needs a revision."));
    } else if (revision2 < -1) {
        throw (PatoClientException("The merge command needs a revision."));
    }
}

void PatoClientApi::diff(QString path1, RevisionKey  revision1, QString path2, RevisionKey  revision2) throw (PatoClientException) {


    if (path1 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (revision1 < -1) {
        throw (PatoClientException("The diff command needs a revision."));
    } else if (revision2 < -1) {
        throw (PatoClientException("The diff command needs a revision."));
    }
}
