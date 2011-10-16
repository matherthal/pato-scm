/* 
 * File:   cliReader.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:13 PM
 */

#include "cliReader.h"
#include "checkoutCLI.h"
#include "checkinCLI.h"
#include "updateCLI.h"
#include "addCLI.h"
#include "statusCLI.h"
#include <iostream>
#include <string.h>
using namespace std;

cliReader::cliReader() {
}

cliReader::cliReader(const cliReader& orig) {
}

cliReader::~cliReader() {
}

void cliReader::reader(int argc, char** argv) {
    //i = 0, local path
    //i = 1, command
    //i > 1, parameters

    checkoutCLI* co;
    checkinCLI* ci;
    statusCLI* st;
    updateCLI* up;
    addCLI* add;
    
    if (argc <= 1) {
        cout << "Please specify a command" << endl;
        return;
    }
    command = argv[1];

    if ((strcmp(command, "checkout") == 0) || (strcmp(command, "co") == 0)) {
        //call checkout command

        co = new checkoutCLI();
        co->command(argc, argv);
    }
    else if ((strcmp(command, "checkin") == 0) || (strcmp(command, "ci") == 0)){
        //call checkout command

        ci = new checkinCLI();
        ci->command(argc, argv);
    }
    else if ((strcmp(command, "status") == 0) || (strcmp(command, "st") == 0)){
        //call checkout command

        st = new statusCLI;
        st->command(argc, argv);
    }
    else if ((strcmp(command, "update") == 0) || (strcmp(command, "up") == 0)){
        //call checkout command

        up = new updateCLI;
        up->command(argc, argv);
    }
    else if ((strcmp(command, "add") == 0) || (strcmp(command, "a") == 0)){
        //call checkout command

        add = new addCLI;
        add->command(argc, argv);
    }
    
    else{
        cout<<"Invalid command!"<<endl; 
    }
}

void cliReader::setCommand(char* command) {
    this->command = command;
}

char* cliReader::getCommand() const {
    return command;
}
