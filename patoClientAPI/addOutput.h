/* 
 * File:   addOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 5:22 PM
 */

#ifndef ADDOUTPUT_H
#define	ADDOUTPUT_H

#include<QString>

class addOutput {
public:
    addOutput();
    addOutput(const addOutput& orig);
    virtual ~addOutput();
    void SetAdded(bool added);
    bool IsAdded() const;
    void SetFile(QString file);
    QString GetFile() const;
private:
    QString file;
    bool added;
};

#endif	/* ADDOUTPUT_H */

