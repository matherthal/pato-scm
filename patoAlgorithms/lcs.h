#ifndef LCS_H
#define LCS_H
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
#endif // LCS_H
