#include "patoclientapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
using namespace std;

PatoClientApi::PatoClientApi() {
}

void PatoClientApi::checkout(int revision, char* address, char* username, char* password, char* workspace) {

    if (revision < -1) {
        cout << "Invalid revision number." << endl;
        return;
    } else if (strcmp(address, "")) {
        cout << "The checkout command needs of one address." << endl;
        return;
    } else if (strcmp(username, "")) {
        cout << "The checkout command needs of one username." << endl;
        return;
    } else if (strcmp(password, "")) {
        cout << "The checkout command needs of one password." << endl;
        return;
    } else if (strcmp(workspace, "")) {
        cout << "The checkout command needs of one workspace." << endl;
        return;
    }
    cout << revision << endl;
    cout << address << endl;
    cout << username << endl;
    cout << password << endl;
    cout << workspace << endl;

}

void PatoClientApi::checkin(char* address, char* username, char* password, char* workspace) {

    if (strcmp(address, "")) {
        cout << "The checkin command needs of one address." << endl;
        return;
    } else if (strcmp(username, "")) {
        cout << "The checkin command needs of one username." << endl;
        return;
    } else if (strcmp(password, "")) {
        cout << "The checkin command needs of one password." << endl;
        return;
    } else if (strcmp(workspace, "")) {
        cout << "The checkin command needs of one workspace." << endl;
        return;
    }

    cout << address << endl;
    cout << username << endl;
    cout << password << endl;
    cout << workspace << endl;

}
