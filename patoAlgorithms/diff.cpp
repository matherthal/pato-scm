#include "diff.h"

Diff::Diff(ifstream *fileA,ifstream *fileB)
{
    Diff::fileA = fileA;
    Diff::fileB = fileB;
    calculateDiff();
}

Diff::Diff(char *fileNameA,char *fileNameB)
{
    ifstream fileA,fileB;
    Diff::fileA = &fileA;
    Diff::fileB = &fileB;
    Diff::fileA->open(fileNameA,fstream::binary);
    Diff::fileB->open(fileNameB,fstream::binary);
    calculateDiff();
}

Diff::~Diff(){
    Diff::fileA->close();
    Diff::fileB->close();
}

void Diff::calculateDiff(){
    if(fileA->is_open() && fileB->is_open()){
        char dataA,dataB;
        empty = true;
        while(!fileA->eof() && !fileB->eof()){
            fileA->read(&dataA,1);
            fileB->read(&dataB,1);
            if(dataA != dataB)empty = false;
        }
    }
}

bool Diff::isEmpty(){
    return empty;
}
