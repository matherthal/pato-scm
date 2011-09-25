#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <fstream>
using namespace std;
class Diff
{
private:
    bool empty;
    ifstream *fileA,*fileB;
    void calculateDiff();
public:
    Diff(ifstream*,ifstream*);
    Diff(char*,char*);
    bool isEmpty();

};

#endif // DIFF_H
