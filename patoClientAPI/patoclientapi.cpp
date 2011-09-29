#include "patoclientapi.h"
#include <iostream>
using namespace std;

PatoClientApi::PatoClientApi(){
}



void PatoClientApi::checkout(int revision, const char* adress, const char* username, const char* password, const char* workspace){

    cout<<revision<<endl;
    cout<<adress<<endl;
    cout<<username<<endl;
    cout<<password<<endl;
    cout<<workspace<<endl;
}
