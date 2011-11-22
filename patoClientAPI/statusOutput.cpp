/* 
 * File:   statusOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 5:04 PM
 */

#include "statusOutput.h"

statusOutput::statusOutput() {
}

statusOutput::statusOutput(const statusOutput& orig) {
}

statusOutput::~statusOutput() {
}

void statusOutput::SetFile(QString file) {
    this->file = file;
}

QString statusOutput::GetFile() const {
    return file;
}

void statusOutput::SetStatus(QString status) {
    this->status = status;
}

QString statusOutput::GetStatus() const {
    return status;
}

