/* 
 * File:   logCLI.h
 * Author: marapao
 *
 * Created on November 9, 2011, 1:16 AM
 */

#ifndef LOGCLI_H
#define	LOGCLI_H

#include<QString>

class logCLI {
public:
    logCLI();
    logCLI(const logCLI& orig);
    virtual ~logCLI();
    void command(int argc, char** argv);
    void setQuiet(bool quiet);
    bool isQuiet() const;
    void setVerbose(bool verbose);
    bool isVerbose() const;
    void setPath(QString path);
    QString getPath() const;
    void setFinalRevision(QString finalRevision);
    QString getFinalRevision() const;
    void setInitialRevision(QString initialRevision);
    QString getInitialRevision() const;
    void setAddress(QString address);
    QString getAddress() const;
    void setPassword(QString password);
    QString getPassword() const;
    void setUsername(QString username);
    QString getUsername() const;

private:
    QString path;
    QString username;
    QString password;
    QString address;
    QString initialRevision;
    QString finalRevision;
    bool verbose;
    bool quiet;
};

#endif	/* LOGCLI_H */

