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

class checkin {
public:
    checkin();
    checkin(const checkin& orig);
    virtual ~checkin();
    void command(int argc, char** argv);
    void setPassword(string password);
    string getPassword() const;
    void setUsername(string username);
    string getUsername() const;
    void setAddress(string address);
    string getAddress() const;
    void setWorkspace(string workspace);
    string getWorkspace() const;
private:
    string workspace;
    string address;
    string username;
    string password;
    
    
};

#endif	/* CHECKIN_H */

