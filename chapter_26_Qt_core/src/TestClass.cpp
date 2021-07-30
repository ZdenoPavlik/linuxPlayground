
#include "TestClass.h"

TestClass::TestClass(QObject* parent)
    : QObject(parent)
{

    qDebug() << this << "Constructed";
}

TestClass::~TestClass()
{
    qWarning() << this << "Destructed";
}

void TestClass::emitMakeNoise(QString noise)
{
    emit makeNoise(noise);
}

void TestClass::hearNoise(QString noise)
{
    qDebug() << this << "I am hearing " << noise;
}