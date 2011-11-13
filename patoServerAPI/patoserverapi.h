#ifndef PATOSERVERAPI_H
#define PATOSERVERAPI_H

#include "PatoServerApi_global.h"
#include "../patoDataModel/patodatamodel.h"
#include "../patoFS/patofs.h"
#include<QtCore/QString>

#include "../patoBase/patotypes.h"

using namespace std;

class PATOSERVERAPISHARED_EXPORT PatoServerApi {
private:
    PatoServerApi();
    ~PatoServerApi();
    //std::map<std::string /*file name*/, std::string /*file key (hash code)*/> filePath;
    map<string, string> file;

    static PatoServerApi* patoServerApi;

public:

    bool checkOut(QString path, QString username, QString password, int revision,
                  std::map<std::string, std::string>& filesCheckOut);

    bool checkIn(QString project, QString username, QString password, QString message,
                  std::map<std::string, std::string>& filesCheckIn);

    bool showLog(QString project, QString username, QString password, QString& message, int version,
                 std::map<std::string, std::string>& filesLog);

    static PatoServerApi* getInstance();
    static void destroyInstance();


};

#endif // PATOSERVERAPI_H
