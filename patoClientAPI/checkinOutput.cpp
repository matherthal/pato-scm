/* 
 * File:   checkinOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 6:04 PM
 */

#include "checkinOutput.h"

checkinOutput::checkinOutput() {
}

checkinOutput::checkinOutput(const checkinOutput& orig) {
}

checkinOutput::~checkinOutput() {
}

void checkinOutput::SetFile(QString file) {
    this->file = file;
}

QString checkinOutput::GetFile() const {
    return file;
}

void checkinOutput::SetStatus(QString status) {
    this->status = status;
}

QString checkinOutput::GetStatus() const {
    return status;
}

