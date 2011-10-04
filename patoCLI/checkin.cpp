/* 
 * File:   checkin.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 9:02 PM
 */

#include "checkin.h"
#include<string.h>
#include<iostream>
using namespace std;

checkin::checkin() {
}

void checkin::command(int argc, char** argv){
    //treating cases that argc > 1

    char* parameter;

    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--username") == 0) {
            username = argv[i + 1];
        } else if (strcmp(parameter, "--password") == 0) {
            password = argv[i + 1];
        } else if (strcmp(parameter, "--address") == 0) {
            address = argv[i + 1];
        } else if (strcmp(parameter, "--workspace") == 0) {
            workspace = argv[i + 1];
        }else{
            cout<<"[ERROR] "<<parameter<<" don't exist."<<endl;
            return;
        }
    }
    
    cout << "workspace = " << workspace << endl;
    cout << "username = " << username << endl;
    cout << "password = " << password << endl;
    cout << "address = " << address << endl;

}

void checkin::setPassword(string password) {
    this->password = password;
}

string checkin::getPassword() const {
    return password;
}

void checkin::setUsername(string username) {
    this->username = username;
}

string checkin::getUsername() const {
    return username;
}

void checkin::setAddress(string address) {
    this->address = address;
}

string checkin::getAddress() const {
    return address;
}

void checkin::setWorkspace(string workspace) {
    this->workspace = workspace;
}

string checkin::getWorkspace() const {
    return workspace;
}

checkin::checkin(const checkin& orig) {
}

checkin::~checkin() {
}

