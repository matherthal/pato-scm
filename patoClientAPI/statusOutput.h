/* 
 * File:   statusOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 5:04 PM
 */

#ifndef STATUSOUTPUT_H
#define	STATUSOUTPUT_H

#include<QString>

class statusOutput {
public:
    statusOutput();
    statusOutput(const statusOutput& orig);
    virtual ~statusOutput();
    void SetFile(QString file);
    QString GetFile() const;
    void SetStatus(QString status);
    QString GetStatus() const;
private:
    QString status;
    QString file;

};

#endif	/* STATUSOUTPUT_H */

