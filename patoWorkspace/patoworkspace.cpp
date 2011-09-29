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
void PatoWorkspace::checkout(/*files, repoAddress, revision*/)
{
}

void PatoWorkspace::add(/*path*/)
{
}

void /*QList<FileStatus>*/ PatoWorkspace::status()
{
}

void PatoWorkspace::commit(/*revision*/)
{
}

void PatoWorkspace::update(/*files, revision*/)
{
}

void PatoWorkspace::defaultRepositoryAddress()
{
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
