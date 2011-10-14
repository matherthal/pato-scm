/* 
 * File:   checkin.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 9:02 PM
 */

#include "checkinCLI.h"
#include "../patoClientAPI/patoclientapi.h"
#include<string.h>
#include<iostream>
using namespace std;

checkinCLI::checkinCLI() {
    
    address = "";
    username = "";
    password = "";
    workspace = "";
}


void checkinCLI::command(int argc, char** argv){
    //treating cases that argc > 1

    PatoClientApi* clientAPI;
    clientAPI = new PatoClientApi();
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
    
    
    clientAPI->checkin(address, username, password, workspace);
    
}

void checkinCLI::setPassword(char* password) {
    this->password = password;
}

char* checkinCLI::getPassword() const {
    return password;
}

void checkinCLI::setUsername(char* username) {
    this->username = username;
}

char* checkinCLI::getUsername() const {
    return username;
}

void checkinCLI::setAddress(char* address) {
    this->address = address;
}

char* checkinCLI::getAddress() const {
    return address;
}

void checkinCLI::setWorkspace(char* workspace) {
    this->workspace = workspace;
}

char* checkinCLI::getWorkspace() const {
    return workspace;
}

checkinCLI::checkinCLI(const checkinCLI& orig) {
}

checkinCLI::~checkinCLI() {
}

