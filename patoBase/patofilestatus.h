#ifndef PATOFILESTATUS_H
#define PATOFILESTATUS_H

#include <QObject>

class PatoFileStatus : public QObject
{
    Q_OBJECT
public:
    enum FileStatus
    {
        ADDED,
        MODIFIED,
        REMOVED,
        CLEAN,
        MISSING,
        VERSIONED,
        UNVERSIONED,
        ERROR,
        ALL
    };

public:

    PatoFileStatus(QObject *parent = 0);
    PatoFileStatus(QString, FileStatus);
    PatoFileStatus(const PatoFileStatus&);

    QString fileName() const;
    FileStatus status() const;

    void setFileName( QString );
    void setStatus( FileStatus );

    const PatoFileStatus& operator = (const PatoFileStatus&);



signals:

public slots:

private:
    QString _fileName;
    FileStatus _status;

};

#endif // PATOFILESTATUS_H
