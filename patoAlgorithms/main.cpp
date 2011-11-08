#include <stdlib.h>
#include <unistd.h>
#include <iostream>
//#include <sys/resource.h>
#include "merge.h"

using namespace std;

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
    *seg_CPU_total=0;
    *seg_sistema_total=0;
    /*
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
    double s_CPU_inicial, s_CPU_final, s_total_inicial, s_total_final,t;
/*
    printf("##### TESTE 1 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff = new Diff("fixtures/arq1.txt","fixtures/arq2.txt");

    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
    t = s_CPU_final - s_CPU_inicial;

    int correct = 0;
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

    diff->print();
    if(!correct)
        printf("ERRADO!\n\nTempo: %lf\n\n",t);
    else
        printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
    delete diff;


    printf("##### TESTE 2 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff2 = new Diff("fixtures/arq1.txt","fixtures/arq1.txt");
    diff2->print();
    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
    t = s_CPU_final - s_CPU_inicial;

    correct = diff2->isEmpty();
    correct = correct && diff->getDiffItem(0) == NULL;
    if(!correct)
        printf("ERRADO!\n\nTempo: %lf\n\n",t);
    else
        printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
    delete diff2;

    printf("##### TESTE 3 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff3 = new Diff("fixtures/boa.txt","fixtures/boa2.txt");
    diff3->print();
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

    printf("##### TESTE 4 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff4 = new Diff("fixtures/grande.txt","fixtures/grande2.txt");
    diff4->print();
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

*/

    printf("=============== MERGE ==============\n");
    printf("##### TESTE 1 #####\n");
    Merge *merge1 = new Merge("fixtures/base.txt","fixtures/fileA.txt","fixtures/fileB.txt");
    delete merge1;
    printf("\n##### TESTE 2 #####\n");
    Merge *merge2 = new Merge("fixtures/base.txt","fixtures/fileA2.txt","fixtures/fileB2.txt");
    delete merge2;
    printf("\n##### TESTE 3 #####\n");
    Merge *merge3 = new Merge("fixtures/base.txt","fixtures/fileA3.txt","fixtures/fileB3.txt");
    delete merge3;
    printf("\n##### TESTE 4 #####\n");
    Merge *merge4 = new Merge("fixtures/base.txt","fixtures/fileA4.txt","fixtures/fileB4.txt");
    delete merge4;

    return 0;
}
