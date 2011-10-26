#include "patoclientapi.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QtCore/QString>
#include<QtCore/QTextStream>
#include<QtCore/QDebug>
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
    qout << "address = " << address << endl;
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

void PatoClientApi::add(QString workspace, QList<QString> files)
{
    qWarning() << "Some merge problem below!";
    Q_ASSERT(false);

//    QTextStream qout(stdout);


//    if (workspace == "") {
//        cout << "The add command needs a workspace." << endl;
//        return;
//    } else if (files.isEmpty()) {
//        cout << "The add command needs at least one file to add." << endl;
//        return;TextStream qout(stdout);

//        bool* conversao;
//        int revisionInt = revision.toInt(conversao, 10);



//        if(revision == revision.null){
//            cout<<"revision is null!!!"<<endl;
//        }

//        if (revisionInt < -1) {
//            cout << "Invalid revision number." << endl;
//            return;
//        } else if (address == "") {
//            cout << "The update command needs an address." << endl;
//            return;
//        } else if (username == "") {
//            cout << "The update command needs an username." << endl;
//            return;
//        } else if (password == "") {
//            cout << "The update command needs a password." << endl;
//            return;
//        } else if (workspace == "") {
//            cout << "The update command needs a workspace." << endl;
//            return;
//        }

//        qout << "revision = " << revision << endl;
//        qout << "address = " << address << endl;
//        qout << "username = " << username << endl;
//        qout << "password = " << password << endl;
//        qout << "workspace = " << workspace << endl;
//    }

//    qout << "workspace = " << workspace << endl;

//    QString aux;
//    for (int i = 0; i < files.size(); i++) {
//        aux = files.at(i);
//        qout << "file= " << aux << endl;

//    }

}

void PatoClientApi::status(QString workspace) {

    QTextStream qout(stdout);

    if (workspace == "") {
        cout << "The status command needs a workspace." << endl;
        return;
    }

    qout << "workspace = " << workspace << endl;

}

void PatoClientApi::update(QString revision, QString address, QString username, QString password, QString workspace) {

    
    QTextStream qout(stdout);

    bool* conversao;
    int revisionInt = revision.toInt(conversao, 10);
    
    
    
    if(revision == revision.null){
        cout<<"revision is null!!!"<<endl;
    }
    
    if (revisionInt < -1) {
        cout << "Invalid revision number." << endl;
        return;
    } else if (address == "") {
        cout << "The update command needs an address." << endl;
        return;
    } else if (username == "") {
        cout << "The update command needs an username." << endl;
        return;
    } else if (password == "") {
        cout << "The update command needs a password." << endl;
        return;
    } else if (workspace == "") {
        cout << "The update command needs a workspace." << endl;
        return;
    }

    qout << "revision = " << revision << endl;
    qout << "address = " << address << endl;
    qout << "username = " << username << endl;
    qout << "password = " << password << endl;
    qout << "workspace = " << workspace << endl;

}
