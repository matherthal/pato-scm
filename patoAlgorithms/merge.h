#ifndef MERGE_H
#define MERGE_H
#include <fstream>
#include "diff.h"

using namespace std;

class Merge
{
private:
    Diff *diff;
    fstream mergeFile;
    Lcs *lcs_fileA_base;
    Lcs *lcs_fileB_base;
    bool conflict;
    void doMerge();
    void doAdd(DiffItem*);
    void doDeletion(DiffItem*);
    void doChange(DiffItem*);
    void insertLines(Lcs*,int from,int to);
    bool is_in_lcs(int index,t_lcs *lcs);
public:
    Merge(const char* _fileBase,const char* _fileA,const char* _fileB);
    ~Merge();
    fstream getFile();
    bool has_conflict();
};

#endif // MERGE_H
