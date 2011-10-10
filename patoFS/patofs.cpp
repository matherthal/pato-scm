#include "patofs.h"


PatoFS::PatoFS()
{
}

PatoFS* PatoFS::getInstance() {

	if (mPato == NULL) {
		mPato = new PatoFS();
	}

	return mPato();
}

void PatoFS::destroyInstance() {

	if (mPato != NULL) {
		delete mPato;
	}
}
