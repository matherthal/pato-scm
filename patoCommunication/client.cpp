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

            //Reading string from the result
            xmlrpc_value * const resultP = result.cValueP;
            const char* res;
            xmlrpc_read_string(&env, resultP, &res);

            //Printing the method return
            cout << "res " << res << "\n";
            string s = res;
            cout << "size " << s.length() << "\n";

            //Transform data received into the format returned (map<string, string>*)
            QByteArray data;
            data = QByteArray::fromRawData(res, s.length());
            //QDataStream dataStream(&data, QIODevice::ReadWrite);

            //First param is size of data
            //qint32 paramsize = (qint32)param[0];
            //Second param is the data, where the files are into
            //char* paramdata = (char*)param[1];
            //qint32 size;

            //Need to iterate over data to get each of the files
            map<string, string> files; //Repository to files, it will be returned by the method
            qint32 size = s.length();
            //dataStream >> size;
            //cout << "datastream size " << size << "\n";
            /*for (int i =0; i < size; i=i+4)
            {
                //Name and the file
                QString first;
                QString second;

                //dataStream >> first;
                //dataStream >> second;

                cout << "files name reading " << first.toStdString() << "\n";
                cout << "files content reading" << second.toStdString() << "\n";

                files[first.toStdString()] = second.toStdString();
            }*/
            /*QByteArray::iterator it;
            for (it = data.begin(); it != data.end(); it++) {
                cout << "data " << QString::fromStdString(it->first) << "\n";
            }*/

            /*
            //Transform data received into the format returned (map<string, string>*)
            QByteArray data;
            char* files;
            int lenght;
            data.fromRawData(files, lenght);
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

    void checkin(QString project, QString username, QString password, QString message, std::map<std::string, std::string> files) {
        try {
            //Declaring important variables to the connection
            string const methodName("checkin");
            string const serverUrl = "http://localhost:8080/RPC2";
            xmlrpc_env env;
            xmlrpc_env_init(&env);
            xmlrpc_c::clientSimple myClient;
            xmlrpc_c::value result;
            xmlrpc_c::paramList methodParams;

            //Adding parameter to paramList
            methodParams.add(xmlrpc_c::value_string(project.toStdString()));
            methodParams.add(xmlrpc_c::value_string(username.toStdString()));
            methodParams.add(xmlrpc_c::value_string(password.toStdString()));
            methodParams.add(xmlrpc_c::value_string(message.toStdString()));

            //Creating Iterator to files
            map<string, string>::iterator it;
            //The files will be stored to "data" to be sent
            QByteArray * data = new QByteArray();
            for ( it = files.begin(); it != files.end(); it++)
            {
                data->append(QString::fromStdString(it->first));
                data->append(QString::fromStdString(it->second));
            }
            std::string s = data->data();
            //Adding files to paramList
            //TODO use xmlrpc_c::value instead of xmlrpc_c::value_string below
            methodParams.add(xmlrpc_c::value_string(s));

            //Calling method through the URL, passing params and receiving the result
            myClient.call(serverUrl, methodName, methodParams, &result);

            //Reading string from the result
            xmlrpc_value * const resultP = result.cValueP;
            //const bool *res = false;
            //xmlrpc_read_bool(&env, resultP, &res);

            //Printing the method return
            //cout << "result= " << res << "\n";

            return;
        } catch (...) {
            cerr << "Client threw unexpected error." << endl;
        }
    }
};


int
main(int argc, char **) {
    cout << "Checkout Test!" << "\n";
    Client* client = new Client();
    client->checkout(1, "http://my.place/project", "matheus", "123123123");

    cout << "\nCheckin Test!" << "\n";
    std::map<std::string, std::string> files;
    files.insert(std::make_pair<std::string, std::string>("./file1.cpp", "teste abc"));
    files.insert(std::make_pair<std::string, std::string>("./file2.cpp", "codigo codigo codigo"));
    client->checkin("p1", "Muhammad Li", "123123", "my first commit", files);

    cout << "\n";
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
