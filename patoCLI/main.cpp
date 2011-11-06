/* 
 * File:   main.cpp
 * Author: marapao
 *
 * Created on October 3, 2011, 8:00 PM
 */

#include "cliReader.h"  
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<QtCore/QFile>
#include<QtCore/QTextStream>

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

