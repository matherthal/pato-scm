#include <QtCore/QString>
#include <QtTest/QtTest>
#include <patofs.h>

class PatoFSTest : public QObject
{
    Q_OBJECT

public:
    PatoFSTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCaseSaveData();
    void testCaseSaveData2();
    void testCaseLoadData();
    void testCaseLoadData2();
};

PatoFSTest::PatoFSTest()
{
}

void PatoFSTest::initTestCase()
{
}

void PatoFSTest::cleanupTestCase()
{
}

void PatoFSTest::testCaseSaveData()
{
    std::string data = "abc";

    qDebug(data.c_str());
    PatoFS::getInstance()->saveData(data);

    QVERIFY2(true, "Failure");
}

void PatoFSTest::testCaseSaveData2()
{
    std::string data = "abc";

    std::vector<std::string> vecData;
    vecData.push_back("abc");

    std::vector<int> vecIdFile;
    PatoFS::getInstance()->saveData(vecData, vecIdFile);

    QVERIFY2(!vecIdFile.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData()
{
    std::vector<int> vecIdFile;
    vecIdFile.push_back(1);
    std::vector<std::string> vecData;

    PatoFS::getInstance()->loadData(vecIdFile, vecData);

    QVERIFY2(!vecData.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData2()
{
    int idFile = 1;
    std::string data;
    PatoFS::getInstance()->loadData(idFile, data);

    QVERIFY2(!data.empty(), "Failure");
}

QTEST_APPLESS_MAIN(PatoFSTest);

#include "tst_patofstest.moc"
