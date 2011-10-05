#include "patoworkspace.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;

const QString cWorkspaceMetadata = ".pato.md";

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
        qDebug() << "Creating " << files[i];
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

QList< PatoFileStatus > PatoWorkspace::status() const
{
    QList< PatoFileStatus > statusList;

    for (int i=0; i < versionedFiles.size(); i++)
    {
        QFileInfo fileInfo( workPath + "/" + versionedFiles[i] );
        if ( fileInfo.lastModified() > timespamp )
        {
            statusList.append( PatoFileStatus( versionedFiles[i], PatoFileStatus::MODIFIED ) );
        }
    }

    for (int i=0; i < addedFiles.size(); i++)
    {
        statusList.append( PatoFileStatus( addedFiles[i], PatoFileStatus::MODIFIED ) );

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
        //clear added files list
        //add into versioned files metadata
    }

    writeMetadata();
}

void PatoWorkspace::update( PatoChangeSet changeSet, RevisionKey revision)
{
    changeSet = changeSet; //PatoAlgorithms::ApplyChangeSet( workPath, changeSet);
    qDebug() << "warning: update workspace needs PatoAlgorithms::ApplyChangeSet( workPath, changeSet)";
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


void PatoWorkspace::writeMetadata()
{
    QFile file( workPath + "/" + cWorkspaceMetadata);
    if (file.open( QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream textStream(&file);

        textStream << "Revision: " << revKey;
        textStream << "Default Repository: " << defaultPath;
        textStream << "Versioned Files: ";// << versionedFiles;
    }
}

void PatoWorkspace::readMetadata()
{
    QFile file( workPath + "/" + cWorkspaceMetadata);
    if (file.open( QFile::ReadOnly))
    {
        QTextStream textStream(&file);

        while (!textStream.atEnd())
        {
            qDebug() << textStream.readLine();
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
