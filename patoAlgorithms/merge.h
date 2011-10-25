#ifndef MERGE_H
#define MERGE_H
#include "diff.h"

class Merge
{
private:
    Diff *diff;
    ifstream *fileA;
    ifstream *fileBase;
    ifstream *fileB;
    ofstream *mergeFile;
    void doMerge();
    void doAdd(DiffItem*);
    void doDeletion(DiffItem*);
    void doChange(DiffItem*);
    void insertLines(DiffItem*,int from,int to);
public:
    Merge(char* _fileBase,char* _fileA,char* _fileB);
    ~Merge();
    ofstream* getFile();
};

#endif // MERGE_H
