/* 
 * File:   checkout.h
 * Author: marapao
 *
 * Created on October 3, 2011, 8:19 PM
 */
#include<string>
using namespace std;

#ifndef CHECKOUT_H
#define	CHECKOUT_H



class checkoutCLI {
public:
    checkoutCLI();
    checkoutCLI(const checkoutCLI& orig);
    virtual ~checkoutCLI();
    void command(int argc, char** argv);
    void setPassword(string password);
    string getPassword() const;
    void setUsername(string username);
    string getUsername() const;
    void setAddress(string address);
    string getAddress() const;
    void setWorkspace(string workspace);
    string getWorkspace() const;
    void setRevision(int revision);
    int getRevision() const;
private:
    int revision;
    string workspace;
    string address;
    string username;
    string password;

};

#endif	/* CHECKOUT_H */

