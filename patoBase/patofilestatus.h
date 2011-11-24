#ifndef PATOFILESTATUS_H
#define PATOFILESTATUS_H

#include <QObject>

class PatoFileStatus : public QObject
{
    Q_OBJECT
public:
    enum FileStatus
    {
        ADDED = 0x00000001,
        MODIFIED = 0x00000002,
        REMOVED = 0x00000004,
        CLEAN = 0x00000008,
        MISSING = 0x00000010,
        VERSIONED = 0x00000020,
        UNVERSIONED = 0x00000040,
        ERROR = 0x00000080,
        ALL = 0xFFFFFFFF
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
