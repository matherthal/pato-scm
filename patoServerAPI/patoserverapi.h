#ifndef PATOSERVERAPI_H
#define PATOSERVERAPI_H

#include "PatoServerApi_global.h"
#include "../patoDataModel/patodatamodel.h"
#include "../patoFS/patofs.h"
#include<QtCore/QString>

using namespace std;

class PATOSERVERAPISHARED_EXPORT PatoServerApi {
private:
    PatoDataModel* dataModel;
    PatoFS* storage;
    std::map<std::string, int> filePath;
    map<string, string> file;
    PatoServerApi();

    static PatoServerApi* patoServerApi;

public:
    std::map<std::string, std::string>* checkout(int revision, QString path, QString username, QString password);
    bool checkin(QString path, QString username, QString password);

    static PatoServerApi* getInstance();
    static void destroyInstance();


};

#endif // PATOSERVERAPI_H
