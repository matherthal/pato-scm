#include "patch.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Patch::Patch(char* _delta_file_name,char* _file_name){
    delta_file_name = _delta_file_name;
    file_name=_file_name;
    createPatchToA();
}

void Patch::createPatchToB(){
    ifstream delta,file;
    delta.open(delta_file_name,fstream::binary);
    file.open(file_name,fstream::binary);
    delta.close();
    file.close();
}

void Patch::createPatchToA(){
    ifstream delta(delta_file_name);
    ifstream file(file_name);
    string action;
    string line;
    char *num;
    char type;
    char c;
    int fromA,toA,fromB,toB,i,j;
    int lastA=0;
    result.assign("");
    while(getline(delta,action)){
        num = new char[action.length()];

        for(i=0;action[i]>='0' && action[i] <='9';i++)num[i] = action[i];
        num[i]='\0';
        fromA = atoi(num);

        if(action[i]==','){
            j=i+1;
            for(i=j;action[i]>='0' && action[i] <='9';i++)num[i-j] = action[i];
            num[i-j]='\0';
            toA = atoi(num);
            type = action[i];
        }else{
            toA = -1;
            type = action[i];
        }

        j=i+1;
        for(i=j;action[i]>='0' && action[i] <='9';i++)num[i-j] = action[i];
        num[i-j]='\0';
        fromB = atoi(num);

        toB = -1;
        if(action[i]==','){
            j=i+1;
            for(i=j;action[i]>='0' && action[i] <='9';i++)num[i-j] = action[i];
            num[i-j]='\0';
            toB = atoi(num);
        }

        for(i=lastA+1;i<fromA;i++){
            getline(file,line);

            result+=line;
            result+="\n";
        }
        lastA = i-1;

        if(type=='c'){
            if(toA<0)getline(delta,line);
            if(toA<0)getline(file,line);
            for(i=fromA;i<=toA;i++)getline(delta,line);
            for(i=fromA;i<=toA;i++)getline(file,line);

            if(toB<0){
                getline(delta,line);

                result+=line;
                result+="\n";
            }
            for(i=fromB;i<=toB;i++){
                getline(delta,line);

                result+=line;
                result+="\n";
            }
        }else if(type=='d'){
            if(toA<0)getline(delta,line);
            for(i=fromA;i<=toA;i++)getline(delta,line);
            if(toA<0)getline(file,line);
            for(i=fromA;i<=toA;i++)getline(file,line);
        }else if(type=='a'){
            getline(file,line);
            result+=line;
            result+="\n";
            if(toB<0){
                getline(delta,line);
                result+=line;
                result+="\n";
            }
            for(i=fromB;i<=toB;i++){
                getline(delta,line);
                result+=line;
                result+="\n";
            }
        }
        lastA = fromA>toA?fromA:toA;
    }

    while(getline(file,line)){
        result+=line;
        result+="\n";

    }
    delta.close();
    file.close();
}

void Patch::getFile(char* _file_name){
    ofstream arq;
    arq.open(_file_name);
    arq<<result;
    arq.close();
}
