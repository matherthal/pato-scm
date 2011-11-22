#include "merge.h"
#include <string.h>


Merge::Merge(const char* _fileNameBase,const char* _fileNameA, const char* _fileNameB){
    fileNameA = _fileNameA;
    fileNameB = _fileNameB;
    diff = new Diff(_fileNameA,_fileNameB);
    conflict = false;
    lcs_fileA_base = new Lcs(_fileNameA,_fileNameBase);
    lcs_fileB_base = new Lcs(_fileNameB,_fileNameBase);
    diff = new Diff(_fileNameA,_fileNameB);

    doMerge();
}

void Merge::doMerge(){
    int i=0;
    int lastLine=-1;
    while(diff->getDiffItem(i)!=NULL){
        switch (diff->getDiffItem(i)->getType()){
            case DiffItem::Action_Add:
                insertLines(lcs_fileA_base,lastLine+1,diff->getDiffItem(i)->getAddAfter());
                doAdd(diff->getDiffItem(i));
                lastLine = diff->getDiffItem(i)->getAddAfter();
                break;
            case DiffItem::Action_Delete:
                insertLines(lcs_fileA_base,lastLine+1,diff->getDiffItem(i)->getFromA()-1);
                doDeletion(diff->getDiffItem(i));
                lastLine = diff->getDiffItem(i)->getToA();
                break;
            case DiffItem::Action_Change:                
                insertLines(lcs_fileA_base,lastLine+1,diff->getDiffItem(i)->getFromA()-1);
                doChange(diff->getDiffItem(i));
                lastLine = diff->getDiffItem(i)->getToA();
                break;
        }
        i++;
    }
    insertLines(lcs_fileA_base,lastLine+1,lcs_fileA_base->num_linesA()-1);
}

void Merge::insertLines(Lcs* item, int from,int to){
    for(int i=from;i<=to;i++){
       merge+= item->getLineA(i);
       merge+="\n";
    }
}

void Merge::doAdd(DiffItem* item){
    t_lcs *lcsB = lcs_fileB_base->get_lcs();
    int is_in=1;
    int indexB = item->getFromB();
    while(lcsB!=NULL && indexB<=item->getToB() && is_in){
        if(!is_in_lcs(indexB,lcsB))
            is_in = 0;
        lcsB = lcsB->next;
        indexB++;
    }
    if(!is_in){
        for(int i=item->getFromB();i<=item->getToB();i++){
            merge+= item->getLineB(i);
            merge+="\n";
        }
    }
}

void Merge::doDeletion(DiffItem* item){
    t_lcs *lcsA = lcs_fileA_base->get_lcs();
    int is_in=0;
    int indexA = item->getFromA();
    while(lcsA!=NULL && indexA<=item->getToA()){

        if(is_in_lcs(indexA,lcsA))
            is_in = 1;
        else
            is_in = 0;
        lcsA = lcsA->next;
        indexA++;
    }
    if(!is_in){
        for(int i=item->getFromA();i<=item->getToA();i++){
            merge+= item->getLineA(i);
            merge+="\n";
        }
    }
}

void Merge::doChange(DiffItem* item){
    t_lcs *lcsA = lcs_fileA_base->get_lcs();
    int is_inA=0;
    int is_outA=0;
    int indexA = item->getFromA();
    while(lcsA!=NULL && indexA<=item->getToA()){
        if(!is_in_lcs(indexA,lcsA))
            is_outA++;
        else
            is_inA++;
        indexA++;
    }

    t_lcs *lcsB = lcs_fileB_base->get_lcs();
    int is_inB=0;
    int is_outB=0;
    int indexB = item->getFromB();
    while(lcsB!=NULL && indexB<=item->getToB()){
        if(!is_in_lcs(indexB,lcsB))
            is_outB++;
        else
            is_inB++;
        indexB++;
    }


    if(is_outA==0 && is_inB==0){
        for(int i=item->getFromB();i<=item->getToB();i++){
            merge+= item->getLineB(i);
            merge+="\n";
        }
    }else if(is_inA==0 && is_outB==0){
        for(int i=item->getFromB();i<=item->getToB();i++){
            merge+= item->getLineB(i);
            merge+="\n";
        }
    }else{
        conflict = true;
        merge+=("<<<<<<< ");
        merge+=fileNameA;
        merge+="\n";
        for(int i=item->getFromA();i<=item->getToA();i++){
            merge+= item->getLineA(i);
            merge+="\n";
        }
        merge+=("=======\n");
        for(int i=item->getFromB();i<=item->getToB();i++){
            merge+= item->getLineB(i);
            merge+="\n";
        }
        merge+=(">>>>>>> ");
        merge+=fileNameB;
        merge+="\n";
    }
}
bool Merge::has_conflict(){
    return conflict;
}

bool Merge::is_in_lcs(int index,t_lcs *lcs){
    bool is_in=false;
    while(lcs!=NULL && !is_in){
        is_in = lcs->indexA==index;
        lcs = lcs->next;
    }
    return is_in;
}

Merge::~Merge(){
    delete lcs_fileA_base;
    delete lcs_fileB_base;
    delete diff;
}

void Merge::getFile(char* _file_name){
    ofstream arq;
    arq.open(_file_name);
    arq<<merge;
    arq.close();
}

void Merge::print(){
    cout << merge;
}
