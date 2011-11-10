#ifndef PATOCHANGESET_H
#define PATOCHANGESET_H

#include <QObject>
#include "patotypes.h"

class PatoChangeSet : public QObject
{
    Q_OBJECT
public:
    PatoChangeSet(QObject *parent = 0);
    PatoChangeSet(const PatoChangeSet&);

    const PatoChangeSet& operator= (const PatoChangeSet&);


    const bool isEmpty() const;

    RevisionKey start() const;
    RevisionKey end() const;

private:
    RevisionKey revStart;
    RevisionKey revEnd;

signals:

public slots:

};

#endif // PATOCHANGESET_H
