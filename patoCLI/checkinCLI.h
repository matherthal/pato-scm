/* 
 * File:   checkin.h
 * Author: marapao
 *
 * Created on October 3, 2011, 9:02 PM
 */
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
    void setPassword(char* password);
    char* getPassword() const;
    void setUsername(char* username);
    char* getUsername() const;
    void setAddress(char* address);
    char* getAddress() const;
    void setWorkspace(char* workspace);
    char* getWorkspace() const;
    
private:
    char* workspace;
    char* address;
    char* username;
    char* password;
    
    
};

#endif	/* CHECKIN_H */

