#include "mockfile.h"

MockFile::MockFile()
{
    construir();
}

MockFile::MockFile(QString strName)
{
    construir();
}

void MockFile::construir()
{
    existsResult = true;
    copyResult = true;
    removeResult = true;
}

bool MockFile::exists() const
{
    return existsResult;
}

bool MockFile::copy(const QString &newName)
{
    return copyResult;
}

QString MockFile::fileName() const
{
    return "";
}

bool MockFile::remove()
{
    return removeResult;
}

void MockFile::setExistsResult(bool result)
{
    existsResult = result;
}

void MockFile::setCopyResult(bool result)
{
    copyResult = result;
}

void MockFile::setRemoveResult(bool result)
{
    removeResult = result;
}
