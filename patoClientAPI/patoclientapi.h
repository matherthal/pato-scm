#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

#include "PatoClientApi_global.h"

class PatoClientApi {
public:
    void checkout(int revision, const char* adress, const char* username, const char* password, const char* workspace);
    PatoClientApi();

};

#endif // PATOCLIENTAPI_H
