#include "diff.h"
#include <stdlib.h>

Diff::Diff(string dataA,string dataB)
{
    diff = NULL;
    last_diff = NULL;
    first_diff = NULL;
    position = -1;
    Lcs *lcs = new Lcs(dataA,dataB);
    calculateDiff(lcs);
}

Diff::Diff(const char *fileNameA,const char *fileNameB)
{
    diff = NULL;
    last_diff = NULL;
    first_diff = NULL;
    position = -1;
    Lcs *lcs = new Lcs(fileNameA,fileNameB);
    calculateDiff(lcs);
}

Diff::~Diff(){
    freeDiffItems(diff);
}

void Diff::calculateDiff(Lcs *lcs){
    generateDiff(lcs);
    empty = lcs->num_linesA()==lcs->num_linesB() && lcs->get_length()==lcs->num_linesA();
}

void Diff::freeDiffItems(t_diff *_diff){
    if(_diff!=NULL){
        freeDiffItems(_diff->next);
        delete _diff->diffItem;
        free(_diff);
    }
}

void Diff::addDiffItem(DiffItem* _item){
    if(last_diff==NULL){
        position = 0;
        diff = (t_diff*)malloc(sizeof(t_diff));
        diff->diffItem = _item;
        diff->prev = NULL;
        diff->next = NULL;
        diff->pos = position;
        last_diff = diff;
        first_diff = diff;
    }else{
        last_diff->next = (t_diff*)malloc(sizeof(t_diff));
        last_diff->next->diffItem = _item;
        last_diff->next->next = NULL;
        last_diff->next->prev = last_diff;
        last_diff->next->pos = last_diff->pos+1;
        last_diff = last_diff->next;
    }
}

DiffItem* Diff::getDiffItem(int _pos){
    if(diff==NULL)return NULL;
    if(_pos>last_diff->pos)return NULL;
    if(position<_pos){
        do{
            diff = diff->next;
            position = diff->pos;
        }while(position<_pos);
        if(diff==NULL)diff=first_diff;
    }else if(position>_pos){
        do{
            diff = diff->prev;
            position = diff->pos;
        }while(position>_pos);
        if(diff==NULL)diff=last_diff;
    }
    return diff->diffItem;

}

void Diff::print(){
    t_diff *p = first_diff;
    while(p!=NULL){
        p->diffItem->print();
        p = p->next;
    }
}

string Diff::to_delta_string(){
    string diff;
    t_diff *p = first_diff;
    while(p!=NULL){
        diff+= p->diffItem->to_string_short();
        p = p->next;
    }
    return diff;
}

string Diff::to_string(){
    string diff;
    t_diff *p = first_diff;
    while(p!=NULL){
        diff+= p->diffItem->to_string();
        p = p->next;
    }
    return diff;
}

void Diff::generateDiff(Lcs *lcs){
    t_lcs *p = lcs->get_lcs();
    DiffItem *diffitem;
    int lastA=-1,lastB=-1;
    int findA,findB;
    while(p!=NULL){
        findA=p->indexA-lastA-1;
        findB=p->indexB-lastB-1;

        if(findA && findB){
            diffitem = new DiffItem(DiffItem::Action_Change,lastA+1,p->indexA-1,lastB+1,p->indexB-1,lcs->get_htableA(),lcs->get_htableB());
            addDiffItem(diffitem);
        }else if(findA){
            diffitem = new DiffItem(DiffItem::Action_Delete,lastA+1,p->indexA-1,lastB,lastB,lcs->get_htableA(),lcs->get_htableB());
            addDiffItem(diffitem);
        }else if(findB){
            diffitem = new DiffItem(DiffItem::Action_Add,lastA,lastA,lastB+1,p->indexB-1,lcs->get_htableA(),lcs->get_htableB());
            addDiffItem(diffitem);
        }
        lastA = p->indexA;
        lastB = p->indexB;
        p = p->next;
    }
    findA=lcs->num_linesA()-lastA-1;
    findB=lcs->num_linesB()-lastB-1;

    if(findA && findB){
        diffitem = new DiffItem(DiffItem::Action_Change,lastA+1,lcs->num_linesA()-1,lastB+1,lcs->num_linesB()-1,lcs->get_htableA(),lcs->get_htableB());
        addDiffItem(diffitem);
    }else if(findA){
        diffitem = new DiffItem(DiffItem::Action_Delete,lastA+1,lcs->num_linesA()-1,lastB,lastB,lcs->get_htableA(),lcs->get_htableB());
        addDiffItem(diffitem);
    }else if(findB){
        diffitem = new DiffItem(DiffItem::Action_Add,lastA,lastA,lastB+1,lcs->num_linesB()-1,lcs->get_htableA(),lcs->get_htableB());
        addDiffItem(diffitem);
    }

}

void Diff::getFile(char* _file_name){
    ofstream arq;
    arq.open(_file_name);
    t_diff *p = first_diff;
    while(p!=NULL){
        arq<<p->diffItem->to_string_short();
        p = p->next;
    }
    arq.close();
}

bool Diff::isEmpty(){
    return empty;
}
