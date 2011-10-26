#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <fstream>
#include <vector>
#include "lcs.h"
#include "diffitem.h"

using namespace std;

struct t_diff{
    DiffItem *diffItem;
    int pos;
    struct t_diff *prev;
    struct t_diff *next;
};
typedef struct t_diff t_diff;

class Diff
{
private:
    t_diff *diff;
    int position;
    t_diff *last_diff;
    t_diff *first_diff;
    biglinkedtable ***table;
    hashtable **htableA,**htableB;
    bool empty;
    int type;
    ifstream *fileA,*fileB;
    unsigned int sizeFileA,sizeFileB;
    int sizeHashA,sizeHashB;
    void calculateDiff();
    char* lcsBin(char*,unsigned long, char*,unsigned long);
    t_lcs* lcsTxt(int,int,int*);
    char* lcs(char*, char*, int);
    hashtable** init_hash(char*,int,unsigned int,int*);
    biglinkedtable*** build_linked_table();
    void free_lcs(t_lcs*);
    void free_hash(hashtable**,int);
    void free_table(biglinkedtable***,int,int);
    void freeDiffItems(t_diff *diff);
    void add_to_table(int,int,int,int,int,int);
    void generateDiff(t_lcs*);
    void addDiffItem(DiffItem*);
public:
    static int use_pd;
    static const int T_Bin = 0;
    static const int T_Txt = 1;
    Diff(ifstream*,ifstream*,int);
    Diff(const char*,const char*,int);
    ~Diff();
    bool isEmpty();
    void print();
    DiffItem* getDiffItem(int _pos);
};

#endif // DIFF_H
