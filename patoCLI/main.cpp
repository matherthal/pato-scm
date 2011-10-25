/* 
 * File:   main.cpp
 * Author: marapao
 *
 * Created on October 3, 2011, 8:00 PM
 */

#include <cstdlib>
#include "cliReader.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cliReader* cli;
    
    cli = new cliReader();
    
    cli->reader(argc, argv);
    return 0;
}

