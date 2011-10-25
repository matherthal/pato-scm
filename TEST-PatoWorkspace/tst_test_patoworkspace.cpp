#include <QtCore/QString>
#include <QtTest/QtTest>
#include "../patoWorkspace/patoworkspace.h"

const QString testDIR  = QString("./testDIR/");
const QString testTMP  = QString("./testTMP/");
const QString testCASE = QString("./testWSCASE/");

const QStringList testFLIST = QStringList() << "patoworkspace.cpp" << "pasta1/PatoWorkspace.pro" << "patoworkspace.h";

class TEST_PatoWorkspace : public QObject
{
    Q_OBJECT

public:
    TEST_PatoWorkspace();

    bool clear();
    bool filesExist(QString dir, QStringList files);

private Q_SLOTS:
    void testCaseCreate();
    void testCaseTryToCreate();
    void testCaseOpen();
    void testCaseSetRevision();
    void testCaseAdd();
    void testCaseSetRevisionCommiting();
    void testCaseChanges();
    void testCaseStatus();
};


bool TEST_PatoWorkspace::clear()
{
    system( QString("rm -rf %1").arg(testDIR).toStdString().c_str() );

    return !QDir(testDIR).exists();
}

bool TEST_PatoWorkspace::filesExist(QString dir, QStringList files)
{
    for (int i = 0; i < files.size(); i++)
    {
        if ( !QFile(dir + files[i]).exists() )
        {
            qDebug() << "File missing: " << files[i];
            return false;
        }
    }

    return true;
}

TEST_PatoWorkspace::TEST_PatoWorkspace()
{
}

void TEST_PatoWorkspace::testCaseTryToCreate()
{
    QStringList fileList = testFLIST;

    QVERIFY(PatoWorkspace::instance()->setPath(testDIR));

    if ( PatoWorkspace::instance()->create(testCASE, fileList, QDir(testCASE).absolutePath(), 0) )
    {
        QVERIFY( PatoWorkspace::instance()->revision() == 0 );
    }
    else
    {
        qDebug() << PatoWorkspace::instance()->getLastError();
        QVERIFY( false );
    }

    QVERIFY2(filesExist(testDIR, fileList), "One or more files missing");
}

void TEST_PatoWorkspace::testCaseCreate()
{
    QVERIFY2(clear(), "Unable to clear test output dir");

    QStringList fileList = testFLIST;

    QVERIFY(PatoWorkspace::instance()->setPath(testDIR,true));

    if ( PatoWorkspace::instance()->create(testCASE, fileList, QDir(testCASE).absolutePath(), 0) )
    {
        QVERIFY( PatoWorkspace::instance()->revision() == 0 );
    }
    else
    {
        qDebug() << PatoWorkspace::instance()->getLastError();
        QVERIFY( false );
    }

    QVERIFY2(filesExist(testDIR, fileList), "One or more files missing");
}

//open a repository
void TEST_PatoWorkspace::testCaseOpen()
{
    QVERIFY(PatoWorkspace::instance()->setPath(testDIR));

    QVERIFY2( PatoWorkspace::instance()->isReady(), "Error: not ready yet" );
}

void TEST_PatoWorkspace::testCaseSetRevision()
{

}

void TEST_PatoWorkspace::testCaseAdd()
{

}

void TEST_PatoWorkspace::testCaseSetRevisionCommiting()
{

}

void TEST_PatoWorkspace::testCaseChanges()
{

}

void TEST_PatoWorkspace::testCaseStatus()
{

}

QTEST_MAIN(TEST_PatoWorkspace);

#include "tst_test_patoworkspace.moc"
