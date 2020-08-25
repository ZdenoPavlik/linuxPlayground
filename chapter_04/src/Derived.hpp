#pragma once
#include "Base.hpp"
#include <iostream>

class Derived : public Base<Derived>
{
public:
    void doSomethingFromDerived()
    {
        std::cout << "Log from derived class" << std::endl;
    }
};

#include "Derived.inl"