#include "patofilestatus.h"

PatoFileStatus::PatoFileStatus(QObject *parent) : QObject(parent)
{
}


PatoFileStatus::PatoFileStatus(const PatoFileStatus&) :  QObject(NULL)
{
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

