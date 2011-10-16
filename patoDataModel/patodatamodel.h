#ifndef PATODATAMODEL_H
#define PATODATAMODEL_H

#include "PatoDataModel_global.h"

#include <string>

using namespace std;

class PATODATAMODELSHARED_EXPORT PatoDataModel {
private:
    PatoDataModel();
    ~PatoDataModel();

    static PatoDataModel* patoDataModel;

public:

    //singleton pattern
    static PatoDataModel* getInstance();
    static void destroyInstance();

    //getters and setters >
    //a set of file keys from the latest version
    int* getFileKey(const string& pFilePath);

    //a set of file keys from a specified version
    int* getFileKey(const string& pFilePath, int version);

    //return the latest version number
    int getLastVersion(const string& pPath);
    //<

    //repositoy operations >
    //<

    //user operations >
    bool validateUser(const string& login, const string& password);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    //<
};

#endif // PATODATAMODEL_H
