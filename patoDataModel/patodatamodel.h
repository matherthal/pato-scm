#ifndef PATODATAMODEL_H
#define PATODATAMODEL_H

#include "PatoDataModel_global.h"

#include <string>

using namespace std;

class PATODATAMODELSHARED_EXPORT PatoDataModel {
private:
    PatoDataModel();
    static PatoDataModel* patoDataModel;

public:

    //singleton pattern
    static PatoDataModel* getInstance();
    static void destroyInstance();

    //getters and setters >
    int getFileKey(const string& pFilePath);

    int getLastVersion(const string& path);
    //<

    //repositoy operations >

    //version's default value -> 0 (latest version)
    //the idea is return an array of int (all file keys)
    int* checkout(const string& path, int version = 0);

    //we need to define a data structure to represent the file!
    int checkin(unsigned char file[], const string& path);

    //<

    //user operations >
    bool validateUser(const string& login, const string& password);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    //<
};

#endif // PATODATAMODEL_H
