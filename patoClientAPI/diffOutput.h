/* 
 * File:   diffOutput.h
 * Author: marapao
 *
 * Created on November 8, 2011, 7:37 PM
 */

#ifndef DIFFOUTPUT_H
#define	DIFFOUTPUT_H

#include<QString>
#include<QList>

class diffOutput {
public:
    diffOutput();
    diffOutput(const diffOutput& orig);
    virtual ~diffOutput();
private:
    QString file;
    QList<QString> changedLines;
    

};

#endif	/* DIFFOUTPUT_H */

