#ifndef MERGE_H
#define MERGE_H
#include "diff.h"

class Merge
{
private:
    Diff *diff;
    ofstream *mergeFile;
    Lcs *lcs_fileA_base;
    Lcs *lcs_fileB_base;
    void doMerge();
    void doAdd(DiffItem*);
    void doDeletion(DiffItem*);
    void doChange(DiffItem*);
    void insertLines(DiffItem*,int from,int to);
public:
    Merge(const char* _fileBase,const char* _fileA,const char* _fileB);
    ~Merge();
    ofstream* getFile();
};

#endif // MERGE_H
