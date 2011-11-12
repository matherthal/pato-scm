#include "patoworkspace.h"
#include <QDir>
#include "../patoBase/patofilestatus.h"
#include "../patoAlgorithms/diff.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;

const QString cWorkspaceControlFolder = ".pato";
const QString cWorkspaceMetadata = ".pato.md";
const QString cAddedMetadata = ".added.md";
const QString cRemovedMetadata = ".removed.md";



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

PatoWorkspace::PatoWorkspace()
{
    ready = false;
}

PatoWorkspace::~PatoWorkspace()
{
}

//////////////PRIMEIRA FASE//////////////////////
bool PatoWorkspace::create(QString sourceDir, QStringList files, QString repoAddress, RevisionKey revision )
{
    if ( workPath.isEmpty())
    {
        lastError = "Work path is Empty.";
        return false;
    }

    QFile file( workPath + "/" + cWorkspaceMetadata);
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

    QFile file( directory + "/" + cWorkspaceMetadata);
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

bool PatoWorkspace::add( QString sourceDir, QStringList paths )
{
    for (int i = 0; i < paths.size(); i++)
    {
        if (!versionedFiles.contains( paths[i] ))
        {
            if (!addedFiles.contains(paths[i]))
                addedFiles.append(paths[i]);

            copyFile(sourceDir, workPath, paths[i] );
        }
        else
        {
            qWarning() << QString("%1 - Already Versioned!!!").arg(paths[i]);
        }
    }

    writeMetadata();

    return true;
}

QList< PatoFileStatus > PatoWorkspace::status(PatoFileStatus::FileStatus statusFilter) const
{
    QList< PatoFileStatus > statusList;

    for (int i=0; i < versionedFiles.size(); i++)
    {
        if (  QFile( workPath + "/" + versionedFiles[i]).exists() )
        {
            QFileInfo fileInfo( workPath + "/" + versionedFiles[i] );

            if ( (statusFilter & PatoFileStatus::MODIFIED) && (fileInfo.lastModified() > timestamp ) )
            {
                statusList.append( PatoFileStatus( versionedFiles[i], PatoFileStatus::MODIFIED ) );
            }

            if ( (statusFilter & PatoFileStatus::CLEAN) && (fileInfo.lastModified() <= timestamp) )
            {
                statusList.append( PatoFileStatus( versionedFiles[i], PatoFileStatus::CLEAN ) );
            }
        }
        else
        {
            if ( statusFilter & PatoFileStatus::MISSING )
            {
                statusList.append( PatoFileStatus( versionedFiles[i], PatoFileStatus::MISSING ) );
            }
        }
    }

    if (statusFilter & PatoFileStatus::ADDED)
    {
        for (int i=0; i < addedFiles.size(); i++)
        {
            statusList.append( PatoFileStatus( addedFiles[i], PatoFileStatus::ADDED ) );

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

bool PatoWorkspace::update( PatoChangeSet changeSet, RevisionKey rev)
{
    PatoChangeSet localChanges = changes();

    if (!localChanges.isEmpty())
    {

    }
    else
    {
        Q_ASSERT (  changeSet.start() == revision() );
        //copyRevision( backupPath(revision()), backupPath(changeSet.end()) );
        //PatoAlgorithms::ApplyChangeSet( backupPath(changeSet.end()), changeSet); //a clean .end() version;
        //PatoAlgorithms::Merge( backupPath(changeSet.end()), changeSet); //a clean .end() version;
    }

    changeSet = changeSet; //PatoAlgorithms::ApplyChangeSet( workPath, changeSet);
    qWarning() << "Update workspace needs PatoAlgorithms::ApplyChangeSet( workPath, changeSet)";
    revKey  = rev;

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
    }
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
    //read .pato.md;
    //remove all files;
    //remove all dirs;
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
