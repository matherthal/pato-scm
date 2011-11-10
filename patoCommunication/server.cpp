//#include "server.h"

#include <iostream>
#include<stdlib.h>
#include <string.h>
//#include<QtCore/QString>
//#include<QtCore/QTextStream>

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
using namespace std;

#ifdef WIN32
  #define SLEEP(seconds) SleepEx(seconds * 1000);
#else
  #define SLEEP(seconds) sleep(seconds);
#endif


class PatoServerApi : public xmlrpc_c::method {
public:
    /*PatoServerApi() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:ii";
            // method's result and two arguments are integers
        this->_help = "This method adds two integers together";
    }*/
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
};

class checkout : public xmlrpc_c::method {
public:
    /*PatoServerApi() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:ii";
            // method's result and two arguments are integers
        this->_help = "This method adds two integers together";
    }*/
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {

        int const addend(paramList.getInt(0));
        int const adder(paramList.getInt(1));

        paramList.verifyEnd(2);

        *retvalP = xmlrpc_c::value_int(addend + adder + adder);

        // Sometimes, make it look hard (so client can see what it's like
        // to do an RPC that takes a while).
        if (adder == 1)
            SLEEP(2);
    }
};

class checkin : public xmlrpc_c::method {
public:
    /*PatoServerApi() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:ii";
            // method's result and two arguments are integers
        this->_help = "This method adds two integers together";
    }*/
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {

        int const addend(paramList.getInt(0));
        int const adder(paramList.getInt(1));

        paramList.verifyEnd(2);

        *retvalP = xmlrpc_c::value_int(addend + adder + adder);

        // Sometimes, make it look hard (so client can see what it's like
        // to do an RPC that takes a while).
        if (adder == 1)
            SLEEP(2);
    }
};

int
main(int           const,
     const char ** const) {

    try {
        xmlrpc_c::registry myRegistry;

        xmlrpc_c::methodPtr const PatoServerApiP(new PatoServerApi);
        xmlrpc_c::methodPtr const checkoutP(new checkout);
        xmlrpc_c::methodPtr const checkinP(new checkin);

        myRegistry.addMethod("PatoServerApi", PatoServerApiP);
        myRegistry.addMethod("checkout", checkoutP);
        myRegistry.addMethod("checkin", checkinP);

        xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt()
            .registryP(&myRegistry)
            .portNumber(8080));

        myAbyssServer.run();
        // xmlrpc_c::serverAbyss.run() never returns
        assert(false);
    } catch (exception const& e) {
        cerr << "Something failed.  " << e.what() << endl;
    }
    return 0;
}



/*
PatoServerApi::PatoServerApi()
{

    dataModel = PatoDataModel::getInstance();
    storage = PatoFS::getInstance();
}

map<string, string>* PatoServerApi::checkout(int revision, QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return NULL;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return NULL;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return NULL;

    string strUsername = username.toStdString();
    string strPassword = password.toStdString();
    string strPath = path.toStdString();

    if (!dataModel->checkOut(strUsername,strPassword,strPath,revision,filePath))
            return NULL;

    vector<int> key;
    vector<string> content;

    map<string, int>::iterator it;
    for ( it=filePath.begin() ; it != filePath.end(); it++ ) {
        key.push_back((*it).second);
    }

   if (!storage->loadData(key, content))
       return NULL;

   vector<string>::iterator cit;
   for ( it = filePath.begin(), cit = content.begin() ; it != filePath.end(); it++, cit++ ) {

       file[(*it).first] = (*cit);
   }

   return &file;

}

bool PatoServerApi::checkin(QString path, QString username, QString password) {

    if (!dataModel->validateProject(path.toStdString()))
        return false;

    if (!dataModel->validateUser(username.toStdString(),password.toStdString()))
        return false;

    if (!dataModel->validateUserProject(username.toStdString(),password.toStdString(),path.toStdString()))
        return false;

    string message = NULL;
    string strUsername = username.toStdString();
    string strPath = path.toStdString();

    if (!dataModel->checkIn(filePath, strPath, strUsername,message))
        return false;

    return true;
}
*/

