/* 
 * File:   checkoutOutput.cpp
 * Author: marapao
 * 
 * Created on November 8, 2011, 5:31 PM
 */

#include "checkoutOutput.h"

checkoutOutput::checkoutOutput() {
}

checkoutOutput::checkoutOutput(const checkoutOutput& orig) {
}

checkoutOutput::~checkoutOutput() {
}

void checkoutOutput::SetFile(QString file) {
    this->file = file;
}

QString checkoutOutput::GetFile() const {
    return file;
}

void checkoutOutput::SetStatus(QString status) {
    this->status = status;
}

QString checkoutOutput::GetStatus() const {
    return status;
}

