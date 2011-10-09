#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <fstream>
using namespace std;

struct biglinkedtable{
    int indexA;
    int indexB;
    int i,j;
    struct biglinkedtable *next;
};
typedef struct biglinkedtable biglinkedtable;

struct hashtable{
    unsigned int hash;
    int length;
    char *line;
};
typedef struct hashtable hashtable;

struct t_lcs{
    int indexA;
    int indexB;
    struct t_lcs *next;
};
typedef struct t_lcs t_lcs;

class Diff
{
private:
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
    void add_to_table(int,int,int,int,int,int);
    void generateDiff(t_lcs*);
public:
    static int use_pd;
    static const int T_Bin = 0;
    static const int T_Txt = 1;
    Diff(ifstream*,ifstream*,int);
    Diff(const char*,const char*,int);
    ~Diff();
    bool isEmpty();
};

#endif // DIFF_H
