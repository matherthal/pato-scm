#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

//#include "PatoClientApi_global.h"
#include"PatoClientApi_global.h"

#include"../patoBase/patotypes.h"
#include"PatoClientException.h"
#include"logOutput.h"
#include"statusOutput.h"
#include"addOutput.h"
#include"checkoutOutput.h"
#include"checkinOutput.h"
#include"updateOutput.h"
#include"diffOutput.h"
#include<QString>
#include<QList>


class PatoClientApi {
public:

    QString init(QString repoName, QString username, QString password);

    QList<logOutput> log(QString adress, QString username, QString password, RevisionKey initialRevision, RevisionKey finalRevision) throw(PatoClientException);

    void merge(QString path1, RevisionKey revision1, QString path2, RevisionKey revision2, QString workspace) throw(PatoClientException);
    void diff(QString path1, RevisionKey revision1, QString path2, RevisionKey revision2) throw(PatoClientException);

    QList<checkoutOutput> checkout(RevisionKey revision, QString adress, QString username, QString password, QString workspace) throw(PatoClientException);
    QList<PatoFileStatus> update(RevisionKey revision, QString adress, QString username, QString password, QString workspace, bool ignoreLocalChanges) throw(PatoClientException);
    QList<PatoFileStatus> checkin(QString address, QString username, QString password, QString workspace, QString message)throw(PatoClientException);
    QList<PatoFileStatus> status(QString workspace) throw(PatoClientException);
    QList<PatoFileStatus> add(QString workspace, QStringList files) throw(PatoClientException);

    PatoClientApi();

private:

};

#endif // PATOCLIENTAPI_H
