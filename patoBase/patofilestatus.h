#ifndef PATOFILESTATUS_H
#define PATOFILESTATUS_H

#include <QObject>

class PatoFileStatus : public QObject
{
    Q_OBJECT
public:
    PatoFileStatus(QObject *parent = 0);
    PatoFileStatus(const PatoFileStatus&);

signals:

public slots:

};

#endif // PATOFILESTATUS_H
