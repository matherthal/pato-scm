#include "patoclientapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>

using namespace std;

PatoClientApi::PatoClientApi() {
}

void PatoClientApi::checkout(int revision, QString address, QString username, QString password, QString workspace) {

    
    QTextStream qout(stdout);
    
    if (revision < -1) {
        cout << "Invalid revision number." << endl;
        return;
    } else if (address == "") {
        cout << "The checkout command needs an address." << endl;
        return;
    } else if (username == "") {
        cout << "The checkout command needs an username." << endl;
        return;
    } else if (password == "") {
        cout << "The checkout command needs a password." << endl;
        return;
    } else if (workspace == "") {
        cout << "The checkout command needs a workspace." << endl;
        return;
    }

    qout << "revision = " << revision << endl;
    qout << "address = " <<  address << endl;
    qout << "username = " << username << endl;
    qout << "password = " << password << endl;
    qout << "workspace = " << workspace << endl;

}

void PatoClientApi::checkin(QString address, QString username, QString password, QString workspace) {

    QTextStream qout(stdout);
    
    if (address == "") {
        cout << "The checkin command needs an address." << endl;
        return;
    } else if (username == "") {
        cout << "The checkin command needs an username." << endl;
        return;
    } else if (password == "") {
        cout << "The checkin command needs a password." << endl;
        return;
    } else if (workspace == "") {
        cout << "The checkin command needs a workspace." << endl;
        return;
    }

    qout << "address = " << address << endl;
    qout << "username = " << username << endl;
    qout << "password = " << password << endl;
    qout << "workspace = " << workspace << endl;

}
