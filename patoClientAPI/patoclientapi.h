#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

//#include "PatoClientApi_global.h"
#include"PatoClientApi_global.h"
#include<QtCore/QString>

class PatoClientApi {
public:
    void checkout(int revision, QString adress, QString username, QString password, QString workspace);
    void checkin(QString address, QString username, QString password, QString workspace);
    PatoClientApi();

};

#endif // PATOCLIENTAPI_H
