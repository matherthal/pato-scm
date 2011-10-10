#ifndef PATOFS_H
#define PATOFS_H

#include "PatoFS_global.h"

class PATOFSSHARED_EXPORT PatoFS {
private:
    PatoFS();
    ~PatoFS();

    static PatoFS* mPato;

public:
    static PatoFS* getInstance();
    static void destroyInstance();
};

#endif // PATOFS_H
