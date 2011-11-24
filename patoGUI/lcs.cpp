#include "lcs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

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

hashtable** Lcs::init_hash(char *arq,unsigned int size,unsigned int i,int *length){
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

Lcs::Lcs(const char *fileNameA,const char *fileNameB)
{
    ifstream fileA,fileB;
    struct stat results;
    if (stat(fileNameA, &results) == 0)
        Lcs::sizeFileA = results.st_size;
    if (stat(fileNameB, &results) == 0)
        Lcs::sizeFileB = results.st_size;
    Lcs::fileA = &fileA;
    Lcs::fileB = &fileB;
    Lcs::fileA->open(fileNameA,fstream::binary);
    Lcs::fileB->open(fileNameB,fstream::binary);
    calculate_lcs();
    Lcs::fileA->close();
    Lcs::fileB->close();
}

Lcs::~Lcs(){
    free_hash(htableA,sizeHashA);
    free_hash(htableB,sizeHashB);
    free_lcs(lcs);
}

void Lcs::calculate_lcs(){
    if(fileA->is_open() && fileB->is_open()){
        char *dataA,*dataB;
        dataA = new char[sizeFileA];
        dataB = new char[sizeFileB];
        fileA->read(dataA,sizeFileA);
        fileB->read(dataB,sizeFileB);
        sizeHashA=0,sizeHashB=0;
        htableA = init_hash(dataA,sizeFileA,0,&sizeHashA);
        htableB = init_hash(dataB,sizeFileB,0,&sizeHashB);
        table = build_linked_table();
        length = 0;
        lcs = lcs_txt(0,0,&length);
        free_table(table,sizeHashA);
    }
}

void Lcs::add_to_table(int i,int j,int indexA,int indexB,int next_i,int next_j){
    if(table[i]==NULL){
        table[i]=(biglinkedtable**)malloc(sizeof(biglinkedtable*)*(sizeHashB));
        memset(table[i],NULL,sizeof(biglinkedtable*)*(sizeHashB));
    }
    table[i][j] = (biglinkedtable*)malloc(sizeof(biglinkedtable));
    table[i][j]->indexA = indexA;
    table[i][j]->indexB = indexB;
    table[i][j]->i = i;
    table[i][j]->j = j;
    if(next_i<sizeHashA && table[next_i] && next_j<sizeHashB){
        table[i][j]->next = table[next_i][next_j];
    }else{
        table[i][j]->next=NULL;
    }
}

t_lcs* Lcs::lcs_txt(int i,int j,int *size){
    if(i>=sizeHashA || j>=sizeHashB){
        *size=0;
        return NULL;
    }
    if(table[i]!=NULL && table[i][j]!=NULL){
        t_lcs *n=NULL,*ret=NULL;
        biglinkedtable *pt = table[i][j];
        while(pt!=NULL){
            if(pt->indexA>=0){
                if(n==NULL)n = (t_lcs*)malloc(sizeof(t_lcs));
                else{
                    n->next = (t_lcs*)malloc(sizeof(t_lcs));
                    n = n->next;
                }
                if(ret==NULL)ret = n;
                *size = *size+1;
                n->indexA = pt->indexA;
                n->indexB = pt->indexB;
                n->next = NULL;
            }
            pt = pt->next;
        }
        //if(ret!=NULL)printf("\n");
        return ret;
    }
    int same = 0;
    if(htableA[i]->hash == htableB[j]->hash){
        if(htableA[i]->length==htableB[j]->length)
            same = strcmp(htableA[i]->line,htableB[j]->line)==0;
    }
    if(same){
        t_lcs *p = lcs_txt(i+1,j+1,size);
        *size = *size+1;
        t_lcs *n = (t_lcs*)malloc(sizeof(t_lcs));
        n->indexA = i;
        n->indexB = j;
        n->next = p;
        add_to_table(i,j,n->indexA,n->indexB,i+1,j+1);
        return n;
    }else{
        int size1=*size;
        int size2=*size;
        t_lcs *p1 = lcs_txt(i+1,j,&size1);
        t_lcs *p2 = lcs_txt(i,j+1,&size2);
        if(size1>=size2){
            add_to_table(i,j,-1,-1,i+1,j);
            *size = size1;
            free_lcs(p2);
            return p1;
        }else{
            add_to_table(i,j,-1,-1,i,j+1);
            *size = size2;
            free_lcs(p1);
            return p2;
        }
    }
}

biglinkedtable*** Lcs::build_linked_table(){
    table = (biglinkedtable***)malloc(sizeof(biglinkedtable**)*(sizeHashA));
    memset(table,NULL,sizeof(biglinkedtable**)*(sizeHashA));
    return table;
}

void Lcs::free_lcs(t_lcs *p){
    if(p!=NULL && p->next==NULL)
        free(p);
    else if(p!=NULL){
        free_lcs(p->next);
        p->next=NULL;
        free(p);
    }
}

void Lcs::free_hash(hashtable** _htable,int size){
    for(int i=0;i<size;i++){
        free(_htable[i]);
    }
    free(_htable);
}

void Lcs::free_table(biglinkedtable*** _table,int _linesA){
    for(int i=0;i<_linesA;i++){
        if(_table[i]!=NULL)free(_table[i]);
    }
    free(_table);
}

t_lcs* Lcs::get_lcs(){
    t_lcs *ret = lcs;
    return ret;
}

int Lcs::get_length(){
    return length;
}

int Lcs::num_linesA(){
    return sizeHashA;
}

int Lcs::num_linesB(){
    return sizeHashB;
}

hashtable** Lcs::get_htableA(){
    return htableA;
}

hashtable** Lcs::get_htableB(){
    return htableB;
}

char* Lcs::getLineA(int _num_line){
    return htableA[_num_line]->line;
}

char* Lcs::getLineB(int _num_line){
    return htableB[_num_line]->line;
}

int Lcs::getLineALength(int _num_line){
    return htableA[_num_line]->length;
}

int Lcs::getLineBLength(int _num_line){
    return htableB[_num_line]->length;
}
