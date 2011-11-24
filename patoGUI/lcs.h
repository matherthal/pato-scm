#ifndef LCS_H
#define LCS_H
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

class Lcs
{
private:
    biglinkedtable ***table;
    hashtable **htableA,**htableB;
    ifstream *fileA,*fileB;
    unsigned int sizeFileA,sizeFileB;
    int sizeHashA,sizeHashB;
    int length;
    t_lcs* lcs;
    t_lcs* lcs_txt(int,int,int*);
    hashtable** init_hash(char*,unsigned int,unsigned int,int*);
    biglinkedtable*** build_linked_table();
    void calculate_lcs();
    void free_lcs(t_lcs*);
    void free_hash(hashtable**,int);
    void free_table(biglinkedtable***,int);
    void add_to_table(int,int,int,int,int,int);
public:
    Lcs(const char* _fileA,const char* _fileB);
    ~Lcs();
    t_lcs* get_lcs();
    int get_length();
    int num_linesA();
    int num_linesB();
    hashtable** get_htableA();
    hashtable** get_htableB();
    char* getLineA(int _num_line);
    char* getLineB(int _num_line);
    int getLineALength(int _num_line);
    int getLineBLength(int _num_line);
};
#endif // LCS_H
