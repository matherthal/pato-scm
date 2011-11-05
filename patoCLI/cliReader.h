/* 
 * File:   cliReader.h
 * Author: marapao
 *
 * Created on October 3, 2011, 8:13 PM
 */

#ifndef CLIREADER_H
#define	CLIREADER_H

#include<QtCore/QString>
using namespace std;

class cliReader {
public:
    cliReader();
    cliReader(const cliReader& orig);
    virtual ~cliReader();
    void reader(int argc, char** argv);
    void setCommand(QString command);
    QString getCommand() const;
    
private:
    QString command;

};

#endif	/* CLIREADER_H */

