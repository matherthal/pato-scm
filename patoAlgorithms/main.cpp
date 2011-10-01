#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/resource.h>
#include "diff.h"

using namespace std;

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
  long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
  struct rusage ptempo;

  getrusage(0,&ptempo);

  seg_CPU = ptempo.ru_utime.tv_sec;
  mseg_CPU = ptempo.ru_utime.tv_usec;
  seg_sistema = ptempo.ru_stime.tv_sec;
  mseg_sistema = ptempo.ru_stime.tv_usec;

 *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
 *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}

int main(int argc, char *argv[]){
    double s_CPU_inicial, s_CPU_final, s_total_inicial, s_total_final,t;

    printf("##### TESTE 1 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff = new Diff("fixtures/arq1.txt","fixtures/arq2.txt",Diff::T_Txt);

    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
    t = s_CPU_final - s_CPU_inicial;
    if(diff->isEmpty())
        printf("ERRADO!\n\n");
    else
        printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
    delete diff;


    printf("##### TESTE 2 #####\n");
    Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

    Diff *diff2 = new Diff("fixtures/arq1.txt","fixtures/arq1.txt",Diff::T_Txt);

    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
    t = s_CPU_final - s_CPU_inicial;
    if(!diff2->isEmpty())
        printf("ERRADO!\n\n");
    else
        printf("Resultado: CORRETO!\nTempo: %lf\n\n",t);
    delete diff2;

    return 0;
}
