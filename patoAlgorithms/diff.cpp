#include "diff.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

Diff::Diff(ifstream *fileA,ifstream *fileB, int _type)
{
    Diff::fileA = fileA;
    Diff::fileB = fileB;
    type = _type;
    calculateDiff();
}

Diff::Diff(const char *fileNameA,const char *fileNameB, int _type)
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
    type = _type;
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
        char *lcs_ret = lcs(dataA,dataB,type);
        cout<<lcs_ret<<endl;
        empty = sizeFileA == sizeFileB && strlen(lcs_ret)==sizeFileA;
    }
}

char* Diff::lcsBin(char *arqA,unsigned long a, char *arqB,unsigned long b){
    if(strlen(arqA)==a || strlen(arqB)==b){
            return (char*)"";
    }else if(arqA[a]==arqB[b]){
            char *ret,*tmp;

            tmp = lcsBin(arqA,a+1,arqB,b+1);
            ret = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
            ret[0] = arqA[a];
            strcat(ret,tmp);

            return ret;
    }else{
            char *p1,*p2;
            p1 = lcsBin(arqA,a+1,arqB,b);
            p2 = lcsBin(arqA,a,arqB,b+1);
            if(strlen(p2)>strlen(p1)){
                    return p2;
            }else{
                    return p1;
            }
    }
}

char* Diff::lcsTxt(char *arqA,unsigned long a, char *arqB,unsigned long b){

    if(strlen(arqA)==a || strlen(arqB)==b){
            //cout <<"*";
            return (char*)"\0";
    }

    int i=0;
    int fimA,fimB,iguais;
    fimA = fimB = 0;
    iguais = 1;
    while(!fimA || !fimB){
            if(!fimA && !fimB){
                    if(arqA[a+i] != arqB[b+i])
                            iguais = 0;
                    if(arqA[a+i]=='\n'||arqA[a+i]=='\0')fimA=a+i;
                    if(arqB[b+i]=='\n'||arqB[b+i]=='\0')fimB=b+i;
            }else if(fimA){
                    if(arqB[b+i]=='\n'||arqB[b+i]=='\0')fimB=b+i;
            }	else if(fimB){
                    if(arqA[a+i]=='\n'||arqA[a+i]=='\0')fimA=a+i;
            }
            i++;
    }

    if(iguais)
    {
            char *ret,*tmp;
            tmp = lcsTxt(arqA,fimA+1,arqB,fimB+1);
            ret = (char*)malloc(sizeof(char)*(strlen(tmp)+(fimA-a+1)));
            for(int j=a;j<fimA+1;j++)
                    ret[j-a] = arqA[j];
            //printf("%s%s==",ret,tmp);
            strcat(ret,tmp);
            //printf("%s?\n",ret);
            return ret;

    }else{
            char *p1,*p2;
            p1 = lcsTxt(arqA,fimA+1,arqB,b);
            p2 = lcsTxt(arqA,a,arqB,fimB+1);
            if(strlen(p2)>strlen(p1)){
                    return p2;
            }else{
                    return p1;
            }
    }
}

char* Diff::lcs(char *arqA, char *arqB, int type){
    char *tmp;
    if (type == T_Bin)
            tmp = lcsBin(arqA,0,arqB,0);
    else
            tmp = lcsTxt(arqA,0,arqB,0);
    return tmp;
}

bool Diff::isEmpty(){
    return empty;
}
