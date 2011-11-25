#ifndef BDPATODATAMODEL_H
#define BDPATODATAMODEL_H

#include "../../PatoDataModel_global.h"

#include "CppSQLite3.h"

#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <QtSql>
#include "../../../patoBase/patolog.h"

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

    std::string getNameConfigItem(int idItemConfig, std::string& project);
    std::string getFileIdStored(std::string& nameFile);
    void getCompletePath(int idItemConfig, std::string& project, std::string& completePath);
    bool getFilePath(std::string& project, int version, std::map<std::string, std::string>& filePath);
    bool getLog(std::string& project, int version, PatoLog&  log);
    void getInfoTransaction(std::string& project, int version, PatoLog& log);

    bool getLogPathFile(std::string project,std::string& path, std::vector<PatoLog>& message);
    //<


    //user operations>
    bool validateUser(const string& login, const string& password);
    bool validateUserProject( const std::string& login, const std::string& password, const std::string& project );
    int getUserId(std::string& loginUser);
    bool createUser(std::string& nameUser, std::string& loginUser,std::string& pass);
    bool addUserProject(std::string loginUser, std::string& project);
    //<

    //project operations>
    bool validateProject( const string& projectName );
    int getProjectId(std::string& project);
    bool createProject(std::string& project);
    bool insertProjectVersion(std::string& project);
    int getIdProjectLastVersion(std::string& project);
    int getIdProjectVersion(std::string& project, int version);
    int getIdProjectPreviusVersion(std::string& project);
    void getIdProjectAllVersion(std::string& project, std::vector<int>& vecIdProject);
    void getOutputOracleIn(std::vector<int>& vecIdProject, std::string& strAllIdProject);
    //<

    //IC operations>
    std::string getFolderInserted(std::string& folderToInsert, std::string& project);
    int getLastVersionFolder(std::string& filePath);
    bool insertRelationElement(std::string& project, std::string& path, std::string& file);
    int  getLastElement( std::string& project, std::string& element );
    int getLastProjectElement(std::string& project);
    //<

    //file operations>
    bool isFile(std::string& path);
    bool getPathsLastVersion(std::string& project);
    bool findPathLastVersion(std::string path);
    int getLastVersionFile(std::string& file);
    bool insertFile(std::string& path, std::string& file, /*std::string& project,*/ std::string& idFile);
    int getIdLastFile(std::string& file);
    void createMapFile(std::vector<std::string>& _mergedPath, std::vector<std::string>& _mergedIdFile, std::map<std::string,std::string>& _filePath);
    void getCodStorage(std::string& path, std::vector<std::string>& vecCodStorage);
    bool updateCodStorageFile(std::string& oldKey, std::string& newKey);
    //<

    //folder operations>
    std::string getLastFolder(std::string& path);
    int getIdLastFolder(std::string& path);
    bool hasFolderInsert(std::string& folder, std::string& project);
    bool insertFolder(std::string& filePath, std::string& project);
    //<

    //Relation Project version with elements>
    bool insertRelationProjectElementTransaction(std::string& project);
    bool insertRelationProjectTransaction(const std::string& sqlInsert);
    void removePathPreviousTransaction(std::string path);
    //<

    //>String operations
    void removeToken(std::string& path, char token);
    //<

    bool clear();
private:

    //singleton´s pattern variable
    static BDPatoDataModel *bdPato;

    QSqlDatabase db;
    //CppSQLite3DB dataBase;



    std::vector<std::string> vecFilePath;
    std::vector<std::string> vecIdFile;

    std::list<std::string> listPathLastVersion;
};

}

#endif // BDPATODATAMODEL_H
