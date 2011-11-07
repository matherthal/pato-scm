#ifndef DIFFITEM_H
#define DIFFITEM_H
#include "lcs.h"
class DiffItem
{
private:
    hashtable** htableA;
    hashtable** htableB;
    int type,fromA,toA,fromB,toB;
public:
    static const int Action_Add = 0;
    static const int Action_Delete = 1;
    static const int Action_Change = 2;
    DiffItem(int _type,int _fromA,int _toA,int _fromB,int _toB,hashtable** htableA,hashtable** htableB);
    ~DiffItem();
    void print();
    int getType();
    int getAddAfter();
    int getDeleteFrom();
    int getDeleteTo();
    int getFromA();
    int getToA();
    int getFromB();
    int getToB();
    char* getLineA(int);
    char* getLineB(int);
    int getLineALength(int _num_line);
    int getLineBLength(int _num_line);
};

#endif // DIFFITEM_H
