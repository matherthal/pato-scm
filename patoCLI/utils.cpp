/* 
 * File:   utils.cpp
 * Author: marapao
 * 
 * Created on October 23, 2011, 1:33 PM
 */

#include "utils.h"

utils::utils() {
}

utils::utils(const utils& orig) {
}

utils::~utils() {
}

void utils::SetPath(QString path) {
    this->path = path;
}

QString utils::GetPath() const {
    return path;
}

QString utils::returnPath(){

       system("pwd > caminho.txt");
        FILE* f = fopen("caminho.txt", "r");

        char caminho[300];
        fscanf(f, "%s", caminho);

        fclose(f);

        return (QString) caminho;
}
