#include "merge.h"

Merge::Merge()
{
}

Merge::Merge(char* _fileNameBase,char* _fileNameA,char* _fileNameB){
    diff = new Diff(_fileNameA,_fileNameB,Diff::T_Txt);

    Merge::mergeFile = NULL;
    ifstream _fileA,_fileB,_fileBase;
    Merge::fileA = &_fileA;
    Merge::fileB = &_fileB;
    Merge::fileBase = &_fileBase;
    Merge::fileA->open(_fileNameA,fstream::binary);
    Merge::fileB->open(_fileNameB,fstream::binary);
    Merge::fileBase->open(_fileNameBase,fstream::binary);
    doMerge();
    Merge::fileA->close();
    Merge::fileB->close();
    Merge::fileBase->close();
}

void Merge::doMerge(){

}

Merge::~Merge(){
    if(mergeFile!=NULL)mergeFile->close();
}

ifstream Merge::getFile(){
    return mergeFile;
}
