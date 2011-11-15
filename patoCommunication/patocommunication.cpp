//#include "patocommunication.h"

#include <cstdlib>
#include <string>
#include <iostream>
//#include <xmlrpc-c/girerr.hpp>
//#include <xmlrpc-c/base.hpp>
//#include <xmlrpc-c/client_simple.hpp>

using namespace std;

int
main(int argc, char **) {
/*
    if (argc-1 > 0) {
        cerr << "This program has no arguments" << endl;
        exit(1);
    }

    try {
        string const serverUrl("http://localhost:8080/RPC2");
        string const methodName("checkout");

        xmlrpc_c::clientSimple myClient;
        xmlrpc_c::value result;

        myClient.call(serverUrl, methodName, "ii", &result, 2, 10);

        int const sum = xmlrpc_c::value_int(result);
        // Assume the method returned an integer; throws error if not

        cout << "Result of RPC (sum of 5 and 7): " << sum << endl;

    } catch (exception const& e) {
        cerr << "Client threw error: " << e.what() << endl;
    } catch (...) {
        cerr << "Client threw unexpected error." << endl;
    }
*/
    return 0;
}

/*
PatoCommunication::PatoCommunication()
{
    patoServer = new PatoServerApi();
}

void PatoCommunication::checkout(int revision, QString adress, QString username, QString password)
{
    QString path = PatoCommunication::getPath(adress);
    patoServer->checkout(revision,path,username,password);
}

void PatoCommunication::checkin(QString address, QString username, QString password)
{
    QString path = PatoCommunication::getPath(address);
    patoServer->checkin(path,username,password);
}

QString PatoCommunication::getPath(QString adress)
{
    return "./";
}*/
