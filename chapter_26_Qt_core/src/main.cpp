#include <QCoreApplication>
#include <iostream>

#include "TestClass.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Hello World from QT" << std::endl;

    {
        TestClass clazz;
        clazz.setObjectName("Dummy name");
        qDebug() << &clazz;

        TestClass clazz2;
        clazz2.setObjectName("clazz 2");

        QObject::connect(&clazz, &TestClass::makeNoise, &clazz2, &TestClass::hearNoise);

        clazz.emitMakeNoise("brown noise");
    }

    return a.exec();
}
