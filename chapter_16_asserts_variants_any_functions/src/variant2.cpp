#pragma once

#include <iostream>
#include <string>
#include <memory>

// Polymorphism without Base class

class Var2Derived
{
public:
    void printName() const
    {
        std::cout << "print Var2Derived " << std::endl;
    }
};

class Var2AnotherDerived
{
public:
    void printName() const
    {
        std::cout << "print Var2AnotherDerived " << std::endl;
    }
};

class Var2ThirdDerived
{
public:
    void printName() const
    {
        std::cout << "print Var2ThirdDerived " << std::endl;
    }
};

struct CallPrintName
{
    void operator()(const Var2Derived& d)
    {
        d.printName();
    }
    void operator()(const Var2AnotherDerived& ad)
    {
        ad.printName();
    }
    void operator()(const Var2ThirdDerived& td)
    {
        td.printName();
    }
};

void variant2()
{
    std::cout << "------------------------------\n"
              << "Polymorphism (runtime) without base class" << std::endl;

    std::variant<Var2Derived, Var2AnotherDerived, Var2ThirdDerived> var;

    // https://www.bfilipek.com/2018/09/visit-variants.html
    /*std::visit is a powerful utility that allows you to call a function over a currently active type in std::variant. It does some magic to select
     * the proper overload, and what’s more, it can support many variants at once.*/

    std::visit(CallPrintName{}, var); // 1st approach, if API is not generic (i.e. "printName" has different names)
    var = Var2AnotherDerived();
    std::visit(CallPrintName{}, var);
    var = Var2ThirdDerived();
    std::visit(CallPrintName{}, var);

    std::cout << std::endl;
    auto caller = [](const auto& obj) { obj.printName(); }; // 2nd approach, if API is generic
    std::visit(caller, var);
    var = Var2AnotherDerived();
    std::visit(caller, var);
    var = Var2ThirdDerived();
    std::visit(caller, var);
}