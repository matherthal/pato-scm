#include "patodatamodel.h"
#include "bdpatodatamodel.h"

PatoDataModel* PatoDataModel::patoDataModel = NULL;

PatoDataModel::PatoDataModel()
{

}

PatoDataModel* PatoDataModel::getInstance() {

    if (patoDataModel == NULL)
        patoDataModel = new PatoDataModel();

    return patoDataModel;
}

void PatoDataModel::destroyInstance() {

    if (patoDataModel != NULL) {
        delete patoDataModel;
        patoDataModel = NULL;
    }
}

bool PatoDataModel::initBD()
{
    return bd::BDPatoDataModel::getInstance()->initBD();
}

//repositoy operations >
bool PatoDataModel::checkIn(std::map<std::string, StorageKey>& filePath, std::string& project, std::string& loginUser, std::string& message)
{
    bd::BDPatoDataModel* dataBase = bd::BDPatoDataModel::getInstance();
    qDebug()<< "inicio";
    if ( !dataBase->saveTransaction(message, loginUser) )
        return false;

    qDebug()<< "salvou transacao";

    std::map<std::string, StorageKey>::iterator itFilePath;
    for( itFilePath = filePath.begin(); itFilePath != filePath.end(); itFilePath++ )
    {
        std::string previousElement;
        std::string path = itFilePath->first;
        if ( !saveProjectElement(path, itFilePath->second, project, previousElement))
                return false;
    }

    dataBase->insertRelationProjectElementTransaction(project);

    return true;
}

bool PatoDataModel::saveProjectElement(std::string& filePath, StorageKey idFile, std::string& project, std::string& previousElement)
{
    if ( filePath.empty() )
            return true;

    bd::BDPatoDataModel* dataBase = bd::BDPatoDataModel::getInstance();

    int posTokenPath = filePath.find("\\");
    std::string element;
    if( posTokenPath != -1)
        element = filePath.substr(0, posTokenPath);
    else
        element = filePath;


    int posTokenFile = element.find(".");
    bool bFile = false;
    if ( posTokenFile != -1 )
        bFile = true;


    if ( bFile )
    {
        if ( !dataBase->insertFile(element, project, idFile) )
                return false;
    }
    else
    {
        //if ( !dataBase->hasFolderInsert(element, project) )
        if ( !dataBase->insertFolder(element, project) )
            return false;
    }

    dataBase->insertRelationElement(project, element, previousElement);

    if (posTokenPath == -1)
        filePath.erase(0, filePath.length());
    else
        filePath.erase(0, posTokenPath+1);

    saveProjectElement(filePath, idFile, project, element);
    return true;
}

bool PatoDataModel::checkOut(std::string& loginUser, std::string& password, std::string& project, int version, std::map<std::string, StorageKey>& filePath)
{
    if ( !validateUserProject(loginUser, password, project) )
            return false;

    return bd::BDPatoDataModel::getInstance()->getFilePath(project, version, filePath);
}

bool PatoDataModel::showLog(std::string& loginUser, std::string& password, std::string& project, int version, std::vector<std::string>& filePath)
{
    if ( !validateUserProject(loginUser, password, project) )
            return false;

    return bd::BDPatoDataModel::getInstance()->getLog(project, version, filePath);
}

//<

//user operations >
bool PatoDataModel::validateUser(const string& login, const string& password)
{
    return bd::BDPatoDataModel::getInstance()->validateUser(login, password);
}

bool PatoDataModel::validateUserProject(const string& login, const string& password, const string& project)
{
    return bd::BDPatoDataModel::getInstance()->validateUserProject(login, password, project);
}
//<

//project operations >
bool PatoDataModel::validateProject( const string& projectName )
{
    return bd::BDPatoDataModel::getInstance()->validateProject(projectName);
}
//<


