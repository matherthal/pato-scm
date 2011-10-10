/* 
 * File:   statusCLI.cpp
 * Author: marapao
 * 
 * Created on October 10, 2011, 7:26 PM
 */

#include "statusCLI.h"

statusCLI::statusCLI() {
}

statusCLI::statusCLI(const statusCLI& orig) {
}

statusCLI::~statusCLI() {
}

void statusCLI::SetPath(QString path) {
    this->path = path;
}

QString statusCLI::GetPath() const {
    return path;
}

