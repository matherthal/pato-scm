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
    void setPassword(char* password);
    char* getPassword() const;
    void setUsername(char* username);
    char* getUsername() const;
    void setAddress(char* address);
    char* getAddress() const;
    void setWorkspace(char* workspace);
    char* getWorkspace() const;
    void setRevision(int revision);
    int getRevision() const;
    
private:
    int revision;
    char* workspace;
    char* address;
    char* username;
    char* password;

};

#endif	/* CHECKOUT_H */

