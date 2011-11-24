#include "file.h"

File::File()
{
}

File::File(const QString &name)
{
    file.setFileName(name);
}

File::~File()
{
}

bool File::copy(const QString &newName)
{
    return file.copy(newName);
}

bool File::exists() const
{
    return file.exists();
}

QString File::fileName() const
{
    return file.fileName();
}

bool File::remove()
{
    return file.remove();
}
