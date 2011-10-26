#include "diffitem.h"
#include <stdio.h>
#include <stdlib.h>

DiffItem::DiffItem(int _type,int _fromA,int _toA,int _fromB,int _toB,hashtable** _htableA,hashtable** _htableB)
{
    type = _type;
    fromA = _fromA;
    fromB = _fromB;
    toA = _toA;
    toB = _toB;
    htableA = _htableA;
    htableB = _htableB;
}

DiffItem::~DiffItem(){
}

char* DiffItem::getLineA(int _num_line){
    return htableA[_num_line]->line;
}

char* DiffItem::getLineB(int _num_line){
    return htableB[_num_line]->line;
}

int DiffItem::getType(){
    return type;
}

int DiffItem::getAddAfter(){
    if(type==DiffItem::Action_Add)
        return fromA;
    else
        return fromB;
}

int DiffItem::getDeleteFrom(){
    return fromA;
}

int DiffItem::getDeleteTo(){
    return toA;
}

int DiffItem::getFromA(){
    return fromA;
}

int DiffItem::getToA(){
    return toA;
}

int DiffItem::getFromB(){
    return fromB;
}

int DiffItem::getToB(){
    return toB;
}

void DiffItem::print(){
    if(fromA==toA)printf("%d",fromA+1);
    else printf("%d,%d",fromA+1,toA+1);
    if(type==Action_Add)printf("a");
    else if(type==Action_Delete)printf("d");
    else if(type==Action_Change)printf("c");
    if(fromB==toB)printf("%d",fromB+1);
    else printf("%d,%d",fromB+1,toB+1);

    printf("\n");
    if(type!=Action_Add){
        for(int i=fromA;i<=toA;i++){
            printf("< %s\n",htableA[i]->line);
        }
    }

    if(type==Action_Change)
        printf("--------\n");

    if(type!=Action_Delete){
        for(int i=fromB;i<=toB;i++){
            printf("> %s\n",htableB[i]->line);
        }
    }
}
