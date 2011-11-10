#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

//#include "PatoClientApi_global.h"
#include"PatoClientApi_global.h"
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
    QList<checkoutOutput> checkout(int revision, QString adress, QString username, QString password, QString workspace) throw(PatoClientException);
    QList<logOutput> log(QString adress, QString username, QString password, QString initialRevision, QString finalRevision) throw(PatoClientException);
    QList<checkoutOutput> checkin(QString address, QString username, QString password, QString workspace)throw(PatoClientException);
    QList<statusOutput> status(QString workspace) throw(PatoClientException);
    QList<addOutput> add(QString workspace, QList<QString> files) throw(PatoClientException);
    QList<updateOutput> update(QString revision, QString adress, QString username, QString password, QString workspace) throw(PatoClientException);
    void merge(QString path1, int revision1, QString path2, int revision2, QString workspace) throw(PatoClientException);
    void diff(QString path1, int revision1, QString path2, int revision2) throw(PatoClientException);
    
    PatoClientApi();

private:

};

#endif // PATOCLIENTAPI_H
