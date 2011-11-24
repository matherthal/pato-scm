/* 
 * File:   mergeCLI.h
 * Author: marapao
 *
 * Created on November 9, 2011, 3:06 AM
 */

#ifndef MERGECLI_H
#define	MERGECLI_H

#include <QString>
#include "../patoBase/patotypes.h"

class mergeCLI {
public:
    mergeCLI();
    mergeCLI(const mergeCLI& orig);
    virtual ~mergeCLI();
    void command(int argc, char** argv);
    void setWorkspace(QString workspace);
    QString getWorkspace() const;
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
    QString workspace;
};

#endif	/* MERGECLI_H */

