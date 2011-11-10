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
#include<QString>
#include<QList>


class PatoClientApi {
public:
    QList<checkoutOutput> checkout(RevisionKey revision, QString adress, QString username, QString password, QString workspace) throw(PatoClientException);
    QList<logOutput> log(QString adress, QString username, QString password, RevisionKey initialRevision, RevisionKey finalRevision) throw(PatoClientException);
    QList<checkoutOutput> checkin(QString address, QString username, QString password, QString workspace)throw(PatoClientException);
    QList<statusOutput> status(QString workspace) throw(PatoClientException);
    QList<addOutput> add(QString workspace, QStringList files) throw(PatoClientException);
    QList<updateOutput> update(RevisionKey revision, QString adress, QString username, QString password, QString workspace) throw(PatoClientException);
    void merge(QString path1, RevisionKey revision1, QString path2, RevisionKey revision2, QString workspace) throw(PatoClientException);
    void diff(QString path1, RevisionKey revision1, QString path2, RevisionKey revision2) throw(PatoClientException);
    
    PatoClientApi();

private:

};

#endif // PATOCLIENTAPI_H
