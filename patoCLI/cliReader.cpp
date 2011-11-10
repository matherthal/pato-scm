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
#include "logCLI.h"
#include "diffCLI.h"
#include "mergeCLI.h"
#include <iostream>
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
    logCLI* log;
    diffCLI* diff;
    mergeCLI* merge;
    
    if (argc <= 1) {
        cout << "Pato has the following commands:" << endl;
        cout << "add (a)" << endl;
        cout << "checkout (co)" << endl;
        cout << "checkin (ci)" << endl;
        cout << "diff" << endl;
        cout << "log" << endl;
        cout << "merge" << endl;
        cout << "status" << endl;
        cout << "update (up)" << endl;

        return;
    }
    
    command = argv[1];

    
    
    if (command == "checkout" || command == "co") {
        //call checkout command

        co = new checkoutCLI();
        co->command(argc, argv);
    }
    else if (command == "checkin" || command == "ci"){
        //call checkin command

        ci = new checkinCLI();
        ci->command(argc, argv);
    }
    else if (command == "status" || command == "st"){
        //call status command

        st = new statusCLI;
        st->command(argc, argv);
    }
    else if (command == "update" || command == "up"){
        //call update command

        up = new updateCLI;
        up->command(argc, argv);
    }
    else if (command == "add" || command == "a"){
        //call add command

        add = new addCLI;
        add->command(argc, argv);
    }
    else if (command == "log"){
        //call add command

        log = new logCLI();
        log->command(argc, argv);
    }
    else if (command == "diff"){
        //call add command

        diff = new diffCLI();
        diff->command(argc, argv);
    }
    else if (command == "merge"){
        //call add command

        merge = new mergeCLI();
        merge->command(argc, argv);
    }
    else{
        cout<<"Invalid command!"<<endl; 
    }
}

void cliReader::setCommand(QString command) {
    this->command = command;
}

QString cliReader::getCommand() const {
    return command;
}

