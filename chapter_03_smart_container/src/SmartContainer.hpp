#pragma once
#include <iostream>

template <typename T>
class SmartContainer
{
public:
    explicit SmartContainer(T inputValue);
    SmartContainer(const SmartContainer& other);                      // copy constructor
    SmartContainer(const SmartContainer&& other) noexcept;            // move constructor
    SmartContainer& operator=(const SmartContainer& other);           // copy assignment
    SmartContainer& operator=(const SmartContainer&& other) noexcept; // move assignment

    unsigned int use_count();
    T* get();
    T& operator*();
    T* operator->();

    virtual ~SmartContainer();

private:
    unsigned int _referenceCounter = 0;
    T* _storage;
};

//https://www.geeksforgeeks.org/how-to-implement-user-defined-shared-pointers-in-c/

/*
https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

When combinining templated class with constructor in cpp(!) it will end with undefined reference by compiler.
Therefore is used inl file to create "single inlined file"
*/

#include "SmartContainer.inl"
