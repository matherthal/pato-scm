/* 
 * File:   updateCLI.h
 * Author: marapao
 *
 * Created on October 7, 2011, 10:40 AM
 */

#ifndef UPDATECLI_H
#define	UPDATECLI_H

#include<QtCore/QString>
#include<../patoBase/patotypes.h>

class updateCLI {
public:
    updateCLI();
    updateCLI(const updateCLI& orig);
    virtual ~updateCLI();
    void command(int argc, char** argv);
    void SetAddress(QString address);
    QString GetAddress() const;
    void SetPassword(QString password);
    QString GetPassword() const;
    void SetUsername(QString username);
    QString GetUsername() const;
    void SetRevision(RevisionKey  revision);
    RevisionKey GetRevision() const;
    void SetWorkspace(QString workspace);
    QString GetWorkspace() const;
private:
    QString workspace;
    RevisionKey revision;
    QString username;
    QString password;
    QString address;

};

#endif	/* UPDATECLI_H */

