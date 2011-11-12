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
typedef QString RevisionKey;
typedef std::string StorageKey;
#include "patofilestatus.h"


typedef struct _PatoDiffInfo
{
    PatoFileStatus::FileStatus status;
    QByteArray diff;
}PatoDiffInfo;

typedef QMap<QString, PatoDiffInfo> PatoChangeSetMap;

#include "patochangeset.h"
#include "patofilestatus.h"

#endif // PATOTYPES_H
