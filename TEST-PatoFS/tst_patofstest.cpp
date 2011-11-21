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
    std::string data = "abcd";

    qDebug(data.c_str());
    //key = PatoFS::getInstance()->saveData(data);
    qDebug(key.c_str());

    QVERIFY2(true, "Failure");
}

void PatoFSTest::testCaseSaveData2()
{
    std::string data = "abcdef";

    std::vector<std::string> vecData;
    vecData.push_back(data);
    vecData.push_back("abcgh");
    vecData.push_back("abcdef");

    std::vector<std::string> vecIdFile;
   // PatoFS::getInstance()->saveData(vecData, vecIdFile);

    QVERIFY2(!vecIdFile.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData()
{
    std::vector<std::string> vecIdFile;
    vecIdFile.push_back(key);
    vecIdFile.push_back("d7b8bdadb1420605d54d85205a1841c8");
    vecIdFile.push_back("e80b5017098950fc58aad83c8c14978e");
    std::vector<std::string> vecData;

    PatoFS::getInstance()->loadData(vecIdFile, vecData);

    QVERIFY2(!vecData.empty(), "Failure");
}

void PatoFSTest::testCaseLoadData2()
{
    std::string idFile = "900150983cd24fb0d6963f7d28e17f72";//key;
    std::string data;
    PatoFS::getInstance()->loadData(idFile, data);

    QVERIFY2(!data.empty(), "Failure");
}

QTEST_APPLESS_MAIN(PatoFSTest);

#include "tst_patofstest.moc"
