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

QString PatoClientApi::init(QString repoName, QString username, QString password, QString workspace)
{

    if (repoName == "") {
        throw (PatoClientException("The init command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The init command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The init command needs a password."));
    }
    else if (workspace == "") {
            throw (PatoClientException("The init command needs a password."));
     }
    qDebug()<<"create"<<endl;

    QString repoAddress = "http://hardcoded.com/" + repoName;
    QStringList files;
    RevisionKey revision;

    PatoServerApi *serverApi = PatoServerApi::getInstance();

    bool succeded;
    if(!serverApi->validateProject(repoName)){
        succeded = serverApi->createProject(repoName);
        if (!succeded)
            return "";
    }

    if(!serverApi->validateUser(username, password))
        serverApi->createUser(username, username, password);

    //if(!serverApi->validateUserProject(username, repoName)){
    succeded = serverApi->addUserProject(username, repoName);
    if (!succeded){
        cout<<"1"<<endl;
        throw (PatoClientException("Problem to create project and add user"));
    }
    //}

    PatoWorkspace* work;
    work = PatoWorkspace::instance();
    qDebug()<<"create "<<workspace<<endl;
    work->setPath(workspace, true);
    succeded = work->create(workspace, files, repoAddress, revision);
    if (!succeded){
        qDebug()<<work->getLastError()<<endl;
        throw (PatoClientException("Problem to create project and add user"));
    }
    return repoAddress;
}

QList<checkoutOutput> PatoClientApi::checkout(RevisionKey revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    std::map<std::string, std::string> mapp;
    bool success;


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


    success = server->checkOut(address, username, password, revision, mapp);

    if ( PatoWorkspace::exists(workspace) )
    {
        work->cleanCopy( versionParams, false);
    }
    else
    {
        work->create( versionParams );
    }





    return output;
}

QList<logOutput> PatoClientApi::log(QString address, QString username, QString password, RevisionKey initialRevision, RevisionKey finalRevision) throw (PatoClientException) {

    QList<logOutput> output;
    PatoLog log;
    PatoServerApi* server = PatoServerApi::getInstance();

    if (username == "") {
        throw (PatoClientException("The log command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The log command needs a password."));
    }



    server->showLog(address, username, password, initialRevision, log);



    return output;
}

QList< PatoFileStatus > PatoClientApi::checkin(QString address, QString username, QString password, QString workspace, QString message) throw (PatoClientException)
{
    PatoServerApi* server = PatoServerApi::getInstance();

    if (username == "") {
        throw (PatoClientException("The checkin command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkin command needs a password."));
    }

    PatoWorkspace* work = PatoWorkspace::instance();
    std::map<std::string, std::string> myChanges = work->changesToServer();


    if(server->checkIn(address, username, password, message, myChanges)){
        work->setRevision(work->revision() + 1);
    }

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

    work->setPath(workspace);

    return work->add(workspace, files);
}

void PatoClientApi::remove(QString workspace, QStringList files) throw (PatoClientException)
{
    PatoWorkspace* work = PatoWorkspace::instance();

    if (workspace == "") {
        throw (PatoClientException("The add command needs a workspace."));
    } else if (files.isEmpty()) {
        throw (PatoClientException("The add command needs at least one file to add."));
    }

    work->setPath(workspace);

    work->remove(files);

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
