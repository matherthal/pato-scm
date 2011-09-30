#ifndef PATOWORKSPACE_H
#define PATOWORKSPACE_H

#include "PatoWorkspace_global.h"

class PATOWORKSPACESHARED_EXPORT PatoWorkspace
{

public://STATICS
    static PatoWorkspace* instance();
    static void free();

public:
    //////////////PRIMEIRA FASE//////////////////////
    void checkout(/*files, repoAddress, revision*/);
    void add(/*path*/);
    void /*QList<FileStatus>*/ status();
    void commit(/*revision*/);
    void update(/*files, revision*/);
    void defaultRepositoryAddress();
    /////////////////////////////////////////////////

    //////////////SEGUNDA FASE///////////////////////
    void revert(/*path*/);
    void currentFile(/*path*/);// File
    void originalFile(/*path*/);// File
    void remove(/*path*/);
    void copy(/*originalPath, destinationPath*/);
    /////////////////////////////////////////////////

private:
    PatoWorkspace();
    virtual ~PatoWorkspace();

private:
    static PatoWorkspace* sigleWorkspace;
};

#endif // PATOWORKSPACE_H
