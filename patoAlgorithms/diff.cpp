#include "diff.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int Diff::use_pd;

unsigned int func_hash(char* str, unsigned int len)
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = (hash << 4) + (*str);
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
   }

   return hash;
}

char* init_str(char *str,unsigned int from,unsigned int *to){
    if(str[*to]=='\n'){
        unsigned int length = *to-from;
        char *tmp = (char*)malloc(sizeof(char)*(length+1));
        tmp[length]='\0';
        return tmp;
    }else{
        unsigned int posTmp = *to-from;
        unsigned int posStr = *to;
        *to = *to+1;
        char* tmp = init_str(str,from,to);
        tmp[posTmp]=str[posStr];
        return tmp;
    }
}

hashtable** Diff::init_hash(char *arq,int size,unsigned int i,int *length){
    if(i>=size){
        hashtable** _htable =(hashtable**)malloc(sizeof(hashtable*)* (*length));
        return _htable;
    }else{
        unsigned int pos=i;
        char *str = init_str(arq,i,&pos);
        unsigned int str_length = pos-i;
        int my_pos = *length;
        *length = *length+1;
        hashtable** _htable = init_hash(arq,size,pos+1,length);
        _htable[my_pos] = (hashtable*)malloc(sizeof(hashtable));
        _htable[my_pos]->line = str;
        _htable[my_pos]->length=str_length;
        _htable[my_pos]->hash = func_hash(str,str_length);
        return _htable;
    }
}

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
    Diff::fileA->close();
    Diff::fileB->close();
}

Diff::~Diff(){	
}

void Diff::calculateDiff(){
    if(fileA->is_open() && fileB->is_open()){
        char *dataA,*dataB;
        dataA = new char[sizeFileA];
        dataB = new char[sizeFileB];
        fileA->read(dataA,sizeFileA);
        fileB->read(dataB,sizeFileB);
        sizeHashA=0,sizeHashB=0;
        htableA = init_hash(dataA,sizeFileA,0,&sizeHashA);
        htableB = init_hash(dataB,sizeFileB,0,&sizeHashB);
        if(use_pd)table = build_linked_table();

        int length_lcs = 0;
        t_lcs *p= lcsTxt(0,0,&length_lcs);

        /*
        printf("\nLCS:\n");
        while(p!=NULL){
            printf("%s\n",htableA[p->index]->line);
            p = p->next;
        }*/
        empty = sizeHashA==sizeHashB && length_lcs==sizeHashA;
        if(use_pd)free_table(table,sizeHashA,sizeHashB);
        free_hash(htableA,sizeHashA);
        free_hash(htableB,sizeHashB);
    }
}

char* Diff::lcsBin(char *arqA,unsigned long a, char *arqB,unsigned long b){
    if(strlen(arqA)==a || strlen(arqB)==b){
        return (char*)"";
    }else if(arqA[a]==arqB[b]){
        char *ret,*tmp;

        tmp = lcsBin(arqA,a+1,arqB,b+1);
        ret = new char[strlen(tmp)+1];//(char*)malloc(sizeof(char)*(strlen(tmp)+1));
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

void Diff::add_to_table(int i,int j,int index,int next_i,int next_j){
    if(!use_pd)return;
    if(table[i]==NULL){
        table[i]=(biglinkedtable**)malloc(sizeof(biglinkedtable*)*sizeHashB);
        memset(table[i],NULL,sizeof(biglinkedtable*)*sizeHashB);
    }
    table[i][j] = (biglinkedtable*)malloc(sizeof(biglinkedtable));
    table[i][j]->index = index;
    if(table[next_i]!=NULL && next_i<sizeHashA && next_j<sizeHashB){
        table[i][j]->next = table[next_i][next_j];
    }else
        table[i][j]->next=NULL;
}

t_lcs* Diff::lcsTxt(int i,int j,int *size){
    if(i>=sizeHashA || j>=sizeHashB){
        *size=0;
        return NULL;
    }
    if(use_pd && table[i]!=NULL && table[i][j]!=NULL){
        t_lcs *n=NULL,*ret=NULL;
        biglinkedtable *pt = table[i][j];
        while(pt!=NULL){
            if(pt->index>=0){
                n = (t_lcs*)malloc(sizeof(t_lcs));
                if(ret==NULL)ret = n;
                n->index = pt->index;
                n->next = NULL;
                n = n->next;
            }
            pt = pt->next;
        }
        return ret;
    }
    int same = 0;
    if(htableA[i]->hash == htableB[j]->hash){
        if(htableA[i]->length==htableB[j]->length)
            same = strcmp(htableA[i]->line,htableB[j]->line)==0;
    }
    if(same){
        t_lcs *p = lcsTxt(i+1,j+1,size);
        *size = *size+1;
        t_lcs *n = (t_lcs*)malloc(sizeof(t_lcs));
        n->index = i;
        n->next = p;
        add_to_table(i,j,n->index,i+1,j+1);
        return n;
    }else{
        int size1=*size;
        int size2=*size;
        t_lcs *p1 = lcsTxt(i+1,j,&size1);
        t_lcs *p2 = lcsTxt(i,j+1,&size2);
        if(size1>size2){
            add_to_table(i,j,-1,i+1,j);
            *size = size1;
            free_lcs(p2);
            return p1;
        }else{
            add_to_table(i,j,-1,i,j+1);
            *size = size2;
            free_lcs(p1);
            return p2;
        }
    }
}

biglinkedtable*** Diff::build_linked_table(){
    table = (biglinkedtable***)malloc(sizeof(biglinkedtable**)*sizeHashA);
    memset(table,NULL,sizeof(biglinkedtable**)*sizeHashA);
}

void Diff::free_lcs(t_lcs *p){
    if(p!=NULL && p->next==NULL)
        free(p);
    else if(p!=NULL){
        free_lcs(p->next);
        p->next=NULL;
        free(p);
    }
}

void Diff::free_hash(hashtable** _htable,int size){
    for(int i=0;i<size;i++){
        free(_htable[i]);
    }
    free(_htable);
}

void Diff::free_table(biglinkedtable*** _table,int _linesA, int _linesB){
    for(int i=0;i<_linesA;i++){
        if(_table[i]!=NULL)free(_table[i]);
    }
    free(_table);
}

char* Diff::lcs(char *_arqA, char *_arqB, int type){
    char *tmp;
    if (type == T_Bin)
        tmp = lcsBin(_arqA,0,_arqB,0);
    else{

        //tmp = lcsTxt(0,0);
    }
    return tmp;
}

bool Diff::isEmpty(){
    return empty;
}
