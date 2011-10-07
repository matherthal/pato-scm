#include "diff.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int Diff::use_pd;
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
    //Diff::fileA->close();
    //Diff::fileB->close();
		
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
				//free(lcs_ret);
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

char *cat_plus(biglinkedtable *p,int length){
	if(p==NULL){
		char *ret = (char*)malloc(sizeof(char)*length);
		ret[0]='\0';
		return ret;
	}else{
		return strncat(cat_plus(p->next,length+p->length),p->add,length);
	}
}

char* Diff::lcsTxt(char *arqA,unsigned long a, char *arqB,unsigned long b){
		if(use_pd){
			if(table[a]!=NULL && table[a][b]!=NULL){
				char *tmp = NULL;
				biglinkedtable *p = table[a][b]->next;
				tmp = cat_plus(p,0);
				char *ret = new char[table[a][b]->length];
				strcpy(ret,table[a][b]->add);
				strcat(ret,tmp);
				return ret;
			}
		}
    if(strlen(arqA)<=a || strlen(arqB)<=b){
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
            ret = new char[strlen(tmp)+(fimA-a+1)];//(char*)malloc(sizeof(char)*(strlen(tmp)+(fimA-a+1)));
						if(ret==NULL)printf("not malloced\n");
            for(int j=a;j<fimA+1;j++)
                  ret[j-a] = arqA[j];
						if(use_pd){
							if(table[a]==NULL){
								table[a] = (biglinkedtable**)malloc(sizeof(biglinkedtable*)*(sizeFileB+1));
								memset(table[a], NULL, sizeof(biglinkedtable**)*(sizeFileB+1));
							}
							table[a][b] =  (biglinkedtable*)malloc(sizeof(biglinkedtable));
							table[a][b]->length = strlen(tmp)+(fimA-a+1);
							table[a][b]->add = new char[table[a][b]->length];
							table[a][b]->i = a;
							table[a][b]->j = b;
							strcpy(table[a][b]->add,ret);
							if(table[fimA+1]!=NULL && table[fimA+1][fimB+1] !=NULL)
								table[a][b]->next = table[fimA+1][fimB+1];
							else
								table[a][b]->next = NULL;
						}
            strcat(ret,tmp);
            return ret;

    }else{
            char *p1,*p2;
            p1 = lcsTxt(arqA,fimA+1,arqB,b);
            p2 = lcsTxt(arqA,a,arqB,fimB+1);
            if(strlen(p2)>strlen(p1)){
										if(use_pd){
											if(table[a]==NULL){
												table[a] = (biglinkedtable**)malloc(sizeof(biglinkedtable*)*(sizeFileB+1));
												memset(table[a], NULL, sizeof(biglinkedtable**)*(sizeFileB+1));
											}

											table[a][b] =  (biglinkedtable*)malloc(sizeof(biglinkedtable));
											table[a][b]->length = 0;
											table[a][b]->add = new char[1];
											table[a][b]->i = a;
											table[a][b]->j = b;
											strcpy(table[a][b]->add,"");
											if(table[fimA+1]!=NULL && table[fimA+1][b] !=NULL)
												table[a][b]->next = table[fimA+1][b];
											else
												table[a][b]->next = NULL;
										}
                    return p2;
            }else{
										if(use_pd){
											if(table[a]==NULL){
												table[a] = (biglinkedtable**)malloc(sizeof(biglinkedtable*)*(sizeFileB+1));
												memset(table[a], NULL, sizeof(biglinkedtable**)*(sizeFileB+1));
											}
											table[a][b] =  (biglinkedtable*)malloc(sizeof(biglinkedtable));
											table[a][b]->length = 0;
											table[a][b]->add = new char[1];
											table[a][b]->i = a;
											table[a][b]->j = b;
											strcpy(table[a][b]->add,"");
											if(table[a]!=NULL && table[a][fimB+1] !=NULL)
												table[a][b]->next = table[a][fimB+1];
											else
												table[a][b]->next = NULL;
										}
                    return p1;
            }
    }
}

void Diff::free_table(biglinkedtable*** table){
	if(table!=NULL){
		for(unsigned int i=0;i<sizeFileA+1;i++){
			if(table[i]!=NULL){
				for(unsigned int j=0;j<sizeFileB+1;j++){
					if(table[i][j]!=NULL){
						free(table[i][j]->add);
						table[i][j]->next = NULL;
						free(table[i][j]);
					}
				}
				free(table[i]);
			}
		}
		free(table);
	}
}

char* Diff::lcs(char *arqA, char *arqB, int type){
    char *tmp;
		if(use_pd){
			table = (biglinkedtable***)malloc(sizeof(biglinkedtable**)*(sizeFileA+1));
			printf("setting...\n");
	 		memset(table, NULL, sizeof(biglinkedtable***)*(sizeFileA+1));
			printf("ok\n");
		}
		printf("iniciando...\n");
    if (type == T_Bin)
            tmp = lcsBin(arqA,0,arqB,0);
    else
            tmp = lcsTxt(arqA,0,arqB,0);

		if(use_pd){
			//free_table(table);
		}
    return tmp;
}

bool Diff::isEmpty(){
    return empty;
}
