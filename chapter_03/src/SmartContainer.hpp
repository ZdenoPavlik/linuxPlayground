#pragma once
#include <iostream>

template <typename T>
class SmartContainer
{
public:
    SmartContainer();
    SmartContainer(const SmartContainer& other);                      // copy constructor
    SmartContainer(const SmartContainer&& other) noexcept;            // move constructor
    SmartContainer& operator=(const SmartContainer& other);           // copy assignment
    SmartContainer& operator=(const SmartContainer&& other) noexcept; // move assignment

    virtual ~SmartContainer();

    size_t size();
    T& at(size_t index);
    void add(T newElement);
    void remove(size_t index);

private:
    unsigned int _referenceCounter = 0;
    T* _storage;
    size_t _size{0};
};

/*
https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

When combinining templated class with constructor in cpp(!) it will end with undefined reference by compiler.
Therefore is used inl file to create "single inlined file"
*/

#include "SmartContainer.inl"
