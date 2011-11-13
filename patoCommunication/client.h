#ifndef PATOCOMMUNICATION_H
#define PATOCOMMUNICATION_H

//#include "PatoCommunication_global.h"
#include "../patoClientAPI/patoclientapi.h"
#include "../patoServerAPI/patoserverapi.h"

class PATOCOMMUNICATIONSHARED_EXPORT PatoCommunication {
private:
    PatoClientApi* patoClient;
    PatoServerApi* patoServer;

    QString getPath(QString adress);

    string const serverUrl = "http://localhost:8080/RPC2";

public:
    void checkout(int revision, QString adress, QString username, QString password);
    void checkin(QString address, QString username, QString password);

    PatoCommunication();
};

#endif // PATOCOMMUNICATION_H
