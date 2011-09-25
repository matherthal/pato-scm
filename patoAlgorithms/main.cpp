#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "diff.h"

using namespace std;

int main(int argc, char *argv[]){
    Diff *diff = new Diff("fixtures/arq1.txt","fixtures/arq2.txt");
    if(diff->isEmpty())
        cout << "ERRADO!"<<endl;
    else
        cout << "CORRETO[1]!"<<endl;

    diff = new Diff("fixtures/arq1.txt","fixtures/arq1.txt");
    if(!diff->isEmpty())
        cout << "ERRADO!"<<endl;
    else
        cout << "CORRETO[2]!"<<endl;
    delete diff;



    return 0;
}
