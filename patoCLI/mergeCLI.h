/* 
 * File:   mergeCLI.h
 * Author: marapao
 *
 * Created on November 9, 2011, 3:06 AM
 */

#ifndef MERGECLI_H
#define	MERGECLI_H

#include <QString>

class mergeCLI {
public:
    mergeCLI();
    mergeCLI(const mergeCLI& orig);
    virtual ~mergeCLI();
    void command(int argc, char** argv);
    void setWorkspace(QString workspace);
    QString getWorkspace() const;
    void setRevision2(QString revision2);
    QString getRevision2() const;
    void setPath2(QString path2);
    QString getPath2() const;
    void setRevision1(QString revision1);
    QString getRevision1() const;
    void setPath1(QString path1);
    QString getPath1() const;

private:
QString path1;
    QString revision1;
    QString path2;
    QString revision2;
    QString workspace;
};

#endif	/* MERGECLI_H */

