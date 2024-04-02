#include <QtTest>
#include <QtSerialPort>
#include <QtSerialBus>
#include <QDebug>
#include "/home/jakob/test-bench-library/testbenchlibrary.h"

// add necessary includes here

class AcceptanceTest : public QObject
{
    Q_OBJECT

public:
    AcceptanceTest();
    ~AcceptanceTest();

private slots:
    void initTestCase();
    void test_case1();

private:
    TestBenchLibrary t_testBenchLibrary;
};

AcceptanceTest::AcceptanceTest()
{


}

AcceptanceTest::~AcceptanceTest() {}

void AcceptanceTest::initTestCase()
{

    QSerialPort port1("/dev/ttyACM1");
    port1.setBaudRate(QSerialPort::Baud115200);
    port1.setDataBits(QSerialPort::Data8);
    port1.setStopBits(QSerialPort::OneStop);
    port1.setParity(QSerialPort::NoParity);
    port1.setFlowControl(QSerialPort::NoFlowControl);
    if(!port1.open(QIODevice::ReadWrite))
        qDebug() << port1.errorString();

    QSerialPort port2("/dev/ttyACM2");
    port2.setBaudRate(QSerialPort::Baud115200);
    port2.setDataBits(QSerialPort::Data8);
    port2.setStopBits(QSerialPort::OneStop);
    port2.setParity(QSerialPort::NoParity);
    port2.setFlowControl(QSerialPort::NoFlowControl);
    if(!port2.open(QIODevice::ReadWrite))
        qDebug() << port2.errorString();

    QString canPORT="slcan0";

    t_testBenchLibrary = TestBenchLibrary(&port1, &port2, canPORT);
}

void AcceptanceTest::test_case1() {



    t_testBenchLibrary.moveCorrectCard();

    //check if CAN message unlocked
    //ID: 0x18FF80FD
    //if Byte 1 = 0x01 unlocked

}

QTEST_APPLESS_MAIN(AcceptanceTest)

#include "tst_acceptancetest.moc"
