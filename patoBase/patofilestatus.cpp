#include "patofilestatus.h"

PatoFileStatus::PatoFileStatus(QObject *parent) : QObject(parent)
{
}


PatoFileStatus::PatoFileStatus(const PatoFileStatus& src) :  QObject(NULL)
{
    *this = src;
}

PatoFileStatus::PatoFileStatus(QString file, FileStatus stat) :QObject(NULL)
{
    setFileName(file);
    setStatus(stat);
}

QString PatoFileStatus::fileName() const
{
    return _fileName;
}

PatoFileStatus::FileStatus PatoFileStatus::status() const
{
    return _status;
}

void PatoFileStatus::setFileName( QString  s)
{
    _fileName = s;
}

void PatoFileStatus::setStatus( FileStatus  s)
{
    _status = s;
}

const PatoFileStatus& PatoFileStatus::operator = (const PatoFileStatus& src)
{
    _fileName = src._fileName;
    _status = src._status;

    return *this;
}
