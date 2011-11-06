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
int PatoFS::saveData(const std::string& data)
{
    qDebug() << "save Data: ";
    qDebug(data.c_str());
    return bd::BDPatoFS::getInstance()->saveData(data);
}

bool PatoFS::saveData(const std::vector<std::string>& data, std::vector<int>& vecIdFile)
{
    return bd::BDPatoFS::getInstance()->saveData(data, vecIdFile);
}

//loading data
bool PatoFS::loadData(const int idFile, std::string& data)
{
    return bd::BDPatoFS::getInstance()->loadData(idFile, data);
}

bool PatoFS::loadData(const std::vector<int>& vecIdFile, std::vector<std::string>& vecData)
{
    return bd::BDPatoFS::getInstance()->loadData(vecIdFile, vecData);
}
