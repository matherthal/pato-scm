/* 
 * File:   updateCLI.cpp
 * Author: marapao
 * 
 * Created on October 7, 2011, 10:40 AM
 */

#include "updateCLI.h"

updateCLI::updateCLI() {
}

updateCLI::updateCLI(const updateCLI& orig) {
}

updateCLI::~updateCLI() {
}

void updateCLI::SetAddress(QString address) {
    this->address = address;
}

QString updateCLI::GetAddress() const {
    return address;
}

void updateCLI::SetPassword(QString password) {
    this->password = password;
}

QString updateCLI::GetPassword() const {
    return password;
}

void updateCLI::SetUsername(QString username) {
    this->username = username;
}

QString updateCLI::GetUsername() const {
    return username;
}

void updateCLI::SetRevision(QString revision) {
    this->revision = revision;
}

QString updateCLI::GetRevision() const {
    return revision;
}

void updateCLI::SetWorkspace(QString workspace) {
    this->workspace = workspace;
}

QString updateCLI::GetWorkspace() const {
    return workspace;
}

