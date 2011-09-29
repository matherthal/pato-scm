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
    unsigned int sizeFileA,sizeFileB;
    void calculateDiff();
    string lcs(char*,int, char*,int);
public:
    Diff(ifstream*,ifstream*);
    Diff(const char*,const char*);
    ~Diff();
    bool isEmpty();

};

#endif // DIFF_H
