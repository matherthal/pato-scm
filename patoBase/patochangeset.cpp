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
