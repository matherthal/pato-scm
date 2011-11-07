/* 
 * File:   PatoClientException.h
 * Author: marapao
 *
 * Created on October 16, 2011, 11:29 AM
 */

#ifndef PATOCLIENTEXCEPTION_H
#define	PATOCLIENTEXCEPTION_H

#include<exception>
#include<QtCore/QString>
using namespace std;

class PatoClientException: public exception {
public:
    PatoClientException();
    PatoClientException(QString message);
    PatoClientException(const PatoClientException& orig);
    ~PatoClientException()throw();
    void SetMessage(QString message);
    QString GetMessage() const;
private:
    QString message;
    
};

#endif	/* PATOCLIENTEXCEPTION_H */

