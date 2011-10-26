#include "patodatamodel.h"


PatoDataModel::PatoDataModel()
{
}

PatoDataModel* PatoDataModel::getInstance() {

	if (mPato == NULL)
		mPato = new PatoDataModel();

	return mPato;
}

void PatoDataModel::destroyInstance() {

	if (mPato != NULL) {
		delete mPato;
		mPato = NULL;
	}
}
