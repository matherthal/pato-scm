/* 
 * File:   PatoClientException.cpp
 * Author: marapao
 * 
 * Created on October 16, 2011, 11:29 AM
 */

#include "PatoClientException.h"
#include "patoclientapi.h"

#include<QtCore/QString>
#include<QtCore/QTextStream>
using namespace std;

PatoClientException::PatoClientException():exception() {
}

PatoClientException::PatoClientException(const PatoClientException& orig):exception() {
}

PatoClientException::PatoClientException(QString mes):exception(){
    message = mes;
}

PatoClientException::~PatoClientException() throw(){
}

void PatoClientException::SetMessage(QString mes) {
    this->message = mes;
}

QString PatoClientException::GetMessage() const {
    return message;
}

QString PatoClientException::Message(){
    return message;
}

