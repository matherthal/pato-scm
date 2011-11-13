#ifndef PATOCHANGESET_H
#define PATOCHANGESET_H

#include <QObject>
#include "patotypes.h"
#include "patofilestatus.h"

class PatoChangeSet : public QObject
{
    Q_OBJECT

private:


public:
    PatoChangeSet(QObject *parent = 0);
    PatoChangeSet(const PatoChangeSet&);

    const PatoChangeSet& operator= (const PatoChangeSet&);

    void add( QString, PatoFileStatus::FileStatus, QByteArray);
    QList< PatoFileStatus > status() const;

    bool isEmpty() const;

    RevisionKey start() const;
    RevisionKey end() const;

    PatoChangeSetMap changes() const;

private:
    RevisionKey revStart;
    RevisionKey revEnd;



    PatoChangeSetMap myDiffs;

signals:

public slots:

};

#endif // PATOCHANGESET_H
