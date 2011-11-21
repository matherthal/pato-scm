#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

//#include "PatoClientApi_global.h"
#include"PatoClientApi_global.h"

class PatoClientApi {
public:
    void checkout(int revision, char* adress, char* username, char* password, char* workspace);
    void checkin(char* address, char* username, char* password, char* workspace);
    PatoClientApi();

};

#endif // PATOCLIENTAPI_H
