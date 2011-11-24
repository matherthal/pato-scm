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

int DiffItem::getLineALength(int _num_line){
    return htableA[_num_line]->length;
}

int DiffItem::getLineBLength(int _num_line){
    return htableB[_num_line]->length;
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

string DiffItem::to_string(){
    string ss("");
    if(fromA==toA)ss+=(fromA+1);
    else ss+=(fromA+1)+","+toA+1;
    if(type==Action_Add)ss+=("a");
    else if(type==Action_Delete)ss+=("d");
    else if(type==Action_Change)ss+=("c");
    if(fromB==toB)ss+=(fromB+1);
    else ss+=(fromB+1)+","+(toB+1);

    ss+=("\n");
    if(type!=Action_Add){
        for(int i=fromA;i<=toA;i++){
            ss+="< ";
            ss+=htableA[i]->line;
            ss+="\n";
        }
    }

    if(type==Action_Change)
        ss+=("--------\n");

    if(type!=Action_Delete){
        for(int i=fromB;i<=toB;i++){
            ss+="> ";
            ss+=htableB[i]->line;
            ss+="\n";
        }
    }
    return ss;
}

void DiffItem::print(){
    cout << to_string();
}
