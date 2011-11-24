#include "patoworkspace.h"
#include <QDir>
#include "../patoBase/patofilestatus.h"
#include "../patoAlgorithms/diff.h"
#include "../patoBase/patoResourceAbstractFactory.h"
#include "../patoBase/ifile.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;

const QString cWorkspaceControlFolder = ".pato";
const QString cWorkspaceMetadata = "pato.md";
const QString cAddedMetadata = "added.md";
const QString cRemovedMetadata = "removed.md";



string toString( QString strfile )
{
    QString r;

    QFile file (strfile);

    if ( file.open( QFile::ReadOnly) )
    {
        QTextStream stream(&file);

        r = stream.readAll();
    }


    return r.toStdString();
}

QString getDir(QString str)
{
    str.replace('\\', '/');

    while( str[ str.length() - 1] != '/')
    {
        str.remove( str.length() - 1, 1);
    }
    return str;
}

void copyFile(QString path1, QString path2, QString file)
{
    QDir().mkpath(getDir(path2 + '/' + file));
    QFile(path1 + '/' + file).copy(path2 + '/' + file);
}

void removeDirectory(QString path)
{
    QDir dir( path );

    foreach (QString subDir, dir.entryList( QDir::Dirs | QDir::NoDotAndDotDot))
        removeDirectory(subDir);

    foreach ( QString file, dir.entryList( QDir::Files))
        QFile (QFileInfo( dir, file).absoluteFilePath()).remove();

    dir.rmdir(dir.absolutePath());
}

void copyDirectory(QString path1, QString path2)
{
    QDir dir( path1 );

    foreach (QString subDir, dir.entryList( QDir::Dirs | QDir::NoDotAndDotDot))
        copyDirectory(path1+"/"+subDir, path2+"/"+subDir);

    foreach ( QString file, dir.entryList( QDir::Files))
    {
        copyFile (path1,path2, file);
    }
}

void getAllFiles( QString path1, QList<QString>& list)
{
    QDir dir( path1 );

    foreach (QString subDir, dir.entryList( QDir::Dirs | QDir::NoDotAndDotDot))
        getAllFiles(path1+"/"+subDir, list);

    foreach ( QString file, dir.entryList( QDir::Files))
    {
        list << path1+"/"+file;
    }
}

PatoWorkspace* PatoWorkspace::instance()
{
    if (!sigleWorkspace)
        sigleWorkspace = new PatoWorkspace();

    return sigleWorkspace;
}

void PatoWorkspace::free()
{
    if (sigleWorkspace)
    {
        delete sigleWorkspace;
        sigleWorkspace = NULL;
    }
}

bool PatoWorkspace::exists( QString path )
{
    return QFile( QString("%1/%2/%3").arg(path).arg(cWorkspaceControlFolder).arg(cWorkspaceMetadata) ).exists();
}

PatoWorkspace::PatoWorkspace()
{
    ready = false;
}

PatoWorkspace::~PatoWorkspace()
{
}

//////////////PRIMEIRA FASE//////////////////////

bool PatoWorkspace::makeBackup()
{
    return true;
}

bool PatoWorkspace::clearWorkspace()
{
    return true;
}

bool PatoWorkspace::cleanCopy(PatoVersionReturn params,  bool backup)
{
    return cleanCopy(params.path, params.files, params.address, params.revision, backup);
}

bool PatoWorkspace::cleanCopy( QString sourceDir, QStringList files, QString repoAddress, RevisionKey revision, bool backup)
{
    if (backup)
    {
        makeBackup();
    }

    clearWorkspace();
    return create(sourceDir, files, repoAddress, revision);
}

bool PatoWorkspace::create(PatoVersionReturn params)
{
    return create(params.path, params.files, params.address, params.revision);
}

bool PatoWorkspace::create(QString sourceDir, QStringList files, QString repoAddress, RevisionKey revision )
{
    if ( workPath.isEmpty())
    {
        lastError = "Work path is Empty.";
        return false;
    }

    QDir().mkpath(workPath);

    QFile file( metaFilePath( META_CONTROL, true) );

    if ( file.exists() )
    {
        lastError = "Repository already created.";
        return false;
    }

    defaultPath = repoAddress;
    revKey  = revision;

    timestamp = QDateTime::currentDateTime();

    for (int i=0; i < files.size(); i++)
    {
        versionedFiles << files[i];
        copyFile(sourceDir, workPath, files[i] );
    }

    writeMetadata();

    copyRevision(revKey);

    ready = true;
    return true;
}

