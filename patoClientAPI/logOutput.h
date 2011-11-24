/* 
 * File:   logOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 3:46 PM
 */

#ifndef LOGOUTPUT_H
#define	LOGOUTPUT_H

#include<QString>

class logOutput {
public:
    logOutput();
    logOutput(const logOutput& orig);
    virtual ~logOutput();
    void SetRevision(QString revision);
    QString GetRevision() const;
    void SetMessage(QString message);
    QString GetMessage() const;
    void SetDate(QString date);
    QString GetDate() const;
    void SetName(QString name);
    QString GetName() const;
private:
    QString name;
    QString date;
    QString message;
    QString revision;
    
};

#endif	/* LOGOUTPUT_H */

