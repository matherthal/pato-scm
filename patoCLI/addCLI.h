/* 
 * File:   addCLI.h
 * Author: marapao
 *
 * Created on October 7, 2011, 10:26 AM
 */

#ifndef ADDCLI_H
#define	ADDCLI_H


#include<QtCore/QString>
#include<QtCore/QList>

class addCLI {
public:
    addCLI();
    addCLI(const addCLI& orig);
    virtual ~addCLI();
    void command(int argc, char** argv);
    void setFiles(QList<QString> files);
    QList<QString> getFiles() const;
    void setWorkspace(QString workspace);
    QString getWorkspace() const;
private:
    QString workspace;
    QList<QString> files;
};

#endif	/* ADDCLI_H */

