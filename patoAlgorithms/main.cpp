#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
//#include <sys/resource.h>
#include "merge.h"
#include "patch.h"

using namespace std;

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
/*    *seg_CPU_total=0;
    *seg_sistema_to tal=0;

  long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
  struct rusage ptempo;

  getrusage(0,&ptempo);

  seg_CPU = ptempo.ru_utime.tv_sec;
  mseg_CPU = ptempo.ru_utime.tv_usec;
  seg_sistema = ptempo.ru_stime.tv_sec;
  mseg_sistema = ptempo.ru_stime.tv_usec;

 *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
 *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
*/
}


int main(int argc, char *argv[]){

    char type[100];
    char action[100];
    int num=-1;
    if(argc>1){
        strcpy(action,argv[1]);
        if(strcmp(action,"test")==0){
            if(argc>2){
                strcpy(type,argv[2]);
                if(argc>3)
                    num = atoi(argv[3]);
            }else
                strcpy(type,"all");
        }else{
            strcpy(action,"exec");
            strcpy(type,argv[1]);
            if(strcmp(type,"diff")==0){
                if(argc>3){
                    Diff *diffE = new Diff(argv[2],argv[3]);
                    if(argc>4)
                        diffE->getFile(argv[4]);
                    else
                        diffE->print();
                    delete diffE;
                }else{
                    printf("Usage: diff <fileA> <fileB>\n");
                    printf("       diff <fileA> <fileB> <delta_file_path>\n");
                }
                return 0;
            }else if(strcmp(type,"merge")==0){
                if(argc>4){
                    Merge *mergeE = new Merge(argv[3],argv[2],argv[4]);
                    if(mergeE->has_conflict()){
                        printf("Warning: Conflict during the merge!\n");
                    }
                    mergeE->getFile(argv[2]);
                    delete mergeE;
                }else{
                    printf("Usage: merge <fileA> <fileBase> <fileB>\n");
                }
                return 0;
            }else if(strcmp(type,"patch")==0){
                if(argc==4){
                    Patch *patchE = new Patch(argv[2],argv[3]);
                    patchE->print();
                    delete patchE;
                }else if(argc==5 && strcmp(argv[4],"reverse")==0){
                    Patch *patchE = new Patch(argv[2],argv[3],Patch::APPLY_TO_B);
                    patchE->print();
                    delete patchE;
                }else{
                    printf("Usage: patch <delta> <fileA>\n");
                    printf("       patch <delta> <fileB> reverse\n");
                }
                return 0;
            }
        }
    }else{
        strcpy(type,"all");
        strcpy(action,"test");
    }

    double s_CPU_inicial, s_CPU_final, s_total_inicial, s_total_final,t;

    if(strcmp(type,"diff")==0 || strcmp(type,"all")==0){
        int correct = 0;
        printf("=============== DIFF ===============\n");
        if(num==1 || num==-1){
            printf("##### TESTE 1 #####\n");
            Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

            Diff *diff = new Diff("fixtures/arq1.txt","fixtures/arq2.txt");

            Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
            t = s_CPU_final - s_CPU_inicial;

            correct = !diff->isEmpty();
            correct = correct && diff->getDiffItem(0)->getType()==DiffItem::Action_Change;
            correct = correct && diff->getDiffItem(0)->getFromA()==0;
            correct = correct && diff->getDiffItem(0)->getToA()==1;
            correct = correct && diff->getDiffItem(0)->getFromB()==0;
            correct = correct && diff->getDiffItem(0)->getToB()==0;

            correct = correct && diff->getDiffItem(1)->getType()==DiffItem::Action_Delete;
            correct = correct && diff->getDiffItem(1)->getDeleteFrom()==4;
            correct = correct && diff->getDiffItem(1)->getDeleteTo()==4;
            correct = correct && diff->getDiffItem(1)->getAddAfter()==2;

            correct = correct && diff->getDiffItem(2)->getType()==DiffItem::Action_Add;
            correct = correct && diff->getDiffItem(2)->getAddAfter()==5;
            correct = correct && diff->getDiffItem(2)->getFromB()==4;
            correct = correct && diff->getDiffItem(2)->getToB()==4;

            correct = correct && diff->getDiffItem(3) == NULL;

            diff->getFile("fixtures/diff1.txt");
            if(!correct)
                printf("ERRADO!\n\nTempo: %lf\n\n",t);
            else
                printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
            delete diff;
        }

        if(num==2 || num==-1){
            printf("##### TESTE 2 #####\n");
            Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

            Diff *diff2 = new Diff("fixtures/arq1.txt","fixtures/arq1.txt");
            diff2->getFile("fixtures/diff2.txt");
            Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
            t = s_CPU_final - s_CPU_inicial;

            correct = diff2->isEmpty();
            correct = correct && diff2->getDiffItem(0) == NULL;
            if(!correct)
                printf("ERRADO!\n\nTempo: %lf\n\n",t);
            else
                printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
            delete diff2;
        }

        if(num==3 || num==-1){
            printf("##### TESTE 3 #####\n");
            Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

            Diff *diff3 = new Diff("fixtures/boa.txt","fixtures/boa2.txt");
            diff3->getFile("fixtures/diff3.txt");
            Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
            t = s_CPU_final - s_CPU_inicial;

            correct = !diff3->isEmpty();
            correct = correct && diff3->getDiffItem(0)->getType()==DiffItem::Action_Delete;
            correct = correct && diff3->getDiffItem(0)->getDeleteFrom()==2;
            correct = correct && diff3->getDiffItem(0)->getDeleteTo()==2;
            correct = correct && diff3->getDiffItem(0)->getAddAfter()==1;

            correct = correct && diff3->getDiffItem(1)->getType()==DiffItem::Action_Change;
            correct = correct && diff3->getDiffItem(1)->getFromA()==6;
            correct = correct && diff3->getDiffItem(1)->getToA()==6;
            correct = correct && diff3->getDiffItem(1)->getFromB()==5;
            correct = correct && diff3->getDiffItem(1)->getToB()==5;

            correct = correct && diff3->getDiffItem(2)->getType()==DiffItem::Action_Delete;
            correct = correct && diff3->getDiffItem(2)->getDeleteFrom()==10;
            correct = correct && diff3->getDiffItem(2)->getDeleteTo()==10;
            correct = correct && diff3->getDiffItem(2)->getAddAfter()==8;

            correct = correct && diff3->getDiffItem(3)->getType()==DiffItem::Action_Add;
            correct = correct && diff3->getDiffItem(3)->getAddAfter()==15;
            correct = correct && diff3->getDiffItem(3)->getFromB()==14;
            correct = correct && diff3->getDiffItem(3)->getToB()==14;

            correct = correct && diff3->getDiffItem(4) ==NULL;

            if(!correct)
                printf("ERRADO!\n\nTempo: %lf\n\n",t);
            else
                printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
            delete diff3;
        }

        if(num==4 || num==-1){
            printf("##### TESTE 4 #####\n");
            Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

            Diff *diff4 = new Diff("fixtures/grande.txt","fixtures/grande2.txt");
            diff4->getFile("fixtures/diff4.txt");
            Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
            t = s_CPU_final - s_CPU_inicial;

            correct = !diff4->isEmpty();

            correct = correct && diff4->getDiffItem(0)->getType()==DiffItem::Action_Delete;
            correct = correct && diff4->getDiffItem(1)->getType()==DiffItem::Action_Add;
            correct = correct && diff4->getDiffItem(2)->getType()==DiffItem::Action_Change;
            correct = correct && diff4->getDiffItem(3)->getType()==DiffItem::Action_Add;
            correct = correct && diff4->getDiffItem(4)->getType()==DiffItem::Action_Add;
            correct = correct && diff4->getDiffItem(5)->getType()==DiffItem::Action_Change;
            correct = correct && diff4->getDiffItem(6)->getType()==DiffItem::Action_Add;
            correct = correct && diff4->getDiffItem(7) == NULL;

            if(!correct)
                printf("ERRADO!\n\nTempo: %lf\n\n",t);
            else
                printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
            delete diff4;
        }

        if(num==5 || num==-1){
            printf("##### TESTE 5 #####\n");
            string a("pato\nAlgorithm\nWell done.");
            string b("git\nAlgorithm\nnot Well done.");
            Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

            Diff *diff5 = new Diff(a,b);
            cout << diff5->to_string() << endl;
            Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
            t = s_CPU_final - s_CPU_inicial;

            correct = !diff5->isEmpty();

            correct = correct && diff5->getDiffItem(0)->getType()==DiffItem::Action_Change;
            correct = correct && diff5->getDiffItem(1)->getType()==DiffItem::Action_Change;
            correct = correct && diff5->getDiffItem(2) == NULL;

            if(!correct)
                printf("ERRADO!\n\nTempo: %lf\n\n",t);
            else
                printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
            delete diff5;
        }
    }

    if(strcmp(type,"merge")==0 || strcmp(type,"all")==0){
        printf("=============== MERGE ==============\n");

        if(num==1 || num==-1){
            printf("##### TESTE 1 #####\n");
            Merge *merge1 = new Merge("fixtures/base.txt","fixtures/fileA.txt","fixtures/fileB.txt");
            merge1->getFile("fixtures/fileMerge.txt");
            delete merge1;
            Diff *diffM1 = new Diff("fixtures/fileMerge.txt","fixtures/fileMerge.txt.result");
            if(!diffM1->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
        }

        if(num==2 || num==-1){
            printf("##### TESTE 2 #####\n");
            Merge *merge2 = new Merge("fixtures/base.txt","fixtures/fileA2.txt","fixtures/fileB2.txt");
            merge2->getFile("fixtures/fileMerge2.txt");
            delete merge2;
            Diff *diffM2 = new Diff("fixtures/fileMerge2.txt","fixtures/fileA2.txt");
            if(!diffM2->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
        }

        if(num==3 || num==-1){
            printf("##### TESTE 3 #####\n");
            Merge *merge3 = new Merge("fixtures/base.txt","fixtures/fileA3.txt","fixtures/fileB3.txt");
            merge3->getFile("fixtures/fileMerge3.txt");
            delete merge3;
            Diff *diffM3 = new Diff("fixtures/fileMerge3.txt","fixtures/fileB3.txt");
            if(!diffM3->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
        }

        if(num==4 || num==-1){
            printf("##### TESTE 4 #####\n");
            Merge *merge4 = new Merge("fixtures/base.txt","fixtures/fileA4.txt","fixtures/fileB4.txt");
            merge4->getFile("fixtures/fileMerge4.txt");
            delete merge4;
            Diff *diffM4 = new Diff("fixtures/fileMerge4.txt","fixtures/fileB4.txt");
            if(!diffM4->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
        }

        if(num==5 || num==-1){
            printf("##### TESTE 5 #####\n");
            string base  ("Teste do merge\nVamor testar o merge\nMas esse eh com string");
            string dataA ("Teste do merge\nVamor testar o merge\nMas esse eh com o q?");
            string dataB ("Teste do merge\nNao vamos testar o merge\nMas esse eh com string\ntah blz");
            string result("Teste do merge\n<<<<<<< string A\nVamor testar o merge\nMas esse eh com o q?\n=======\nNao vamos testar o merge\nMas esse eh com string\ntah blz\n>>>>>>> string B");
            Merge *merge5 = new Merge(base,dataA,dataB);
            Diff *diffM5 = new Diff(result,merge5->to_string());
            if(!diffM5->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete merge5;
        }
    }


    if(strcmp(type,"patch")==0 || strcmp(type,"all")==0){
        printf("=============== PATCH ==============\n");
        if(num==1 || num==-1){
            printf("##### TESTE 1 #####\n");
            Diff *diffP = new Diff("fixtures/arq1.txt","fixtures/arq2.txt");
            diffP->getFile("fixtures/delta.txt");
            Patch *patch = new Patch("fixtures/delta.txt","fixtures/arq1.txt");
            patch->getFile("fixtures/arq2.txt.patched");
            delete diffP;

            Diff *diffPt = new Diff("fixtures/arq2.txt","fixtures/arq2.txt.patched");
            if(!diffPt->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete diffPt;
        }

        if(num==2 || num==-1){
            printf("##### TESTE 2 #####\n");
            Diff *diffP2 = new Diff("fixtures/boa.txt","fixtures/boa2.txt");
            diffP2->getFile("fixtures/delta.txt");
            Patch *patch2 = new Patch("fixtures/delta.txt","fixtures/boa.txt");
            patch2->getFile("fixtures/boa2.txt.patched");
            delete diffP2;

            Diff *diffPt2 = new Diff("fixtures/boa2.txt","fixtures/boa2.txt.patched");
            if(!diffPt2->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete diffPt2;
        }

        if(num==3 || num==-1){
            printf("##### TESTE 3 #####\n");
            Diff *diffP3 = new Diff("fixtures/grande.txt","fixtures/grande2.txt");
            diffP3->getFile("fixtures/delta.txt");
            Patch *patch3 = new Patch("fixtures/delta.txt","fixtures/grande.txt");
            patch3->getFile("fixtures/grande2.txt.patched");
            delete diffP3;

            Diff *diffPt3 = new Diff("fixtures/grande2.txt","fixtures/grande2.txt.patched");
            if(!diffPt3->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete diffPt3;
        }

        if(num==4 || num==-1){
            printf("##### TESTE 4 #####\n");
            Diff *diffP4 = new Diff("fixtures/grande.txt","fixtures/grande2.txt");
            diffP4->getFile("fixtures/delta.txt");
            Patch *patch4 = new Patch("fixtures/delta.txt","fixtures/grande2.txt",Patch::APPLY_TO_B);
            patch4->getFile("fixtures/grande.txt.patched");
            delete diffP4;

            Diff *diffPt4 = new Diff("fixtures/grande.txt","fixtures/grande.txt.patched");
            if(!diffPt4->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete diffPt4;
        }

        if(num==5 || num==-1){
            printf("##### TESTE 5 #####\n");
            Diff *diffP5 = new Diff("fixtures/arq1.txt","fixtures/arq2.txt");
            diffP5->getFile("fixtures/delta.txt");
            Patch *patch5 = new Patch("fixtures/delta.txt","fixtures/arq2.txt",Patch::APPLY_TO_B);
            patch5->getFile("fixtures/arq1.txt.patched");
            delete diffP5;

            Diff *diffPt5 = new Diff("fixtures/arq1.txt","fixtures/arq1.txt.patched");
            if(!diffPt5->isEmpty())
                printf("Resultado: ERRADO!\n\n");
            else
                printf("Resultado: CORRETO!\n\n");
            delete diffPt5;
        }
    }
    return 0;
}
