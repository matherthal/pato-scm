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
    void setPath(QString); //set workspace directory
    void create( QList< QFile > files, QString repoAddress, RevisionKey revision); //create an initial workspace
    void update( PatoChangeSet changeSet, RevisionKey revision); //apply a changeset and update revision number
    void setRepositoryRevision( RevisionKey revision, bool commiting = true ); //update revision number
    void add( QList < QString > path ); //add files and/or directories
    QString defaultRepositoryAddress(); // return the source repository
    QList< PatoFileStatus > status(); // return a list of file status
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

    void writeMetaData();
    void readMetaData();

private:
    static PatoWorkspace* sigleWorkspace;

    QString workPath;
    QString defaultPath;
    RevisionKey revKey;

};

#endif // PATOWORKSPACE_H
