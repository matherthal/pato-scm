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

    //getters and setters
    int getFileKey(QString pFilePath);

    //user operations >
    bool validateUser(const string& login, const string& password);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    //<


};

#endif // PATODATAMODEL_H
