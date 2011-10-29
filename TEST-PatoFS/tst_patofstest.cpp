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

    PatoFS::getInstance()->saveData(data);

    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(PatoFSTest);

#include "tst_patofstest.moc"
