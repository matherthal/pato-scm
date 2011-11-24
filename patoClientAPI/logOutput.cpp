/* 
 * File:   logOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 3:46 PM
 */

#include "logOutput.h"

logOutput::logOutput() {
}

logOutput::logOutput(const logOutput& orig) {
}

logOutput::~logOutput() {
}

void logOutput::SetRevision(QString revision) {
    this->revision = revision;
}

QString logOutput::GetRevision() const {
    return revision;
}

void logOutput::SetMessage(QString message) {
    this->message = message;
}

QString logOutput::GetMessage() const {
    return message;
}

void logOutput::SetDate(QString date) {
    this->date = date;
}

QString logOutput::GetDate() const {
    return date;
}

void logOutput::SetName(QString name) {
    this->name = name;
}

QString logOutput::GetName() const {
    return name;
}

