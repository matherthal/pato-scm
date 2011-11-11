/* 
 * File:   diffCLI.h
 * Author: marapao
 *
 * Created on November 9, 2011, 3:06 AM
 */

#ifndef DIFFCLI_H
#define	DIFFCLI_H


#include<QString>
#include "../patoClientAPI/patoclientapi.h"

class diffCLI {
public:
    diffCLI();
    diffCLI(const diffCLI& orig);
    virtual ~diffCLI();
    void command(int argc, char** argv);
    void setRevision2(RevisionKey revision2);
    RevisionKey getRevision2() const;
    void setPath2(QString path2);
    QString getPath2() const;
    void setRevision1(RevisionKey revision1);
    RevisionKey getRevision1() const;
    void setPath1(QString path1);
    QString getPath1() const;

private:
    QString path1;
    RevisionKey revision1;
    QString path2;
    RevisionKey revision2;
};

#endif	/* DIFFCLI_H */

