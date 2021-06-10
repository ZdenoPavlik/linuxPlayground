#pragma once

#include <iostream>
#include <string>
#include <memory>

class Base
{
public:
    virtual void printName()
    {
        std::cout << "print Base " << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual void printName() override
    {
        std::cout << "print Derived " << std::endl;
    }
};

class AnotherDerived : public Base
{
public:
    virtual void printName() override
    {
        std::cout << "print AnotherDerived " << std::endl;
    }
};

class ThirdDerived : public Base
{
public:
    virtual void printName() override
    {
        std::cout << "print ThirdDerived " << std::endl;
    }
};

void variant1()
{
    std::cout << "------------------------------"
              << "Trivial inheritance" << std::endl;

    std::unique_ptr<Base> varBase = std::make_unique<Base>();
    varBase->printName();

    std::unique_ptr<Base> varDerived = std::make_unique<Derived>();
    varDerived->printName();

    std::unique_ptr<Base> varAnother = std::make_unique<AnotherDerived>();
    varAnother->printName();

    std::unique_ptr<Base> varThird = std::make_unique<ThirdDerived>();
    varThird->printName();
}
