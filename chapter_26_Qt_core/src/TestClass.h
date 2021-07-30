
#pragma once

#include <QObject>
#include <QDebug>

class TestClass : public QObject
{
    Q_OBJECT

public:
    explicit TestClass(QObject* parent = nullptr);

    ~TestClass();
    void emitMakeNoise(QString noise);

signals:
    void makeNoise(QString noise);

public slots:
    void hearNoise(QString noise);
};