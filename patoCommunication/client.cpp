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
            string const methodName("checkout");
            string const serverUrl = "http://localhost:8080/RPC2";
            xmlrpc_env env;
            xmlrpc_env_init(&env);

            xmlrpc_c::clientSimple myClient;
            //const xmlrpc_c::value result;
            //xmlrpc_value * const result = xmlrpc_build_value(&env, "s", "");
            xmlrpc_c::value result;
            //xmlrpc_value * const resultP = xmlrpc_build_value(&env, "s", "");
            xmlrpc_c::paramList methodParams;

            methodParams.add(xmlrpc_c::value_int(revision));
            methodParams.add(xmlrpc_c::value_string(path.toStdString()));
            methodParams.add(xmlrpc_c::value_string(username.toStdString()));
            methodParams.add(xmlrpc_c::value_string(password.toStdString()));

            //myClient.call(serverUrl, methodName, "ii", &result, revision, path.unicode(), username.unicode(), password.unicode());
            //myClient.call(serverUrl, methodName, "ii", revision, path, username, password, &result);
            myClient.call(serverUrl, methodName, methodParams, &result);

            xmlrpc_value * const resultP = result.cValueP;
            const char* res = {0};
            xmlrpc_read_string(&env, resultP, &res);
            cout << "result= " << res << "\n";

            /* Get our state name and print it out. */
            //char* const res = {0};
            //xmlrpc_parse_value(&env, result, "s", res);
            //die_if_fault_occurred(&env);
            //printf("The sum  is %s\n", *res);

            /*

            //int const ret = xmlrpc_c::value_int(result);
            xmlrpc_c::value xrval = xmlrpc_c::value(result);
            //xmlrpc_c::value val;
            xmlrpc_value *const valP = NULL;

            xrval.instantiate(valP);
*/
            //xmlrpc_decompose_value(&env, result, "s", val);
            //Get returned data as vector (for so it was sent)
            //xrval.value(valP);
            //cout << "numero " << static_cast<string>(xrval) << "\n";
            //cout << "numero " << valP << "\n";
            //xmlrpc_c::value_array const arrayLenDat = xmlrpc_c::value_array(result);
            //vector<xmlrpc_c::value> const param(arrayLenDat.vectorValueValue());

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

            //cout << "lenght = " << (qint32)param[0];
            //cout << "lenght = " << param.data();
            //cout << "data = " << (char*)param[1];
            //cout << "data = " << param[1];
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
