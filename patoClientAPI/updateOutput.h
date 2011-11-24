/* 
 * File:   updateOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 7:27 PM
 */

#ifndef UPDATEOUTPUT_H
#define	UPDATEOUTPUT_H


#include<QString>
class updateOutput {
public:
    updateOutput();
    updateOutput(const updateOutput& orig);
    virtual ~updateOutput();
    void SetFile(QString file);
    QString GetFile() const;
private:
    QString file;
};

#endif	/* UPDATEOUTPUT_H */

