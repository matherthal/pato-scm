#ifndef PATOCHANGESET_H
#define PATOCHANGESET_H

#include <QObject>

class PatoChangeSet : public QObject
{
    Q_OBJECT
public:
    PatoChangeSet(QObject *parent = 0);
    PatoChangeSet(const PatoChangeSet&);

    const PatoChangeSet& operator= (const PatoChangeSet&);
signals:

public slots:

};

#endif // PATOCHANGESET_H