bool PatoWorkspace::setPath(QString directory, bool createDir)
{
    ready = false;
    workPath = directory;

    if(!QDir(directory).exists())
    {
        if (createDir)
            return QDir().mkpath(directory);

        lastError = "Directory doesn't exist";
    }

    QFile file( metaFilePath( META_CONTROL, true ));
    if ( (ready = file.exists()) )
    {
        readMetadata();

    }
    else
    {
        lastError = "The given directory does not contain a pato repository.";
        return false;
    }

    return true;
}

QList< PatoFileStatus > PatoWorkspace::add( QString sourceDir, QStringList paths )
{
    QList< PatoFileStatus > ret;

    for (int i = 0; i < paths.size(); i++)
    {
        if (!versionedFiles.contains( paths[i] ))
        {
            if (!addedFiles.contains(paths[i]))
                addedFiles.append(paths[i]);

            copyFile(sourceDir, workPath, paths[i] );

            ret << PatoFileStatus( paths[i], PatoFileStatus::ADDED);
        }
        else
        {
            ret << PatoFileStatus( paths[i], PatoFileStatus::VERSIONED);
        }
    }

    writeMetadata();

    return ret;
}

QList< PatoFileStatus > PatoWorkspace::status(PatoFileStatus::FileStatus statusFilter) const
{
    QList< PatoFileStatus > statusList;

    QList<QString> allFiles;
    getAllFiles(workPath,allFiles);

    QString ignoredPath = workPath + "/" + cWorkspaceControlFolder;

    foreach ( QString strFile, allFiles)
    {
        if ( strFile.indexOf( ignoredPath ) != 0 )
        {
            strFile.remove(0, (workPath + "/").length());

            int nV = versionedFiles.indexOf(strFile);
            if (nV != -1)
            {
                if (  QFile( workPath + "/" + versionedFiles[nV]).exists() )
                {
                    if ( (statusFilter & PatoFileStatus::MODIFIED) && (statusFilter & PatoFileStatus::CLEAN) )
                    {
                        Diff diff ( (workPath + "/" + versionedFiles[nV]).toStdString().c_str(),
                                    (backupPath(revKey) + versionedFiles[nV]).toStdString().c_str() );

                        if(diff.isEmpty())
                        {
                            if (statusFilter & PatoFileStatus::CLEAN)
                                statusList.append( PatoFileStatus( strFile, PatoFileStatus::CLEAN ) );
                        }
                        else
                        {
                            if (statusFilter & PatoFileStatus::MODIFIED)
                                statusList.append( PatoFileStatus( strFile, PatoFileStatus::MODIFIED ) );
                        }
                    }
                }
                else
                {
                    if ( statusFilter & PatoFileStatus::MISSING )
                    {
                        statusList.append( PatoFileStatus( strFile, PatoFileStatus::MISSING ) );
                    }
                }
            }
            else
            {
                int nR = removedFiles.indexOf(strFile);
                if (nR != -1)
                {
                    if ( statusFilter & PatoFileStatus::REMOVED )
                    {
                        statusList.append( PatoFileStatus( strFile, PatoFileStatus::REMOVED ) );
                    }
                }
                else
                {
                    int nA = addedFiles.indexOf(strFile);
                    if (nA != -1)
                    {
                        if ( statusFilter & PatoFileStatus::ADDED )
                        {
                            statusList.append( PatoFileStatus( strFile, PatoFileStatus::ADDED ) );
                        }
                    }
                    else
                    {
                        if ( statusFilter & PatoFileStatus::UNVERSIONED )
                        {
                            statusList.append( PatoFileStatus( strFile, PatoFileStatus::UNVERSIONED ) );
                        }
                    }
                }
            }
        }
    }

    return statusList;
}

bool PatoWorkspace::setRevision(RevisionKey revision,  bool commiting )
{
    qDebug() << QString("Old Revision: %1 -> New Revision: %2").arg(revKey).arg(revision);

    if (commiting)
    {
        versionedFiles << addedFiles; // added files are now versioned

        for ( int i=0; i < removedFiles.size(); i++ ) //removed files should be removed.
        {
            bool bRemoved = QFile( workPath + "/" + removedFiles[i]).remove();
            if (!bRemoved)
                qWarning() << QString("There was a problem removing the following file: %1").arg(removedFiles[i]);
        }
    }

    addedFiles.clear();
    removedFiles.clear();


    writeMetadata();


    if (commiting)
    {
        copyRevision(revision);
        removeRevision(revKey);
    }

    revKey  = revision;


    return true;
}

