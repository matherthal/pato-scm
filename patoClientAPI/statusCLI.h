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
    virtual ~statusCLI();
    void SetPath(QString path);
    QString GetPath() const;
private:
    QString path;
    
};

#endif	/* STATUSCLI_H */

