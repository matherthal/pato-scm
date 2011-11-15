//#include "client.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <xmlrpc-c/girerr.hpp>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>
#include<QtCore/QString>
#include <QDataStream>

using namespace std;

class Client {
public:

    void checkout(int revision, QString path, QString username, QString password) {
        try {
            //Declaring important variables to the connection
            string const methodName("checkout");
            string const serverUrl = "http://localhost:8080/RPC2";
            xmlrpc_env env;
            xmlrpc_env_init(&env);
            xmlrpc_c::clientSimple myClient;
            xmlrpc_c::value result;
            xmlrpc_c::paramList methodParams;

            //Adding parameter to paramList
            methodParams.add(xmlrpc_c::value_int(revision));
            methodParams.add(xmlrpc_c::value_string(path.toStdString()));
            methodParams.add(xmlrpc_c::value_string(username.toStdString()));
            methodParams.add(xmlrpc_c::value_string(password.toStdString()));

            //Calling method through the URL, passing params and receiving the result
            myClient.call(serverUrl, methodName, methodParams, &result);

            //Reading string from the resultZ
            xmlrpc_value * const resultP = result.cValueP;
            const char* res = {0};
            xmlrpc_read_string(&env, resultP, &res);

            //Printing the method return
            cout << "result= " << res << "\n";


            /*
            //Transform data received into the format returned (map<string, string>*)
            QByteArray data;
            data.fromRawData(char*, lenght);
            QDataStream dataStream(&data, QIODevice::ReadWrite);
            //First param is size of data
            qint32 paramsize = (qint32)param[0];
            //Second param is the data, where the files are into
            char* paramdata = (char*)param[1];

            //Need to iterate over data to get each of the files
            dataStream >> size;
            map<string, string> files; //Repository to files, it will be returned by the method
            for (int i =0; i < size; i++)
            {
                //Name and the file
                QString first;
                QString second;

                dataStream >> first;
                dataStream >> second;

                files[first.toStdString()] = second.toStdString();
            }
            //files[first.toStdString()] = second.toStdString();

                */

            //return map<string, string>;
            return;
        } catch (...) {
            cerr << "Client threw unexpected error." << endl;
        }
    }
};

int
main(int argc, char **) {
    Client* client = new Client();
    client->checkout(1, "http://my.place/project", "matheus", "123123123");


    if (argc-1 > 0) {
        cerr << "This program has no arguments" << endl;
        exit(1);
    }
/*
    try {
        string const methodName("checkout");

        xmlrpc_c::clientSimple myClient;
        xmlrpc_c::value result;

        //myClient.call(serverUrl, methodName, "ii", &result, 2, 10);
        myClient.call(serverUrl, methodName, &result, 2, 10);

        int const sum = xmlrpc_c::value_int(result);
        // Assume the method returned an integer; throws error if not

        cout << "Result of RPC (sum of 5 and 7): " << sum << endl;

    } catch (exception const& e) {
        cerr << "Client threw error: " << e.what() << endl;
    } catch (...) {
        cerr << "Client threw unexpected error." << endl;
    }*/

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
