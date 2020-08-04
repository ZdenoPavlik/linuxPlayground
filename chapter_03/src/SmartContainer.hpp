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
    SmartContainer& operator=(const SmartContainer&& other) noexcept; // move assignemnt

    virtual ~SmartContainer();

    size_t size();
    T at();
    void add(T newElement);
    T remove(size_t index);

private:
    T* _storage;
    size_t size{0};
};