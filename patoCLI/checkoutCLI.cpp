/* 
 * File:   checkout.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:19 PM
 */

#include "checkoutCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include<stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

void checkoutCLI::command(int argc, char** argv) {
    //treating cases that argc > 1

    char* parameter;
    PatoClientApi* clientAPI;

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

    clientAPI = new PatoClientApi();
    
    clientAPI->checkout(revision, address, username, password, workspace);
    
    
    
}

void checkoutCLI::setPassword(char* password) {
    this->password = password;
}

char* checkoutCLI::getPassword() const {
    return password;
}

void checkoutCLI::setUsername(char* username) {
    this->username = username;
}

char* checkoutCLI::getUsername() const {
    return username;
}

void checkoutCLI::setAddress(char* address) {
    this->address = address;
}

char* checkoutCLI::getAddress() const {
    return address;
}

void checkoutCLI::setWorkspace(char* workspace) {
    this->workspace = workspace;
}

char* checkoutCLI::getWorkspace() const {
    return workspace;
}

void checkoutCLI::setRevision(int revision) {
    this->revision = revision;
}

int checkoutCLI::getRevision() const {
    return revision;
}

checkoutCLI::checkoutCLI() {
    revision = -1;
    workspace = "";
    username = "";
    password = "";
    address = "";
    
}

checkoutCLI::checkoutCLI(const checkoutCLI& orig) {
}

checkoutCLI::~checkoutCLI() {
}

