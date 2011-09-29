#include "diff.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

Diff::Diff(ifstream *fileA,ifstream *fileB)
{
    Diff::fileA = fileA;
    Diff::fileB = fileB;
    calculateDiff();
}

Diff::Diff(const char *fileNameA,const char *fileNameB)
{
    ifstream fileA,fileB;
    struct stat results;
    if (stat(fileNameA, &results) == 0)
        Diff::sizeFileA = results.st_size;
    if (stat(fileNameB, &results) == 0)
        Diff::sizeFileB = results.st_size;
    Diff::fileA = &fileA;
    Diff::fileB = &fileB;
    Diff::fileA->open(fileNameA,fstream::binary);
    Diff::fileB->open(fileNameB,fstream::binary);
    calculateDiff();
}

Diff::~Diff(){
    Diff::fileA->close();
    Diff::fileB->close();
}

void Diff::calculateDiff(){
    if(fileA->is_open() && fileB->is_open()){
        char *dataA,*dataB;
        dataA = new char[sizeFileA];
        dataB = new char[sizeFileB];
        fileA->read(dataA,sizeFileA);
        fileB->read(dataB,sizeFileB);
        empty = lcs(dataA,0,dataB,0).length()==0;
    }
}

string Diff::lcs(char *lA, int iA,char *lB,int iB){
    cout << iA<< " "<<iB<<endl;
    if(iA==strlen(lA) || iB == strlen(lB))
        return string("");
    if(lA[iA]==lB[iB]){
        string ret("");
        ret = lA[iA];
        return ret.append(lcs(lA,iA+1,lB,iB+1));
    }
    string s1 = lcs(lA,iA+1,lB,iB);
    string s2 = lcs(lA,iA,lB,iB+1);
    return s1.length()>s2.length()?s1:s2;
}

bool Diff::isEmpty(){
    return empty;
}
