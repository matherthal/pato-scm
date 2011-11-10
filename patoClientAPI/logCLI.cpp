/* 
 * File:   logCLI.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 4:35 PM
 */

#include "logCLI.h"
#include <QList>

logCLI::logCLI() {
}

logCLI::logCLI(const logCLI& orig) {
}

logCLI::~logCLI() {
}

void logCLI::SetPassword(QString password) {
    this->password = password;
}

QString logCLI::GetPassword() const {
    return password;
}

void logCLI::SetUsername(QString username) {
    this->username = username;
}

QString logCLI::GetUsername() const {
    return username;
}

void logCLI::SetFinalRevision(QString finalRevision) {
    this->finalRevision = finalRevision;
}

QString logCLI::GetFinalRevision() const {
    return finalRevision;
}

void logCLI::SetInitialRevision(QString initialRevision) {
    this->initialRevision = initialRevision;
}

QString logCLI::GetInitialRevision() const {
    return initialRevision;
}

void logCLI::SetAddress(QString address) {
    this->address = address;
}

QString logCLI::GetAddress() const {
    return address;
}

void logCLI::SetParameters(QList<QString> parameters) {
    this->parameters = parameters;
}

QList<QString> logCLI::GetParameters() const {
    return parameters;
}