bool PatoWorkspace::update( PatoChangeSet changeSet, bool clear )
{
    PatoChangeSet localChanges = changes();

    if (!localChanges.isEmpty())
    {

    }
    else
    {
        Q_ASSERT (  changeSet.start() == revision() );
        copyDirectory( backupPath(revision()), backupPath(changeSet.end()) );
        //PatoAlgorithms::ApplyChangeSet( backupPath(changeSet.end()), changeSet); //a clean .end() version;
        //PatoAlgorithms::Merge( backupPath(changeSet.end()), changeSet); //a clean .end() version;
    }

    changeSet = changeSet; //PatoAlgorithms::ApplyChangeSet( workPath, changeSet);
    qWarning() << "Update workspace needs PatoAlgorithms::ApplyChangeSet( workPath, changeSet)";
    revKey  = changeSet.end();

    writeMetadata();

    return true;
}

RevisionKey PatoWorkspace::revision() const
{
    return revKey;
}

QString PatoWorkspace::defaultRepositoryAddress() const
{
    return defaultPath;
}
/////////////////////////////////////////////////


void PatoWorkspace::writeMetadata(MetadataType types)
{
    if (types & META_CONTROL)
    {
        QFile file( metaFilePath( META_CONTROL, true ) );
        if (file.open( QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream textStream(&file);

            textStream << revKey << endl;
            textStream << defaultPath << endl;
            textStream << timestamp.toString() << endl;

            for (int i=0; i < versionedFiles.size(); i++)
            {
                textStream << versionedFiles[i] << endl;// << versionedFiles;
            }

            file.close();
        }
        else
        {
            qDebug() << metaFilePath( META_CONTROL, true );
            qWarning() << "Cannot open " << cWorkspaceMetadata;
        }
    }

    if (types & META_ADDED)
    {
        QFile file( metaFilePath( META_ADDED, true ) );
        if (file.open( QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream textStream(&file);

            for (int i=0; i < addedFiles.size(); i++)
            {
                textStream << addedFiles[i] << endl;// << addedFiles;
            }

            file.close();
        }
        else
        {
            qDebug() << metaFilePath( META_ADDED, true );
            qWarning() << "Cannot open " << cAddedMetadata;
        }
    }

    if (types & META_REMOVED)
    {
        QFile file( metaFilePath( META_REMOVED, true ) );
        if (file.open( QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream textStream(&file);

            for (int i=0; i < removedFiles.size(); i++)
            {
                textStream << removedFiles[i] << endl;// << addedFiles;
            }

            file.close();
        }
        else
        {
            qDebug() << metaFilePath( META_REMOVED, true );
            qWarning() << "Cannot open " << cRemovedMetadata;
        }
    }
}

void PatoWorkspace::readMetadata(MetadataType types)
{
    if (types & META_CONTROL)
    {
        versionedFiles.clear();
        QFile file( metaFilePath( META_CONTROL, true ));
        if (file.open( QFile::ReadOnly))
        {
            QTextStream textStream(&file);
            revKey = textStream.readLine().toInt();
            defaultPath = textStream.readLine();
            timestamp.fromString( textStream.readLine() );

            while (!textStream.atEnd())
            {
                versionedFiles << textStream.readLine();
            }
        }
    }

    if (types & META_ADDED)
    {
        addedFiles.clear();
        QFile file( metaFilePath( META_ADDED, true ) );
        if (file.open( QFile::ReadOnly))
        {
            QTextStream textStream(&file);

            while (!textStream.atEnd())
            {
                addedFiles << textStream.readLine();
            }
        }
    }

    if (types & META_REMOVED)
    {
        removedFiles.clear();
        QFile file( metaFilePath( META_REMOVED, true ) );
        if (file.open( QFile::ReadOnly))
        {
            QTextStream textStream(&file);

            while (!textStream.atEnd())
            {
                removedFiles << textStream.readLine();
            }
        }
    }
}

 std::map<string,string> PatoWorkspace::changesToServer() const
 {
      std::map<string,string> ret;
     for (int i=0; i < versionedFiles.size(); i++)
     {
         Diff diff ( (workPath + "/" + versionedFiles[i]).toStdString().c_str(),
                     (backupPath(revKey) + versionedFiles[i]).toStdString().c_str() );

         if (!diff.isEmpty())
         {
             ret [ (defaultRepositoryAddress() + "/" + versionedFiles[i]).toStdString() ] = toString(workPath + "/" + versionedFiles[i]);
         }
     }

     for( int i=0; i < addedFiles.size(); i++)
     {
          ret [(defaultRepositoryAddress() + "/" + addedFiles[i]).toStdString()] = toString(workPath + "/" + addedFiles[i]);
     }

     for( int i=0; i < removedFiles.size(); i++)
     {
         ret [(defaultRepositoryAddress() + "/" + removedFiles[i]).toStdString()] = QString("").toStdString();
     }

     return ret;
 }

PatoChangeSet  PatoWorkspace::changes() const
{
    PatoChangeSet changeSet;

    for (int i=0; i < versionedFiles.size(); i++)
    {
        Diff diff ( (workPath + "/" + versionedFiles[i]).toStdString().c_str(),
                    (backupPath(revKey) + versionedFiles[i]).toStdString().c_str() );

        if (!diff.isEmpty())
        {
            changeSet.add( versionedFiles[i], PatoFileStatus::MODIFIED , toByteArray(diff) );
        }
    }

    for( int i=0; i < addedFiles.size(); i++)
    {
        changeSet.add( addedFiles[i], PatoFileStatus::ADDED, QByteArray());
    }

    for( int i=0; i < removedFiles.size(); i++)
    {
        changeSet.add(  removedFiles[i], PatoFileStatus::REMOVED, QByteArray());
    }

    return changeSet;
}

//////////////SEGUNDA FASE///////////////////////
void PatoWorkspace::revert(QStringList files)
{
    if (files.isEmpty())
    {
        for (int i=0; i < addedFiles.size(); i++)
        {
            QFile( workPath + "/" + addedFiles[i]).remove();
        }

        for (int i=0; i < versionedFiles.size(); i++)
        {
            QFile( workPath + "/" + versionedFiles[i]).remove();
            copyFile( backupPath(revKey), workPath, versionedFiles[i] );
        }

        //the meta files
        copyFile( backupPath(revKey), workPath, metaFilePath(META_CONTROL) );
        addedFiles.clear();
        removedFiles.clear();
    }
    else
    {
        for (int i=0; i < files.size(); i++)
        {
            QFile( workPath + "/" + files[i]).remove();
            copyFile( backupPath(revKey), workPath, files[i] );

            int index= removedFiles.indexOf(files[i]);
            if (  index != -1)
            {
                removedFiles.removeAt(index);
                versionedFiles << files[i];
            }
        }

        writeMetadata();
    }
}

void PatoWorkspace::remove(QStringList files)
{
    for (int i=0; i < files.size(); i++)
    {
        int index = versionedFiles.indexOf( files[i] );

        if ( index != -1 )
        {
            removedFiles << versionedFiles[index];
            versionedFiles.removeAt(index);
        }
        else
        {
            index = addedFiles.indexOf( files[i] );
            if ( index != -1 )
            {
                addedFiles.removeAt(index);
            }
        }
    }
    writeMetadata();
}

void PatoWorkspace::copy(/*originalPath, destinationPath*/)
{
}
/////////////////////////////////////////////////


QString PatoWorkspace::getLastError() const
{
    return lastError;
}

bool PatoWorkspace::isReady() const
{
    return ready;
}


void PatoWorkspace::copyRevision(RevisionKey key) const
{
    QString revPath = backupPath( key );

    for (int i=0; i < versionedFiles.size(); i++)
    {
        QFile( workPath + "/" + versionedFiles[i]).remove();
        copyFile( workPath, revPath, versionedFiles[i] ); //from workspace to backup;
    }

    //the meta file
    copyFile( workPath, revPath, metaFilePath(META_CONTROL) );
}

void PatoWorkspace::removeRevision(RevisionKey key) const
{
    QString revPath = backupPath( key );
    removeDirectory(revPath);
}

QString PatoWorkspace::backupPath(RevisionKey rev) const
{
    return QString("%1/%2/%3/").arg( workPath ).arg( cWorkspaceControlFolder ).arg( rev );
}

QString PatoWorkspace::metaFilePath(MetadataType type, bool fullPath) const
{
    QString strFile;

    switch(type)
    {
    case META_ADDED:
        strFile = cAddedMetadata; break;

    case META_CONTROL:
        strFile = cWorkspaceMetadata; break;

    case META_REMOVED:
        strFile = cRemovedMetadata; break;

    case META_ALL:
    default:
        return QString();
    }

    if (fullPath)
    {
        return QString("%1/%2/%3").arg( workPath ).arg( cWorkspaceControlFolder ).arg( strFile );
    }

    return QString("%1/%2").arg( cWorkspaceControlFolder ).arg( strFile );

}


QByteArray PatoWorkspace::toByteArray(Diff&) const
{
    return QByteArray();
}
