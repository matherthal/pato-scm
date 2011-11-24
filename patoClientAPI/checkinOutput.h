/* 
 * File:   checkinOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 6:04 PM
 */

#ifndef CHECKINOUTPUT_H
#define	CHECKINOUTPUT_H

#include<QString>

class checkinOutput {
public:
    checkinOutput();
    checkinOutput(const checkinOutput& orig);
    virtual ~checkinOutput();
    void SetFile(QString file);
    QString GetFile() const;
    void SetStatus(QString status);
    QString GetStatus() const;
private:
    QString status;
    QString file;

};

#endif	/* CHECKINOUTPUT_H */

