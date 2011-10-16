/* 
 * File:   cliReader.h
 * Author: marapao
 *
 * Created on October 3, 2011, 8:13 PM
 */

#ifndef CLIREADER_H
#define	CLIREADER_H

#include<string>
using namespace std;

class cliReader {
public:
    cliReader();
    cliReader(const cliReader& orig);
    virtual ~cliReader();
    void reader(int argc, char** argv);
    void setCommand(char* command);
    char* getCommand() const;
    
private:
    char* command;

};

#endif	/* CLIREADER_H */

