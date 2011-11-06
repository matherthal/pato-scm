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
  //  void testCaseShowLog();
};

PatoDataModelTest::PatoDataModelTest()
{
}

void PatoDataModelTest::testCaseCheckin()
{
    std::string login = "Rafael";
    std::string pass= "123";
    std::string project = "pato";

    std::map<std::string, int> filePath;
    /*filePath.insert(std::make_pair<std::string,int>("pato\\A.CPP",1));
    filePath.insert(std::make_pair<std::string,int>("pato\\B.CPP",2));
    filePath.insert(std::make_pair<std::string,int>("pato\\C.CPP",3));
    filePath.insert(std::make_pair<std::string,int>("pato\\D.CPP",4));
    filePath.insert(std::make_pair<std::string,int>("pato\\BD\\D.CPP",5));
    filePath.insert(std::make_pair<std::string,int>("pato\\BD\\E.CPP",6));
    filePath.insert(std::make_pair<std::string,int>("pato\\BD\\F.CPP",7));
    filePath.insert(std::make_pair<std::string,int>("pato\\BD\\TESTE\\IVISON\\F.CPP",8));
    filePath.insert(std::make_pair<std::string,int>("pato\\BD\\TESTE\\IVISON\\RAFAEL",0));*/
    filePath.insert(std::make_pair<std::string,int>("pato\\AMARO\\VIRGINIA\\MARIANA\\RAFAEL\\JULIA.DOC",0));

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

    std::map<std::string, int> filePath2;
    PatoDataModel::getInstance()->checkOut(login, pass, project, -1, filePath2);

    bool bValid = false;

    if ( !filePath2.empty() )
    {
        bValid = true;
        std::map<std::string, int>::iterator itMap;
        for(itMap = filePath2.begin(); itMap != filePath2.end(); itMap++)
        {
            qDebug()<< itMap->first.c_str() << " | " << itMap->second;
        }
    }

    QVERIFY2(bValid, "Failure");
}
/*
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

*/
QTEST_APPLESS_MAIN(PatoDataModelTest);

#include "tst_patodatamodeltest.moc"
