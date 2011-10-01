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

//user operations >
bool PatoDataModel::validateUser(const string& login, const string& password)
{
    return bd::BDPatoDataModel::getInstance()->validateUser(login, password);
}
//<

//project operations >
bool PatoDataModel::validateProject( const string& projectName )
{
    return bd::BDPatoDataModel::getInstance()->validateProject(projectName);
}
//<
