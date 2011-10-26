#include "patoworkspace.h"
#include <QDir>
#include "../patoBase/patoResourceAbstractFactory.h"
#include "../patoBase/ifile.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;

const QString cWorkspaceMetadata = ".pato.md";
const QString cAddedMetadata = ".added.md";


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

    PatoResourceAbstractFactory *factory = PatoResourceAbstractFactory::getInstance();
    IFile *file = factory->createFile(workPath + "/" + cWorkspaceMetadata);

    if ( file->exists() )
    {
        lastError = "Repository already created.";
        return false;
    }

    defaultPath = repoAddress;
    revKey  = revision;

    timespamp = QDateTime::currentDateTime();

    for (int i=0; i < files.size(); i++)
    {
        versionedFiles << files[i];
        copyFile(sourceDir, workPath, files[i] );
    }

    writeMetadata();

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
}

QList< PatoFileStatus > PatoWorkspace::status(PatoFileStatus::FileStatus statusFilter) const
{
    QList< PatoFileStatus > statusList;

    for (int i=0; i < versionedFiles.size(); i++)
    {
        if (  QFile( workPath + "/" + versionedFiles[i]).exists() )
        {
            QFileInfo fileInfo( workPath + "/" + versionedFiles[i] );

            if ( (statusFilter & PatoFileStatus::MODIFIED) && (fileInfo.lastModified() > timespamp ) )
            {
                statusList.append( PatoFileStatus( versionedFiles[i], PatoFileStatus::MODIFIED ) );
            }

            if ( (statusFilter & PatoFileStatus::CLEAN) && (fileInfo.lastModified() <= timespamp) )
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

    qDebug() << "warning: status returns only modified and added files";

    return statusList;
}

bool PatoWorkspace::setRevision( RevisionKey revision,  bool commiting  )
{
    qDebug() << QString("Old Revision: %1 -> New Revision: %2").arg(revKey).arg(revision);

    revKey  = revision;

    if (commiting)
    {
        versionedFiles << addedFiles;
    }
    else
    {
        if (addedFiles.size())
        {
            qWarning() << "Ignoring added files" ;
        }
    }
    addedFiles.clear();
    writeMetadata();
}

bool PatoWorkspace::update( PatoChangeSet changeSet, RevisionKey revision)
{
    changeSet = changeSet; //PatoAlgorithms::ApplyChangeSet( workPath, changeSet);
    qWarning() << "Update workspace needs PatoAlgorithms::ApplyChangeSet( workPath, changeSet)";
    revKey  = revision;

    writeMetadata();
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
        QFile file( workPath + "/" + cWorkspaceMetadata);
        if (file.open( QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream textStream(&file);

            textStream << "Revision: " << revKey << endl;
            textStream << "Default Repository: " << defaultPath << endl;

            for (int i=0; i < versionedFiles.size(); i++)
            {
                textStream << versionedFiles[i] << endl;// << versionedFiles;
            }

            file.close();
        }
        else
        {
            qWarning() << "Cannot open .pato.pm ";
        }
    }

    if (types & META_ADDED)
    {
        QFile file( workPath + "/" + cAddedMetadata);
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
            qWarning() << "Cannot open .added.pm ";
        }
    }
}

void PatoWorkspace::readMetadata(MetadataType types)
{
    if (types & META_CONTROL)
    {
        QFile file( workPath + "/" + cWorkspaceMetadata);
        if (file.open( QFile::ReadOnly))
        {
            QTextStream textStream(&file);
            revKey = textStream.readLine().toInt();
            defaultPath = textStream.readLine();

            while (!textStream.atEnd())
            {
                versionedFiles << textStream.readLine();
            }
        }
    }

    if (types & META_ADDED)
    {
        QFile file( workPath + "/" + cAddedMetadata);
        if (file.open( QFile::ReadOnly))
        {
            QTextStream textStream(&file);

            while (!textStream.atEnd())
            {
                addedFiles << textStream.readLine();
            }
        }
    }
}

//////////////SEGUNDA FASE///////////////////////
void PatoWorkspace::revert(/*path*/)
{
}

void PatoWorkspace::currentFile(/*path*/)// File
{
}

void PatoWorkspace::originalFile(/*path*/)// File
{
}

void PatoWorkspace::remove(/*path*/)
{
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
