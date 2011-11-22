#ifndef MOCKFILE_H
#define MOCKFILE_H

#include "ifile.h"

class MockFile : public IFile
{
public:
    MockFile();
    MockFile(QString strName);

    bool exists() const;
    bool copy(const QString &newName);
    QString fileName() const;
    bool remove();

    void setExistsResult(bool result);
    void setCopyResult(bool result);
    void setRemoveResult(bool result);

private:
    void construir();

private:
    bool existsResult;
    bool copyResult;
    bool removeResult;
};

#endif // MOCKFILE_H
