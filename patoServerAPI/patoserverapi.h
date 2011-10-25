#ifndef PATOSERVERAPI_H
#define PATOSERVERAPI_H

#include "PatoServerApi_global.h"
#include "../patoDataModel/patodatamodel.h"
#include<QtCore/QString>

using namespace std;

class PATOSERVERAPISHARED_EXPORT PatoServerApi {
private:
    PatoDataModel* dataModel;
    std::vector<std::string> filePath;

public:
    void checkout(int revision, QString path, QString username, QString password);
    void checkin(QString path, QString username, QString password);
    void update(QString revision, QString path, QString username, QString password);

    PatoServerApi();
};

#endif // PATOSERVERAPI_H
