#ifndef PATCH_H
#define PATCH_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Patch
{
private:
    int type;
    char* delta_file_name;
    char* file_name;
    string result;
    void createPatchToB();
    void createPatchToA();
public:
    static const int APPLY_TO_B = 0;
    static const int APPLY_TO_A = 1;
    Patch(char* _delta_file_name,char* _file_name);
    Patch(char* _delta_file_name,char* _file_name,int _apply_to);
    void getFile(char* _file_name);
    void print();
};

#endif // PATCH_H
