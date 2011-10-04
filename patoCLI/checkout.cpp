/* 
 * File:   checkout.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:19 PM
 */

#include "checkout.h"
#include<stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

void checkout::command(int argc, char** argv) {
    //treating cases that argc > 1

    char* parameter;

    for (int i = 2; i < argc; i += 2) {
        parameter = argv[i];

        if (strcmp(parameter, "--revision") == 0) {
            revision = atoi(argv[i + 1]);
        } else if (strcmp(parameter, "--username") == 0) {
            username = argv[i + 1];
        } else if (strcmp(parameter, "--password") == 0) {
            password = argv[i + 1];
        } else if (strcmp(parameter, "--address") == 0) {
            address = argv[i + 1];
        } else if (strcmp(parameter, "--workspace") == 0) {
            workspace = argv[i + 1];
        }
    }

    
    
    
    cout << "revision = " << revision << endl;
    cout << "workspace = " << workspace << endl;
    cout << "username = " << username << endl;
    cout << "password = " << password << endl;
    cout << "address = " << address << endl;

}

checkout::checkout() {
    revision = -1;
    workspace = "";
    username = "";
    password = "";
    address = "";
}

void checkout::setPassword(string password) {
    this->password = password;
}

string checkout::getPassword() const {
    return password;
}

void checkout::setUsername(string username) {
    this->username = username;
}

string checkout::getUsername() const {
    return username;
}

void checkout::setAddress(string address) {
    this->address = address;
}

string checkout::getAddress() const {
    return address;
}

void checkout::setWorkspace(string workspace) {
    this->workspace = workspace;
}

string checkout::getWorkspace() const {
    return workspace;
}

void checkout::setRevision(int revision) {
    this->revision = revision;
}

int checkout::getRevision() const {
    return revision;
}

checkout::checkout(const checkout& orig) {
}

checkout::~checkout() {
}

