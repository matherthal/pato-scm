/* 
 * File:   utils.h
 * Author: marapao
 *
 * Created on October 23, 2011, 1:33 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#include<QtCore/QString>
#include<iostream>
#include<fstream>
#include <cstdlib>


class utils {
public:
    utils();
    utils(const utils& orig);
    virtual ~utils();
    void SetPath(QString path);
    QString GetPath() const;
    static QString returnPath();
private:
    QString path;

};

#endif	/* UTILS_H */

