/* 
 * File:   addOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 5:22 PM
 */

#include "addOutput.h"

addOutput::addOutput() {
}

addOutput::addOutput(const addOutput& orig) {
}

addOutput::~addOutput() {
}

void addOutput::SetAdded(bool added) {
    this->added = added;
}

bool addOutput::IsAdded() const {
    return added;
}

void addOutput::SetFile(QString file) {
    this->file = file;
}

QString addOutput::GetFile() const {
    return file;
}

