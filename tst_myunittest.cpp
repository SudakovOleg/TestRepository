#include <QString>
#include <QtTest>
#include "myclass.h"

class MyUnitTest : public QObject
{
    Q_OBJECT

private:
    MyClass* _cls;

public:
    MyUnitTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void TestDependsVal();
    void TablTestMax_data();
    void TablTestMax();
};

MyUnitTest::MyUnitTest()
{
}

void MyUnitTest::initTestCase()
{
    _cls = new MyClass;
   // _cls=nullptr;
    QVERIFY2(_cls, "Can’t allocate memory"); // Не возможно выделить память под объект
}

void MyUnitTest::cleanupTestCase()
{
   // _cls=nullptr;
    QVERIFY2(_cls, "Can’t release memory"); // Не возможно удалить объект
}


void MyUnitTest::TestDependsVal()
{
   int temp_max= _cls->max(25, 0);
    QCOMPARE(temp_max, 25);
    QCOMPARE(_cls->max(temp_max,50),50);

}

void MyUnitTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void MyUnitTest::TablTestMax_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("second");
    QTest::addColumn<int>("expected");

    QTest::newRow("Test data 1") << 0 << 0 << 0;
    QTest::newRow("Test data 2") << 5 << 10 << 10;
    QTest::newRow("Test data 3") << 10 << 5 << 10;
    QTest::newRow("Test data 4") << -5 << -10 << -5;
    QTest::newRow("Test data 5") << -10 << -5 << -5;
    QTest::newRow("Test data 6") << 5 << -10 << 5;
    QTest::newRow("Test data 7") << -5 << 10 << 10;
}

void MyUnitTest::TablTestMax()
{
    MyClass mc;
    QFETCH(int, first);
    QFETCH(int, second);
    QFETCH(int, expected);
    int actual = mc.max(first, second);
    QCOMPARE(actual, expected);

}

QTEST_APPLESS_MAIN(MyUnitTest)

#include "tst_myunittest.moc"
