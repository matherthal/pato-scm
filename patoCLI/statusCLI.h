/* 
 * File:   statusCLI.h
 * Author: marapao
 *
 * Created on October 10, 2011, 7:26 PM
 */

#ifndef STATUSCLI_H
#define	STATUSCLI_H

#include<QtCore/QString>

class statusCLI {
public:
    statusCLI();
    statusCLI(const statusCLI& orig);
    void command(int argc, char** argv);
    virtual ~statusCLI();
    void SetWorkspace(QString workspace);
    QString GetWorkspace() const;
private:
    QString workspace;
    
};

#endif	/* STATUSCLI_H */

