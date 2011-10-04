/* 
 * File:   checkout.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:19 PM
 */

#include "checkoutCLI.h"
#include<stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

void checkoutCLI::command(int argc, char** argv) {
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

checkoutCLI::checkoutCLI() {
    revision = -1;
    workspace = "";
    username = "";
    password = "";
    address = "";
}

void checkoutCLI::setPassword(string password) {
    this->password = password;
}

string checkoutCLI::getPassword() const {
    return password;
}

void checkoutCLI::setUsername(string username) {
    this->username = username;
}

string checkoutCLI::getUsername() const {
    return username;
}

void checkoutCLI::setAddress(string address) {
    this->address = address;
}

string checkoutCLI::getAddress() const {
    return address;
}

void checkoutCLI::setWorkspace(string workspace) {
    this->workspace = workspace;
}

string checkoutCLI::getWorkspace() const {
    return workspace;
}

void checkoutCLI::setRevision(int revision) {
    this->revision = revision;
}

int checkoutCLI::getRevision() const {
    return revision;
}

checkoutCLI::checkoutCLI(const checkoutCLI& orig) {
}

checkoutCLI::~checkoutCLI() {
}

