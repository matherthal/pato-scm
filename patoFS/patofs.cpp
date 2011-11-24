#include "patofs.h"
#include <iostream>
#include "bdpatoFS.h"

PatoFS* PatoFS::mPatoFS = NULL;

//constructor
PatoFS::PatoFS() {

}

PatoFS* PatoFS::getInstance() 
{
    if (mPatoFS == NULL)
        mPatoFS = new PatoFS();

    return mPatoFS;
}

bool PatoFS::destroyInstance() {

    if (mPatoFS != NULL) {
        delete mPatoFS;
        mPatoFS = NULL;

        return true;
    }

    return false;
}

bool PatoFS::initBD()
{
   return bd::BDPatoFS::getInstance()->initBD();
}

//saving data
StorageKey PatoFS::saveData(const std::string& data, std::string& key_last_version)
{
    return bd::BDPatoFS::getInstance()->saveData(data, key_last_version);
}

bool PatoFS::saveData(const std::vector<std::string>& data, std::vector<StorageKey>& vecIdFile, std::vector<StorageKey>& vecDeltaIdFile)
{
    return bd::BDPatoFS::getInstance()->saveData(data, vecIdFile, vecDeltaIdFile);
}

//loading data
bool PatoFS::loadData(StorageKey& idFile, std::string& data)
{
    return bd::BDPatoFS::getInstance()->loadData(idFile, data);
}

bool PatoFS::loadData(const std::vector<StorageKey>& vecIdFile, std::vector<std::string>& vecData)
{
    return bd::BDPatoFS::getInstance()->loadData(vecIdFile, vecData);
}
