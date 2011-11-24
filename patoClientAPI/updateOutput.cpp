/* 
 * File:   updateOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 7:27 PM
 */

#include "updateOutput.h"

updateOutput::updateOutput() {
}

updateOutput::updateOutput(const updateOutput& orig) {
}

updateOutput::~updateOutput() {
}

void updateOutput::SetFile(QString file) {
    this->file = file;
}

QString updateOutput::GetFile() const {
    return file;
}

