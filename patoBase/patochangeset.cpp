#include "patochangeset.h"

PatoChangeSet::PatoChangeSet(QObject *parent) :
    QObject(parent)
{
}


PatoChangeSet::PatoChangeSet(const PatoChangeSet& src) : QObject(NULL)
{
    *this = src;
}

const PatoChangeSet& PatoChangeSet::operator= (const PatoChangeSet& src)
{
    return *this;
}

bool PatoChangeSet::isEmpty() const
{
   return true;
}

void PatoChangeSet::add( QString file, PatoFileStatus::FileStatus status, QByteArray data)
{
    myDiffs[file].status = status;
    myDiffs[file].diff = data;

}

QList< PatoFileStatus > PatoChangeSet::status() const
{
    QList< PatoFileStatus > ret;

    PatoChangeSetMap::ConstIterator it;

    for (it = myDiffs.constBegin(); it != myDiffs.constEnd(); it++)
    {
        ret << PatoFileStatus( it.key(), it.value().status );
    }

    return ret;
}

PatoChangeSetMap PatoChangeSet::changes() const
{
    return myDiffs;
}


RevisionKey PatoChangeSet::start() const
{
    return revStart;
}

RevisionKey PatoChangeSet::end() const
{
    return revEnd;
}
