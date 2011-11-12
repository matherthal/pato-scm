#ifndef PATCH_H
#define PATCH_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Patch
{
private:
    char* delta_file_name;
    char* file_name;
    string result;
    void createPatchToB();
    void createPatchToA();
public:
    Patch(char* _delta_file_name,char* _file_name);
    void getFile(char* _file_name);
};

#endif // PATCH_H
