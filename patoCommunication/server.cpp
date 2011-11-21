#include "server.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <QtCore/QString>
//#include<QtCore/QTextStream>
#include <QDataStream>

#include <cassert>
#include <stdexcept>
#include <iostream>
#ifdef WIN32
#  include <windows.h>
#else
#  include <unistd.h>
#endif

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#include <XmlRpcCpp.h>

using namespace std;

#ifdef WIN32
  #define SLEEP(seconds) SleepEx(seconds * 1000);
#else
  #define SLEEP(seconds) sleep(seconds);
#endif

//Including patoserverapi
//#include "../patoServerAPI/patoserverapi.h"

typedef std::vector<xmlrpc_c::value> carray;

/*class Server : public xmlrpc_c::method {
public:
    PatoServerApi() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:ii";
            // method's result and two arguments are integers
        this->_help = "This method adds two integers together";
    }*
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {

        int const addend(paramList.getInt(0));
        int const adder(paramList.getInt(1));

        paramList.verifyEnd(2);

        *retvalP = xmlrpc_c::value_int(addend - adder);

        // Sometimes, make it look hard (so client can see what it's like
        // to do an RPC that takes a while).
        if (adder == 1)
            SLEEP(2);
    }
};*/

class checkout : public xmlrpc_c::method {
public:
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {
        xmlrpc_env env;
        xmlrpc_env_init(&env);

        cout << "Checkout" << "\n";
        //Parameters of checkout on ServerAPI
        int revision(paramList.getInt(0));
        string path(paramList.getString(1));
        string username(paramList.getString(2));
        string password(paramList.getString(3));

        //Printing params for Debug
        cout << "Revision: " << revision << "\n";
        cout << "Path:     " << path << "\n";
        cout << "Username: " << username << "\n";
        cout << "Password: " << password << "\n\n";
        cerr << "";

        //Parameters as Qt vars
        QString qpath = QString::fromStdString(path);
        QString quser = QString::fromStdString(username);
        QString qpw = QString::fromStdString(password);

        //---Given a revision get file names and its content---
        //Instancianting PatoServerAPI
        std::map<std::string, std::string> files;
        files.insert(std::make_pair<std::string, std::string>("./file1.cpp", "create { turtle };"));
        files.insert(std::make_pair<std::string, std::string>("./file2.cpp", "access { turtle data };"));
        bool ok = true;//PatoServerApi::getInstance()->checkOut(qpath, quser, qpw, revision, files);
        
        //Calling checkout from PatoServerAPI
        //bool ok = false;
        //ok = serverApiP->checkOut(qpath, quser, qpw, revision, files);
        if (!ok) {
            cout << "Cannot to checkout";
            return;
        }
        //Data received, now it must be disassembled and read

        //Creating Iterator to files
        map<string, string>::iterator it;

        //The files will be stored to "data" to be sent
        QByteArray * data = new QByteArray();
        //QDataStream dataStream(&data, QIODevice::ReadWrite);
        //Size of data is stored to "data" too
        //dataStream << (qint32)files.size();
        //cout << "files size " << (qint32)files.size() << "\n";
        //cout << "datastream status " << dataStream.status() << "\n";
        for ( it = files.begin(); it != files.end(); it++)
        {
            //Get the name and data of files
            //dataStream << QString::fromStdString(it->first);
            //cout << "files name writing " << data << "\n";
            //dataStream << QString::fromStdString(it->second);
            //cout << "files content writing " << it->second << "\n";
            //cout << "datastream status " << dataStream.status() << "\n";
            data->append(QString::fromStdString(it->first));
            data->append(QString::fromStdString(it->second));
        }

        // Build our parameter array.
        //XmlRpcValue param_array = XmlRpcValue::makeArray();
        //param_array.arrayAppendItem(XmlRpcValue::makeString(data.data()));
        //param_array.arrayAppendItem(XmlRpcValue::makeInt(3));
        // *retvalP = XmlRpcValue::makeString(data.data(), data.length());

        //string s = data.data();
        //cout << "data " << s.size() << "\n";
        //*retvalP = xmlrpc_string_new(&env, data.data());


        *retvalP = xmlrpc_string_new(&env, data->data());

        //string s = "matheus";
        //*retvalP = xmlrpc_string_new(&env, s.data());

        // Sometimes, make it look hard (so client can see what it's like
        // to do an RPC that takes a while).
        //if (adder == 1)
        //    SLEEP(2);
    }
};

class checkin : public xmlrpc_c::method {
public:
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {

        cout << "Checkin" << "\n";
        //Parameters of checkout on ServerAPI
        string project(paramList.getString(0));
        string username(paramList.getString(1));
        string password(paramList.getString(2));
        string message(paramList.getString(3));
        string files(paramList.getString(4));

        //Files to be sent
        //TODO: the files (and their name) should be put in a vector e received here through the paramList?
        //or should be put in a map? Or anything else???
        //Anyway, they must be read here, and be passed to serverApiP->checkIn
        //std::map<std::string, std::string> files;
        
        //Printing params for Debug
        cout << "Project:  " << project << "\n";
        cout << "Username: " << username << "\n";
        cout << "Password: " << password << "\n";
        cout << "Message:  " << message << "\n";
        cout << "Files:    " << files << "\n\n";
        cerr << "";

        //Parameters as Qt vars
        QString qproj = QString::fromStdString(project);
        QString quser = QString::fromStdString(username);
        QString qpw = QString::fromStdString(password);
        QString qmsg = QString::fromStdString(message);


        /*
        //---Given a revision get file names and its content---
        //Instancianting PatoServerAPI
        //PatoServerApi* serverApiP = PatoServerApi::getInstance();
        //std::map<std::string, std::string> files;
        std::map<std::string, std::string> files;
        files.insert(std::make_pair<std::string,std::string>("client.cpp","teste abc"));
        //Calling checkout from PatoServerAPI
        bool ok = false;
        //ok = serverApiP->checkIn(qproj, quser, qpw, qmsg, files);
        ok = serverApiP->checkIn(qproj, quser, qpw, qmsg, files);
        if (!ok) {
            cout << "Cannot to checkout";
            *retvalP = xmlrpc_c::value_boolean(false);
            return;
        }*/
        *retvalP = xmlrpc_c::value_boolean(true);
    }
};


class log : public xmlrpc_c::method {
public:
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {
    }
};

int
main(int           const,
     const char ** const) {

    try {
        xmlrpc_c::registry myRegistry;

        //xmlrpc_c::methodPtr const ServerP(new Server);
        xmlrpc_c::methodPtr const checkoutP(new checkout);
        xmlrpc_c::methodPtr const checkinP(new checkin);
        xmlrpc_c::methodPtr const logP(new log);

        //myRegistry.addMethod("PatoServerApi", PatoServerApiP);
        myRegistry.addMethod("checkout", checkoutP);
        myRegistry.addMethod("checkin", checkinP);
        myRegistry.addMethod("log", logP);

        /*xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt()
            .registryP(&myRegistry)
            .portNumber(8080));*/
        xmlrpc_c::serverAbyss myAbyssServer(
            myRegistry, //handler of methods
            8080,
            "xmlrpc_log"
        );

        myAbyssServer.run();
        // xmlrpc_c::serverAbyss.run() never returns
        assert(false);

    } catch (exception const& e) {
        cerr << "Something failed.  " << e.what() << endl;
    }
    return 0;
}
