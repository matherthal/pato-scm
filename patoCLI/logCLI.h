/* 
 * File:   logCLI.h
 * Author: marapao
 *
 * Created on November 8, 2011, 4:35 PM
 */

#ifndef LOGCLI_H
#define	LOGCLI_H

#include<QString>
#include<QList>
#include"../patoBase/patotypes.h"

class logCLI {
public:
    logCLI();
    logCLI(const logCLI& orig);
    virtual ~logCLI();
    void command(int argc, char** argv);
    void SetPassword(QString password);
    QString GetPassword() const;
    void SetUsername(QString username);
    QString GetUsername() const;
    void SetFinalRevision(RevisionKey  finalRevision);
    RevisionKey GetFinalRevision() const;
    void SetInitialRevision(RevisionKey  initialRevision);
    RevisionKey  GetInitialRevision() const;
    void SetAddress(QString address);
    QString GetAddress() const;
    void SetParameters(QList<QString> parameters);
    QList<QString> GetParameters() const;
private:
    QString address;
    RevisionKey initialRevision;
    RevisionKey finalRevision;
    QString username;
    QString password;
    QList<QString> parameters;
    
};

#endif	/* LOGCLI_H */

