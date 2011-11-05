#ifndef PATOCLIENTAPI_H
#define PATOCLIENTAPI_H

//#include "PatoClientApi_global.h"
#include"PatoClientApi_global.h"
#include"PatoClientException.h"
//#include "../patoWorkspace/patoworkspace.h"
#include<QtCore/QString>

class PatoClientApi {
public:
    void checkout(int revision, QString adress, QString username, QString password, QString workspace);
    void checkin(QString address, QString username, QString password, QString workspace);
    void status(QString workspace);
    void add(QString workspace, QList<QString> files) throw(PatoClientException);
    void update(QString revision, QString adress, QString username, QString password, QString workspace);
    void merge(QString path1, int revision1, QString path2, int revision2, QString workspace);
    void diff(QString path1, int revision1, QString path2, int revision2);
    
    PatoClientApi();
//    void setPworkSpace(PatoWorkspace pworkSpace);
//    PatoWorkspace getPworkSpace() const;

private:
//    PatoWorkspace pworkSpace;
};

#endif // PATOCLIENTAPI_H
