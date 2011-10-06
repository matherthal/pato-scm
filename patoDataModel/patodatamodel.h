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

    //return a set of file keys
    int* getFileKey(const string& pFilePath); //keys from latest version
    int* getFileKey(const string& pFilePath, int version);

    int getLastVersion(const string& path);
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
