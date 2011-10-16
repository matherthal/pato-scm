#include "patofs.h"
#include <iostream>

//constructor
PatoFS::PatoFS() {
	db = QSqlDatabase::addDatabase( "QSQLITE" );
	db.setDatabaseName("DataBase/PatoDB.sqlite");

	if (!db.open()) {
		std::cout << "Erro..." << endl;
	}
	else {
		std::cout << "Ok" << endl;
	}

}

PatoFS* PatoFS::getInstance() 
{

	if (mPatoFS == NULL)
		mPatoFS = new mPatoFS();

	return mPatoFS;
}

void PatoFS::destroyInstance() {


	if (mPatoFS != NULL) {
		delete mPatoFS;
		mPatoFS = NULL;
	}
}
