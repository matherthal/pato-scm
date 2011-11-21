#ifndef PATOTYPES_H
#define PATOTYPES_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QStringList>
#include <QDebug>
#include <QTextStream>
#include <QDateTime>
typedef int RevisionKey;
typedef std::string StorageKey;
#include "patofilestatus.h"

typedef struct _PatoDiffInfo
{
    PatoFileStatus::FileStatus status;
    QByteArray diff;
}PatoDiffInfo;

typedef struct _PatoVersionReturn
{
    QString address;
    QString path;
    RevisionKey revision;
    QStringList files;
}PatoVersionReturn;

typedef QMap<QString, PatoDiffInfo> PatoChangeSetMap;

#endif // PATOTYPES_H
