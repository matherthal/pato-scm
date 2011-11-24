#ifndef PATOSERVERAPI_H
#define PATOSERVERAPI_H

#include "PatoServerApi_global.h"
#include "../patoDataModel/patodatamodel.h"
#include "../patoFS/patofs.h"
#include<QtCore/QString>

#include "../patoBase/patotypes.h"
#include "../patoBase/patolog.h"
using namespace std;

class PATOSERVERAPISHARED_EXPORT PatoServerApi {
private:
    PatoServerApi();
    ~PatoServerApi();
    //std::map<std::string /*file name*/, std::string /*file key (hash code)*/> filePath;
    map<string, string> file;

    static PatoServerApi* patoServerApi;

public:

    /*Retun a map ( in parameter ) with path of file and the content. If all steps are perfomed correct,
    the function´s return is true*/
    bool checkOut(QString path, QString username, QString password, int revision,
                  std::map<std::string, std::string>& filesCheckOut);

    /*Return true if all the paths are saved in datamodel*/
    bool checkIn(QString project, QString username, QString password, QString message,
                  std::map<std::string, std::string>& filesCheckIn);

    /*Show log of the files involved in a specific revision*/
    bool showLog(QString project, QString username, QString password, int version,
                 PatoLog& log);

    /*Show all the revision that a specific file was involved in the transaction*/
    bool showLogPathFile(QString& project, QString userLogin, QString password, QString& path,
                         std::vector<PatoLog>& vecLog);

    bool validateProject(QString& project);
    bool createProject(QString& project);
    bool validateUser(QString& userLogin, QString& userPass);
    bool createUser(QString& userName, QString& userLogin, QString& userPass );
    bool addUserProject(QString& user, QString project);

    static PatoServerApi* getInstance();
    static void destroyInstance();


};

#endif // PATOSERVERAPI_H
