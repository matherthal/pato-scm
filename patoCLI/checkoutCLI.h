/* 
 * File:   checkout.h
 * Author: marapao
 *
 * Created on October 3, 2011, 8:19 PM
 */
#include<string>
#include<QtCore/QString>
using namespace std;

#ifndef CHECKOUT_H
#define	CHECKOUT_H



class checkoutCLI {
public:
    checkoutCLI();
    checkoutCLI(const checkoutCLI& orig);
    virtual ~checkoutCLI();
    void command(int argc, char** argv);
    void setPassword(QString password);
    QString getPassword() const;
    void setUsername(QString username);
    QString getUsername() const;
    void setAddress(QString address);
    QString getAddress() const;
    void setWorkspace(QString workspace);
    QString getWorkspace() const;
    void setRevision(int revision);
    int getRevision() const;
    
private:
    int revision;
    QString workspace;
    QString address;
    QString username;
    QString password;

};

#endif	/* CHECKOUT_H */

