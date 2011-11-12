#ifndef BDPATODATAMODEL_H
#define BDPATODATAMODEL_H

#include "../../PatoDataModel_global.h"
#include "../../../patoBase/patotypes.h"

//#include "CppSQLite3.h"

#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

using namespace std;

namespace bd {
class PATODATAMODELSHARED_EXPORT BDPatoDataModel
{
private:
    BDPatoDataModel();
    virtual ~BDPatoDataModel();

public:

    //singleton´s pattern functions>
    static BDPatoDataModel* getInstance();
    static void destroyInstance();
     //<

    //init bd
    bool initBD();

    //repository operations>
    bool saveTransaction( std::string& message, std::string loginUser );
    bool saveProjectElement(std::string& filePath, std::string& previousElement);
    int getLastAvailableVersion();

    std::string getNameConfigItem(StorageKey idItemConfig, std::string& project);
    StorageKey getFileIdStored(std::string& nameFile);
    void getCompletePath(StorageKey idItemConfig, std::string& project, std::string& completePath);
    bool getFilePath(std::string& project, int version, std::map<std::string, StorageKey>& filePath);
    bool getLog(std::string& project, int version, std::vector<std::string>&  filePath);
    //<


    //user operations>
    bool validateUser(const string& login, const string& password);
    bool validateUserProject( const std::string& login, const std::string& password, const std::string& project );
    int getUserId(std::string& loginUser);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    int getProjectId(std::string& project);
    //<

    //IC operations>
    std::string getFolderInserted(std::string& folderToInsert, std::string& project);
    bool insertProjectElement(std::string& filePath, std::string& project);
    bool insertRelationElement(std::string& project, std::string& element, std::string& previousElement);
    int  getLastElement( std::string& project, std::string& element );
    int getLastProjectElement(std::string& project);
    //<

    //file operations>
    bool isFile(std::string& path);
    bool insertFile(std::string& filePath, std::string& project, StorageKey idFile);
    void createMapFile(std::vector<std::string>& _mergedPath, std::vector<StorageKey>& _mergedIdFile, std::map<std::string,StorageKey>& _filePath);
    //<

    //folder operations>
    std::string getLastFolder(std::string& path);
    bool hasFolderInsert(std::string& folder, std::string& project);
    bool insertFolder(std::string& filePath, std::string& project);
    //<

    //Relation Project version with elements>
    bool insertRelationProjectElementTransaction(std::string& project);
    bool insertRelationProjectTransaction(const std::string& sqlInsert);
    //<

    //>String operations
    void removeToken(std::string& path, char token);
    //<

private:

    //singleton´s pattern variable
    static BDPatoDataModel *bdPato;

    QSqlDatabase db;
    //CppSQLite3DB dataBase;

    std::vector<std::string> vecFilePath;
    std::vector<StorageKey> vecIdFile;
};

}

#endif // BDPATODATAMODEL_H
