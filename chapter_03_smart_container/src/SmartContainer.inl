#include "SmartContainer.hpp"

template <typename T>
SmartContainer<T>::SmartContainer(T inputValue)
{
    std::cout << "[SmartContainer] [constructor] called " << std::endl;

    _storage = new T;
    _referenceCounter++;

    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer& other) // copy constructor
{
    std::cout << "[SmartContainer] [copy constructor] called " << std::endl;
    _storage = other._storage;
    _referenceCounter = other._referenceCounter;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
unsigned int SmartContainer<T>::use_count()
{
    return _referenceCounter;
}

template <typename T>
T* SmartContainer<T>::get()
{
    return _storage;
}

// Overload * operator
template <typename T>
T& SmartContainer<T>::operator*()
{
    return *_storage;
}

// Overload -> operator
template <typename T>
T* SmartContainer<T>::operator->()
{
    return _storage;
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer&& other) noexcept // move constructor
{
    std::cout << "[SmartContainer] [move constructor] called " << std::endl;
}

template <typename T>
SmartContainer<T>::~SmartContainer()
{
    std::cout << "[SmartContainer] [move assignment] called " << std::endl;

    _referenceCounter--;
    std::cout << "[SmartContainer] _referenceCounter decreased to " << _referenceCounter << std::endl;
    if(_referenceCounter == 0)
    {
        std::cout << "[SmartContainer] removing _storage" << std::endl;
        delete _storage;
    }
}
