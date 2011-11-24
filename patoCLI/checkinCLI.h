/* 
 * File:   checkin.h
 * Author: marapao
 *
 * Created on October 3, 2011, 9:02 PM
 */

#include<QtCore/QString>
#include<string>
using namespace std;

#ifndef CHECKIN_H
#define	CHECKIN_H

class checkinCLI {
public:
    checkinCLI();
    checkinCLI(const checkinCLI& orig);
    virtual ~checkinCLI();
    void command(int argc, char** argv);
    void setPassword(QString password);
    QString getPassword() const;
    void setUsername(QString username);
    QString getUsername() const;
    void setAddress(QString address);
    QString getAddress() const;
    void setWorkspace(QString workspace);
    QString getWorkspace() const;
    
private:
    QString workspace;
    QString address;
    QString username;
    QString password;
    QString message;
    
};

#endif	/* CHECKIN_H */

