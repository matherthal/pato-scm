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
    ifstream *mergeFile;
    void doMerge();
public:
    Merge(char* _fileBase,char* _fileA,char* _fileB);
    ~Merge();
    ifstream getFile();
};

#endif // MERGE_H
