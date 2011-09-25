#include "diff.h"

Diff::Diff(ifstream *fileA,ifstream *fileB)
{
    Diff::fileA = fileA;
    Diff::fileB = fileB;
}

Diff::Diff(char *fileNameA,char *fileNameB)
{
    ifstream fileA,fileB;
    Diff::fileA = &fileA;
    Diff::fileB = &fileB;
    Diff::fileA->open(fileNameA,fstream::binary);
    Diff::fileB->open(fileNameB,fstream::binary);
}

void Diff::calculateDiff(){
    if(fileA->is_open() && fileB->is_open()){

    }
}

bool Diff::isEmpty(){
    return false;
}
