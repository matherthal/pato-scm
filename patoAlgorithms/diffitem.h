#ifndef DIFFITEM_H
#define DIFFITEM_H
#include <string>
#include "lcs.h"
class PATOALGORITHMSSHARED_EXPORT DiffItem
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
    string to_string();
    string to_string_short();
};

#endif // DIFFITEM_H
