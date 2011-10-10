#ifndef PATOWORKSPACE_H
#define PATOWORKSPACE_H

#include <QList>
#include "PatoWorkspace_global.h"

#include "../patoBase/patotypes.h"


class PATOWORKSPACESHARED_EXPORT PatoWorkspace
{

public://STATICS
    static PatoWorkspace* instance();
    static void free();

public:
    //////////////PRIMEIRA FASE//////////////////////
    bool setPath(QString); //set workspace directory
    void create( QStringList files, QString repoAddress, RevisionKey revision); //create an initial workspace
    void update( PatoChangeSet changeSet, RevisionKey revision); //apply a changeset and update revision number
    void setRevision( RevisionKey revision, bool commiting = true ); //update revision number
    void add( QStringList path ); //add files and/or directories
    QString defaultRepositoryAddress() const; // return the source repository
    RevisionKey revision() const; //get current revision
    QList< PatoFileStatus > status() const; // return a list of file status
    /////////////////////////////////////////////////

    //////////////SEGUNDA FASE///////////////////////
    void revert(/*path*/);
    void currentFile(/*path*/);// File
    void originalFile(/*path*/);// File
    void remove(/*path*/);
    void copy(/*originalPath, destinationPath*/);
    /////////////////////////////////////////////////

private:
    PatoWorkspace();
    virtual ~PatoWorkspace();

    void writeMetadata();
    void readMetadata();

private:
    static PatoWorkspace* sigleWorkspace;

    QString workPath;
    QString defaultPath;
    RevisionKey revKey;

    QStringList versionedFiles;
    QStringList removedFiles;
    QStringList addedFiles;

    QDateTime timespamp;
};

#endif // PATOWORKSPACE_H
