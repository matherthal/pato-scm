/* 
 * File:   checkin.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 9:02 PM
 */

#include "checkinCLI.h"
#include<string.h>
#include<iostream>
using namespace std;

checkinCLI::checkinCLI() {
}

void checkinCLI::command(int argc, char** argv){
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

void checkinCLI::setPassword(string password) {
    this->password = password;
}

string checkinCLI::getPassword() const {
    return password;
}

void checkinCLI::setUsername(string username) {
    this->username = username;
}

string checkinCLI::getUsername() const {
    return username;
}

void checkinCLI::setAddress(string address) {
    this->address = address;
}

string checkinCLI::getAddress() const {
    return address;
}

void checkinCLI::setWorkspace(string workspace) {
    this->workspace = workspace;
}

string checkinCLI::getWorkspace() const {
    return workspace;
}

checkinCLI::checkinCLI(const checkinCLI& orig) {
}

checkinCLI::~checkinCLI() {
}

