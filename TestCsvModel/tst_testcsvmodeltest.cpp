#include <QString>
#include <QtTest>
#include "../MineSenseDemo/models/csvmodel.h"

class TestCsvModelTest : public QObject
{
    Q_OBJECT

public:
    TestCsvModelTest();

private Q_SLOTS:
    void initTestCase();
    void setAdress();
    void setXTitle();
    void setYTitle();
    void setData();
    void setX();
    void setY();
    void insertData();
    void addData();
    void removeData();
    void clearData();
};


TestCsvModelTest::TestCsvModelTest()
{

}

void TestCsvModelTest::initTestCase()
{
    CsvModel model1("qwerty", "xyz", "abc");
    QCOMPARE(model1.getAddress(), string("qwerty"));
    QCOMPARE(model1.getXTitle(), string("xyz"));
    QCOMPARE(model1.getYTitle(), string("abc"));
}

void TestCsvModelTest::setAdress()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setAdress("poiuy");
    QCOMPARE(model1.getAddress(), string("poiuy"));
    model1.setAdress("");
    QCOMPARE(model1.getAddress(), string(""));
}

void TestCsvModelTest::setXTitle()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setXTitle("poiuy");
    QCOMPARE(model1.getXTitle(), string("poiuy"));
    model1.setXTitle("");
    QCOMPARE(model1.getXTitle(), string(""));
}

void TestCsvModelTest::setYTitle()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setYTitle("poiuy");
    QCOMPARE(model1.getYTitle(), string("poiuy"));
    model1.setYTitle("");
    QCOMPARE(model1.getYTitle(), string(""));

}

void TestCsvModelTest::setData()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setData(0, 1, 2);
    model1.setData(-1, 1, 2);
    model1.addData(10, 2);
    model1.setData(0, 1, 2);
    QCOMPARE(model1.getData(0).first, 1.0);
    QCOMPARE(model1.getData(0).second, 2.0);
}

void TestCsvModelTest::setX()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setX(0, 1);
    model1.setX(-1, 1);
    model1.addData(10, 2);
    model1.setX(0, 1);
    QCOMPARE(model1.getData(0).first, 1.0);
}

void TestCsvModelTest::setY()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.setY(0, 1);
    model1.setY(-1, 1);
    model1.addData(10, 2);
    model1.setY(0, 1);
    QCOMPARE(model1.getData(0).second, 1.0);

}

void TestCsvModelTest::insertData()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.insertData(10, 1, 2);
    model1.addData(10, 10);
    model1.addData(10, 11);
    model1.insertData(1, 1, 2);
    QCOMPARE(model1.getData(1).second, 2.0);

}

void TestCsvModelTest::addData()
{
    CsvModel model1("qwerty", "xyz", "abc");\
    model1.addData(10, 10);
    QCOMPARE(model1.getData(0).second, 10.0);
    model1.addData(10, 11);
    QCOMPARE(model1.getData(1).second, 11.0);

}

void TestCsvModelTest::removeData()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.removeData(1);
    model1.addData(10, 10);
    model1.addData(10, 11);
    model1.removeData(0);
    model1.addData(10, 12);
    QCOMPARE(model1.getData(1).second, 12.0);

}

void TestCsvModelTest::clearData()
{
    CsvModel model1("qwerty", "xyz", "abc");
    model1.clearData();
    model1.addData(10, 10);
    model1.addData(10, 11);
    model1.clearData();
    size_t zero = 0;
    QCOMPARE(model1.getAllData().size(), zero);

}


QTEST_APPLESS_MAIN(TestCsvModelTest)

#include "tst_testcsvmodeltest.moc"
