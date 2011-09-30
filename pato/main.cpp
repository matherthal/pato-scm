#include <QtCore/QCoreApplication>
#include <QTimer>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "../patoClientAPI/patoclientapi.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName("Pato-SCM");

    //process command lines here//TODO-PATO

    //Creating one instance of PatoClientApi
    PatoClientApi *orquestrador;
    orquestrador = new PatoClientApi();

    //Identification of one command and your options
    int command = 0;
    bool checkout, adress, revision, username, password, workspace;
    checkout = false;
    adress = false;
    revision = false;
    username = false;
    password = false;
    workspace = false;

        cout<<"1 "<<command<<endl;


    while((command = getopt(argc, argv, "carupw:")) != -1){
        cout<<"2 "<<command<<endl;

        switch(command){
        case 'c':
            checkout = true;
            break;
        case 'a':
            adress = true;
            break;
        case 'r':
            revision = true;
            break;
        case 'u':
            username = true;
            break;
        case 'p':
            password = true;
            break;
        case 'w':
            workspace = true;
            break;
        }
            cout<<"command: "<<command<<endl;
    }

    if(checkout)
        orquestrador->checkout(20, "kjdkfj", "kjdkfj", "kjdkfj", "kjdkfj");

    return 0;
}
