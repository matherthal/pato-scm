#ifndef DIFF_H
#define DIFF_H
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
    bool empty;
    int type;
    void calculateDiff(Lcs *lcs);
    void freeDiffItems(t_diff *diff);
    void generateDiff(Lcs*);
    void addDiffItem(DiffItem*);
public:
    Diff(const char*,const char*);
    ~Diff();
    bool isEmpty();
    void print();
    DiffItem* getDiffItem(int _pos);
    void getFile(char* _file_name);
};

#endif // DIFF_H
