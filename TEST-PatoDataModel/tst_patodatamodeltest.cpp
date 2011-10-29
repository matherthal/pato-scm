#include <QtCore/QString>
#include <QtTest/QtTest>
#include <patodatamodel.h>

class PatoDataModelTest : public QObject
{
    Q_OBJECT

public:
    PatoDataModelTest();

private Q_SLOTS:
    void testCaseCheckin();
    void testCaseCheckout();
    void testCaseShowLog();
};

PatoDataModelTest::PatoDataModelTest()
{
}

void PatoDataModelTest::testCaseCheckin()
{
    std::string login = "Rafael";
    std::string pass= "123";
    std::string project = "pato";

    std::vector<std::string> filePath;
    filePath.push_back("pato\\A.CPP");
    filePath.push_back("pato\\B.CPP");
    filePath.push_back("pato\\C.CPP");

    std::string message = "Primeiro Commit";
    bool bValid = PatoDataModel::getInstance()->checkIn(filePath, project, login, message);
    //bool bValid = false;
    QVERIFY2(bValid, "Failure");
}

void PatoDataModelTest::testCaseCheckout()
{
    std::string login = "Rafael";
    std::string pass= "123";
    std::string project = "pato";

    std::vector<std::string> filePath2;
    PatoDataModel::getInstance()->checkOut(login, pass, project, -1, filePath2);

    bool bValid = false;

    if ( !filePath2.empty() )
    {
        bValid = true;
        for(unsigned int i = 0; i < filePath2.size(); i++)
        {
            qDebug()<< filePath2[i].c_str();
        }
    }

    QVERIFY2(bValid, "Failure");
}

void PatoDataModelTest::testCaseShowLog()
{
    std::string login = "Rafael";
    std::string pass= "123";
    std::string project = "pato";

    std::vector<std::string> filePathLog;
    PatoDataModel::getInstance()->showLog(login, pass, project, -1, filePathLog);

    bool bValid = false;
    if ( !filePathLog.empty() )
    {
        bValid = true;
        for(int i = 0; i < filePathLog.size(); i++ )
        {
            qDebug(filePathLog[i].c_str());
        }
    }

    QVERIFY2(bValid, "Failure");
}


QTEST_APPLESS_MAIN(PatoDataModelTest);

#include "tst_patodatamodeltest.moc"
