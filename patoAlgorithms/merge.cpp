#include <string.h>
#include "merge.h"

Merge::Merge(const char* _fileNameBase,const char* _fileNameA, const char* _fileNameB){
    diff = new Diff(_fileNameA,_fileNameB);

    lcs_fileA_base = new Lcs(_fileNameBase,_fileNameA);
    lcs_fileB_base = new Lcs(_fileNameBase,_fileNameB);
    diff = new Diff(_fileNameA,_fileNameB);
    doMerge();
}

void Merge::doMerge(){
    int i=0;
    int lastLine=-1;
    t_lcs *lcsB = lcs_fileB_base->get_lcs();
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
        printf("%s\n",item->getLineA(i));
       // mergeFile->write(item->getLineA(i),sizeof(char)*strlen(item->getLineA(i)));
       // mergeFile->write("\n",sizeof(char));
    }
}

void Merge::doAdd(DiffItem* item){
    t_lcs *lcsA = lcs_fileA_base->get_lcs();
    int is_in=1;
    int indexA = item->getFromA();
    while(lcsA!=NULL && indexA<item->getToA() && is_in){
        if(indexA!=lcsA->indexA)
            is_in = 0;
        lcsA = lcsA->next;
        indexA++;
    }
    if(is_in){
        for(int i=item->getFromA();i<item->getToA();i++)
            printf("%s\n",item->getLineA(i));
    }
}

void Merge::doDeletion(DiffItem* item){

}

void Merge::doChange(DiffItem* item){
    printf("<<<<<< A\n");
    for(int i=item->getFromA();i<item->getToA();i++){
        printf("%s\n",item->getLineA(i));
    }
    printf("========\n");
    for(int i=item->getFromB();i<item->getToB();i++){
        printf("%s\n",item->getLineB(i));
    }
    printf(">>>>>> B\n");
}

Merge::~Merge(){
    if(mergeFile!=NULL)mergeFile->close();
    delete lcs_fileA_base;
    delete lcs_fileB_base;
    delete diff;
}

ofstream* Merge::getFile(){
    return mergeFile;
}
