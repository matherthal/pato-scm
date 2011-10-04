/* 
 * File:   cliReader.cpp
 * Author: marapao
 * 
 * Created on October 3, 2011, 8:13 PM
 */

#include "cliReader.h"
#include "checkoutCLI.h"
#include "checkinCLI.h"
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
    }else{
        cout<<"Invalid command!"<<endl; 
    }
}

void cliReader::setCommand(char* command) {
    this->command = command;
}

char* cliReader::getCommand() const {
    return command;
}
