#ifndef PATOWORKSPACE_H
#define PATOWORKSPACE_H

#include <QList>
#include "PatoWorkspace_global.h"
#include "../patoBase/patotypes.h"
#include "../patoAlgorithms/diff.h"

enum MetadataType
{
    META_ADDED = 0x00000001,
    META_CONTROL = 0x00000002,
    META_REMOVED = 0x00000004,
    META_ALL = 0xFFFFFFFF
};

class PATOWORKSPACESHARED_EXPORT PatoWorkspace
{

public://STATICS
    static PatoWorkspace* instance();
    static void free();

    static bool exists( QString path );

public:
    //////////////PRIMEIRA FASE//////////////////////
    bool setPath(QString,bool createDir = false); //set workspace directory

    bool clearWorkspace();
    bool makeBackup();

    bool create(PatoVersionReturn params);
    bool create( QString sourceDir, QStringList files, QString repoAddress, RevisionKey revision); //create an initial workspace

    bool cleanCopy(PatoVersionReturn params, bool backup = false);
    bool cleanCopy( QString sourceDir, QStringList files, QString repoAddress, RevisionKey revision, bool backup = false);

    bool update( PatoChangeSet changeSet,  bool clear ); //apply a changeset
    bool setRevision( RevisionKey revision, bool commiting = true ); //update revision number
    QList< PatoFileStatus > add( QString sourceDir, QStringList path ); //add files and/or directories
    QString defaultRepositoryAddress() const; // return the source repository
    RevisionKey revision() const; //get current revision
    QList< PatoFileStatus > status(PatoFileStatus::FileStatus = PatoFileStatus::ALL) const; // return a list of file status
    PatoChangeSet changes() const; // return a list of file status
    /////////////////////////////////////////////////

    //////////////SEGUNDA FASE///////////////////////
    void revert(QStringList files = QStringList());
    void remove(QStringList files);
    void copy(/*originalPath, destinationPath*/);
    /////////////////////////////////////////////////

    QString getLastError() const;
    bool isReady() const;

private:
    PatoWorkspace();
    virtual ~PatoWorkspace();

    void writeMetadata(MetadataType = META_ALL);
    void readMetadata(MetadataType = META_ALL);

    void copyRevision(RevisionKey) const;
    void removeRevision(RevisionKey) const;
    QString backupPath(RevisionKey) const;

    QString metaFilePath(MetadataType, bool fullPath = false) const;


    QByteArray toByteArray(Diff&) const;

private:
    static PatoWorkspace* sigleWorkspace;

    QString workPath;
    QString defaultPath;
    RevisionKey revKey;

    QStringList versionedFiles;
    QStringList removedFiles;
    QStringList addedFiles;

    QDateTime timestamp;


    QString lastError;


    bool ready;
};

#endif // PATOWORKSPACE_H
