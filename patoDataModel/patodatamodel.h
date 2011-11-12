#ifndef PATODATAMODEL_H
#define PATODATAMODEL_H

#include "PatoDataModel_global.h"

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class PATODATAMODELSHARED_EXPORT PatoDataModel {
private:
    PatoDataModel();
    static PatoDataModel* patoDataModel;

    bool iniciouTransacao;
    std::list<std::string> listPath;

public:

    //singleton pattern
    static PatoDataModel* getInstance();
    static void destroyInstance();

    bool initBD();
    //getters and setters >
    //a set of file keys from the latest version
    //int* getFileKey(const string& pFilePath);

    //a set of file keys from a specified version
    //int* getFileKey(const string& pFilePath, int version);

    //return the latest version number
    //int getLastVersion(const string& pPath);
    //<

    //repositoy operations >
    bool checkIn(std::map<std::string, int>& filePath, std::string& project, std::string& loginUser, std::string& message);
    bool saveProjectElement(std::string& filePath, int idFile, std::string& project/*, std::string& previousElement*/);
    bool insertRelationProjectElementTransaction();

    bool checkOut(std::string& loginUser, std::string& password, std::string& project, int version, std::map<std::string, int>& filePath);
    bool showLog(std::string& loginUser, std::string& password, std::string& project, int version, std::vector<std::string>& filePath);
    //<

    //user operations >
    bool validateUser(const string& login, const string& password);
    bool validateUserProject(const string& login, const string& password, const string& project);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    //<

    //fileoperations >
    std::string getPath( std::string& pathFile );
    std::string getFile( std::string& pathFile );
    bool isFile(std::string& path);
    //<

};

#endif // PATODATAMODEL_H
