#include <string.h>
#include "merge.h"

Merge::Merge(char* _fileNameBase,char* _fileNameA,char* _fileNameB){
    diff = new Diff(_fileNameA,_fileNameB,Diff::T_Txt);

    Merge::mergeFile = NULL;
    ifstream _fileA,_fileB,_fileBase;
    ofstream _mergeFile;
    Merge::fileA = &_fileA;
    Merge::fileB = &_fileB;
    Merge::fileBase = &_fileBase;
    Merge::fileA->open(_fileNameA,fstream::binary);
    Merge::fileB->open(_fileNameB,fstream::binary);
    Merge::fileBase->open(_fileNameBase,fstream::binary);
    Merge::mergeFile = &_mergeFile;
    Merge::mergeFile->open(_fileNameBase,fstream::binary);
    doMerge();
    Merge::fileA->close();
    Merge::fileB->close();
    Merge::fileBase->close();
}

void Merge::doMerge(){
    int i=0;
    int lastLine=-1;
    while(diff->getDiffItem(i)!=NULL){
        switch (diff->getDiffItem(i)->getType()){
            case DiffItem::Action_Add:
                doAdd(diff->getDiffItem(i));
                break;
            case DiffItem::Action_Delete:
                doDeletion(diff->getDiffItem(i));
                break;
            case DiffItem::Action_Change:
                doChange(diff->getDiffItem(i));
                break;
        }

        i++;
    }
}

void Merge::insertLines(DiffItem* item, int from,int to){
    for(int i=from;i<=to;i++){
        mergeFile->write(item->getLineA(i),sizeof(char)*strlen(item->getLineA(i)));
        mergeFile->write("\n",sizeof(char));
    }
}

void Merge::doAdd(DiffItem* item){
}

void Merge::doDeletion(DiffItem* item){
}

void Merge::doChange(DiffItem* item){

}

Merge::~Merge(){
    if(mergeFile!=NULL)mergeFile->close();
}

ofstream* Merge::getFile(){
    return mergeFile;
}
