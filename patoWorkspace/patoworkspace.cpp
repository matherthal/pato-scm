#include "patoworkspace.h"

PatoWorkspace* PatoWorkspace::sigleWorkspace = NULL;


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
void PatoWorkspace::create( QList< QFile > files, QString repoAddress, RevisionKey revision)
{
    revKey  = revision;
}

void PatoWorkspace::setPath(QString directory)
{
    workPath = directory;
}


void PatoWorkspace::add( QList< QString > path )
{
}

QList< PatoFileStatus > PatoWorkspace::status()
{
    return QList< PatoFileStatus >();
}

void PatoWorkspace::setRepositoryRevision( RevisionKey revision,  bool commiting  )
{
    revKey  = revision;

    if (commiting)
    {
          //clear added files list
          //add into versioned files metadata
    }
}

void PatoWorkspace::update( PatoChangeSet changeSet, RevisionKey revision)
{
    revKey  = revision;
}

QString PatoWorkspace::defaultRepositoryAddress()
{
    return "";
}
/////////////////////////////////////////////////

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
