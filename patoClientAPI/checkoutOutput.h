/* 
 * File:   checkoutOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 5:31 PM
 */

#ifndef CHECKOUTOUTPUT_H
#define	CHECKOUTOUTPUT_H

#include<QString>

class checkoutOutput {
public:
    checkoutOutput();
    checkoutOutput(const checkoutOutput& orig);
    virtual ~checkoutOutput();
    void SetFile(QString file);
    QString GetFile() const;
    void SetStatus(QString status);
    QString GetStatus() const;
private:
    QString status;
    QString file;
    
};

#endif	/* CHECKOUTOUTPUT_H */

