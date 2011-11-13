#include "patodatamodel.h"
#include "bdpatodatamodel.h"
#include <algorithm>

PatoDataModel* PatoDataModel::patoDataModel = NULL;

PatoDataModel::PatoDataModel()
{
    iniciouTransacao = false;
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

    iniciouTransacao = true;
    qDebug()<< "salvou transacao";

    bd::BDPatoDataModel::getInstance()->getPathsLastVersion();

    std::map<std::string, int>::iterator itFilePath;
    for( itFilePath = filePath.begin(); itFilePath != filePath.end(); itFilePath++ )
    {
        std::string path = itFilePath->first;
        if ( !saveProjectElement(path, itFilePath->second, project))
                return false;
    }

    dataBase->insertRelationProjectElementTransaction(project);
    dataBase->clear();

    iniciouTransacao = false;

    listPath.clear();

    return true;
}

bool PatoDataModel::saveProjectElement(std::string& filePath, int idFile, std::string& project/*, std::string& previousElement*/)
{
    if ( filePath.empty() )
            return true;

    bd::BDPatoDataModel* dataBase = bd::BDPatoDataModel::getInstance();

    std::string path = getPath(filePath);

    std::string file = getFile(filePath);

    std::list<std::string>::iterator itListPath = std::find(listPath.begin(), listPath.end(), path);
    if ( iniciouTransacao && itListPath == listPath.end() )
    {
        if ( !dataBase->insertFolder(path, project) )
            return false;
    }

    if ( !dataBase->insertFile(path, file/*, project*/, idFile) )
        return false;



    dataBase->insertRelationElement(project, path, file);

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

//File operations>
std::string PatoDataModel::getPath( std::string& pathFile )
{
    int posLastBar = pathFile.rfind("\\");
    std::string path;
    if ( posLastBar > -1 )
    {
        path = pathFile.substr(0, posLastBar);
    }

    return path;
}

std::string PatoDataModel::getFile( std::string& pathFile )
{
    int posLastBar = pathFile.rfind("\\");
    std::string file;
    if ( posLastBar > -1 )
    {
        std::string temp = pathFile.substr(posLastBar, pathFile.length()-posLastBar);
        if ( isFile(temp) )
            file = temp;
    }

    return file;
}

bool PatoDataModel::isFile(std::string &path)
{
    int posTokenFile = path.find(".");
    bool bFile = false;
    if ( posTokenFile != -1 )
        bFile = true;

    return bFile;
}

//<


