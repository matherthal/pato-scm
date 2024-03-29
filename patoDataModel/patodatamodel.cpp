#include "patodatamodel.h"
#include "bdpatodatamodel.h"
#include <algorithm>
#include "../patoBase/patotypes.h"

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
bool PatoDataModel::checkIn(std::map<std::string, std::string>& filePath, std::string& project, std::string& loginUser, std::string& message)
{
    bd::BDPatoDataModel* dataBase = bd::BDPatoDataModel::getInstance();
    if ( !dataBase->saveTransaction(message, loginUser) )
        return false;

    iniciouTransacao = true;

    bd::BDPatoDataModel::getInstance()->insertProjectVersion(project);

    bd::BDPatoDataModel::getInstance()->getPathsLastVersion(project);

    std::map<std::string, std::string>::iterator itFilePath;
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

bool PatoDataModel::saveProjectElement(std::string& filePath, std::string& idFile, std::string& project/*, std::string& previousElement*/)
{
    if ( filePath.empty() )
            return true;

    bd::BDPatoDataModel* dataBase = bd::BDPatoDataModel::getInstance();

    std::string path = getPath(filePath);

    std::string file = getFile(filePath);

    //qDebug() << "\n\nInserindo caminho: " << filePath.c_str();

    std::list<std::string>::iterator itListPath = std::find(listPath.begin(), listPath.end(), path);
    if ( iniciouTransacao && itListPath == listPath.end() )
    {
        if ( !dataBase->insertFolder(path, project) )
            return false;

        listPath.push_back(path);
    }

    if ( !dataBase->insertFile(path, file/*, project*/, idFile) )
        return false;

    dataBase->insertRelationElement(project, path, file);

    return true;
}

int PatoDataModel::checkOut(std::string& loginUser, std::string& password, std::string& project, int version, std::map<std::string, std::string>& filePath)
{
    if ( !validateUserProject(loginUser, password, project) )
            return -1;

    return bd::BDPatoDataModel::getInstance()->getFilePath(project, version, filePath);
}

bool PatoDataModel::showLog(std::string& loginUser, std::string& password, std::string& project, int version, PatoLog& log)
{
    if ( !validateUserProject(loginUser, password, project) )
            return false;

    return bd::BDPatoDataModel::getInstance()->getLog(project, version, log);
}


bool PatoDataModel::showLogPathFile(std::string project,  std::string& login, std::string& password, std::string& path, std::vector<PatoLog>& log)
{
    if ( !validateUserProject(login, password, project) )
            return false;

    return bd::BDPatoDataModel::getInstance()->getLogPathFile(project, path, log);
}

bool PatoDataModel::createProject(std::string& project)
{
    return bd::BDPatoDataModel::getInstance()->createProject(project);
}

bool PatoDataModel::insertProjectVersion(std::string& project)
{
    return bd::BDPatoDataModel::getInstance()->insertProjectVersion(project);
}

bool PatoDataModel::createUser(std::string& nameUser, std::string& loginUser,std::string& pass)
{
    return bd::BDPatoDataModel::getInstance()->createUser(nameUser, loginUser, pass);
}

bool PatoDataModel::addUserProject(std::string loginUser, std::string& project)
{
    return bd::BDPatoDataModel::getInstance()->addUserProject(loginUser, project);
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
    int posLastBar = pathFile.rfind("/");
    std::string path;
    if ( posLastBar > -1 )
    {
        path = pathFile.substr(0, posLastBar+1);
    }

    return path;
}

std::string PatoDataModel::getFile( std::string& pathFile )
{
    int posLastBar = pathFile.rfind("/");
    std::string file;
    if ( posLastBar > -1 )
    {
        std::string temp = pathFile.substr(posLastBar+1, pathFile.length()-posLastBar);
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

void PatoDataModel::getCodStorage(std::string& path, std::vector<std::string>& vecCodStorage)
{
    bd::BDPatoDataModel::getInstance()->getCodStorage(path, vecCodStorage);
}

bool PatoDataModel::updateCodStorageFile(std::string& oldKey, std::string& newKey)
{
    return bd::BDPatoDataModel::getInstance()->updateCodStorageFile(oldKey, newKey);
}

//<


