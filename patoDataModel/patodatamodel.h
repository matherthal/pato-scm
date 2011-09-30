#ifndef PATODATAMODEL_H
#define PATODATAMODEL_H

#include "PatoDataModel_global.h"

class PATODATAMODELSHARED_EXPORT PatoDataModel {
private:
    PatoDataModel();
    static PatoDataModel* mPato;

public:

    //singleton pattern
    static PatoDataModel* getInstance();
    static void destroyInstance();

    //getters and setters
    int getFileKey(QString pFilePath);

};

#endif // PATODATAMODEL_H
