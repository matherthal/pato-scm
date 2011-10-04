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
using namespace  std;


cliReader::cliReader() {
}


cliReader::cliReader(const cliReader& orig) {
}

cliReader::~cliReader() {
}

void cliReader::reader(int argc, char** argv){
    //i = 0, local path
    //i = 1, command
    //i > 1, parameters
    
    checkoutCLI* co;
    checkinCLI* ci;
    
    
    if(argc < 1){
        cout<<"Please specify a command"<<endl;
        return;
    }
    command = argv[1];
    for(int i = 0; i < argc; ++i){
        
        cout<<i<<"  "<<argv[i]<<endl;
    }
    
    if(strcmp(command, "checkout") == 0){
        //call checkout command
        
        co = new checkoutCLI();
        co->command(argc, argv);
    }
    if(strcmp(command, "checkin") == 0){
        //call checkout command
        
        ci = new checkinCLI();
        ci->command(argc, argv);
    }
}

void cliReader::setCommand(char* command) {
    this->command = command;
}

char* cliReader::getCommand() const {
    return command;
}
