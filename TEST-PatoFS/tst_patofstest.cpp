#include <QtCore/QString>
#include <QtTest/QtTest>
#include <patofs.h>

class PatoFSTest : public QObject
{
    Q_OBJECT

public:
    PatoFSTest();
    std::string key;

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
    key = PatoFS::getInstance()->saveData(data);
    qDebug(key.c_str());

    QVERIFY2(true, "Failure");
}

void PatoFSTest::testCaseSaveData2()
{
    std::string data = "abc";

    std::vector<std::string> vecData;
    vecData.push_back("abc");

    std::vector<std::string> vecIdFile;
    PatoFS::getInstance()->saveData(vecData, vecIdFile);

    QVERIFY2(!vecIdFile.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData()
{
    std::vector<std::string> vecIdFile;
    vecIdFile.push_back(key);
    std::vector<std::string> vecData;

    PatoFS::getInstance()->loadData(vecIdFile, vecData);

    QVERIFY2(!vecData.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData2()
{
    std::string idFile = key;
    std::string data;
    PatoFS::getInstance()->loadData(idFile, data);

    QVERIFY2(!data.empty(), "Failure");
}

QTEST_APPLESS_MAIN(PatoFSTest);

#include "tst_patofstest.moc"
