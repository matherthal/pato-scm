#include "patoworkspace.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;

const QString cWorkspaceMetadata = ".pato.md";
const QString cAddedMetadata = ".added.md";

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
}

PatoWorkspace::~PatoWorkspace()
{
}

//////////////PRIMEIRA FASE//////////////////////
void PatoWorkspace::create( QStringList files, QString repoAddress, RevisionKey revision)
{
    defaultPath = repoAddress;
    revKey  = revision;

    timespamp = QDateTime::currentDateTime();

    qDebug() << "Repo: " << repoAddress;
    qDebug() << "Rev: " << revision;

    for (int i=0; i < files.size(); i++)
    {
        versionedFiles << files[i];
        qDebug() << "Creating: " << files[i];
    }

    writeMetadata();
}

bool PatoWorkspace::setPath(QString directory)
{
    QFile file( directory + "/" + cWorkspaceMetadata);

    if ( file.exists() )
    {
        workPath = directory;
        readMetadata();
        return true;
    }

    return false;
}

void PatoWorkspace::add( QStringList paths )
{
    for (int i = 0; i < paths.size(); i++)
    {
        if (!versionedFiles.contains( paths[i] ))
        {
            if (!addedFiles.contains(paths[i]))
                addedFiles.append(paths[i]);

            qDebug() << QString("%1 - Added!!!").arg(paths[i]);
        }
        else
        {
            qDebug() << QString("%1 - Already Versioned!!!").arg(paths[i]);
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

void PatoWorkspace::setRevision( RevisionKey revision,  bool commiting  )
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

void PatoWorkspace::update( PatoChangeSet changeSet, RevisionKey revision)
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

            textStream << "Revision: " << revKey;
            textStream << "Default Repository: " << defaultPath;

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
            textStream << "Revision: " << revKey << endl;
            textStream << "Default Repository: " << defaultPath << endl;

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
