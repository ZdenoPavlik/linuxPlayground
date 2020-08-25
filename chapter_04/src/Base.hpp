#pragma once
#include <iostream>

template <typename T>
class Base
{
public:
    void doSomething()
    {
        T& derived = static_cast<T&>(*this);
        std::cout << "Log from base class" << std::endl;
        derived.doSomethingFromDerived();
    }
};

#include "Base.inl"
