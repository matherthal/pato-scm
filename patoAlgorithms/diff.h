#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <fstream>
using namespace std;

struct biglinkedtable{
	char *add; 
	int length;
	int i,j;
	struct biglinkedtable *next;
};

typedef struct biglinkedtable biglinkedtable;

class Diff
{
private:
		biglinkedtable ***table; 
    bool empty;
    int type;
    ifstream *fileA,*fileB;
    unsigned int sizeFileA,sizeFileB;
    void calculateDiff();
    char* lcsBin(char*,unsigned long, char*,unsigned long);
    char* lcsTxt(char*,unsigned long, char*,unsigned long);
    char* lcs(char*, char*, int);
		void free_table(biglinkedtable***);
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
