#include <QtCore/QString>
#include <QtTest/QtTest>
#include <patofs.h>

class PatoFSTest : public QObject
{
    Q_OBJECT

public:
    PatoFSTest();

private Q_SLOTS:
    //void initTestCase();
    //void cleanupTestCase();
    void testCaseInitBD();
    void testCaseSaveData();
    void testCaseSaveDatas();
    void testCaseLoadData();
    void testCaseLoadDatas();
    void testCaseCloseBD();
};

PatoFSTest::PatoFSTest()
{
}
/*
void PatoFSTest::initTestCase()
{
}*/
/*
void PatoFSTest::cleanupTestCase()
{
}*/

void PatoFSTest::testCaseInitBD()
{
    bool bInitBD = PatoFS::getInstance()->initBD();
    QVERIFY2(bInitBD, "Failure");
}

void PatoFSTest::testCaseSaveData()
{
    std::string data ="abc";
    QString str(data.c_str());

    bool bValid = true;
    int nResult = PatoFS::getInstance()->saveData(data);
    if ( nResult == -1 )
        bValid = false;

    qDebug() << nResult << " " << str;

    QVERIFY2(bValid, "Failure");
}

void PatoFSTest::testCaseSaveDatas()
{
    std::vector<std::string> vecData;
    vecData.push_back("def");
    vecData.push_back("ghi");

    std::vector<int> vecIdFile;

    bool bValid = true;
    PatoFS::getInstance()->saveData(vecData, vecIdFile);
    if ( vecData.empty() )
        bValid = false;

    for(unsigned int i = 0 ; i < vecIdFile.size(); i++)
    {
        qDebug() << vecIdFile[i];
    }


    QVERIFY2(bValid, "Failure");
}

void PatoFSTest::testCaseLoadData()
{
    std::string data;
    PatoFS::getInstance()->loadData(1,data);

    bool bValid = true;
    if ( data.empty() )
        bValid = false;

    qDebug() << "Inicio do Carregamento";
    qDebug() << data.c_str();
    qDebug() << "Fim do Carregamento";

    QVERIFY2(bValid, "Failure");
}

void PatoFSTest::testCaseLoadDatas()
{
    std::vector<std::string> data;
    std::vector<int> vecIDFile;
    vecIDFile.push_back(1);
    vecIDFile.push_back(2);
    vecIDFile.push_back(3);
    PatoFS::getInstance()->loadData(vecIDFile,data);

    bool bValid = true;
    if ( data.empty() )
        bValid = false;

    qDebug() << "Inicio do Carregamento";

    for(unsigned int i = 0; i < data.size(); i++ )
    {
        qDebug() << data[i].c_str();
    }

    qDebug() << "Fim do Carregamento";

    QVERIFY2(bValid, "Failure");

}

void PatoFSTest::testCaseCloseBD()
{
    QVERIFY2(PatoFS::destroyInstance(), "Failure");
}

QTEST_APPLESS_MAIN(PatoFSTest);

#include "tst_patofstest.moc"
