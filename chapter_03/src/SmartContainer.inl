#include "SmartContainer.hpp"

template <typename T>
SmartContainer<T>::SmartContainer()
{
    std::cout << "[SmartContainer] [constructor] called " << std::endl;
    _storage = new T;

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

//Partial template specialization, only for fun. Remember with std::array<T> what will be T*
template <>
SmartContainer<int>::SmartContainer()
{
    std::cout << "[SmartContainer] [partially templated constructor] called " << std::endl;
    std::cout << "[SmartContainer] using partially template specialization";

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer& other) // copy constructor
{
    std::cout << "[SmartContainer] [copy constructor] called " << std::endl;

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer&& other) noexcept // move constructor
{
    std::cout << "[SmartContainer] [move constructor] called " << std::endl;
}

template <typename T>
SmartContainer<T>& SmartContainer<T>::operator=(const SmartContainer& other) // copy assignment
{
    std::cout << "[SmartContainer] [copy assignment] called " << std::endl;

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
SmartContainer<T>& SmartContainer<T>::operator=(const SmartContainer&& other) noexcept // move assignment
{
    std::cout << "[SmartContainer] [move assignment] called " << std::endl;
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

template <typename T>
size_t SmartContainer<T>::size()
{
}

template <typename T>
T& SmartContainer<T>::at(size_t index)
{
    if(index > this->size())
    {
        throw std::runtime_error("Index greater that size of container");
    }
}

template <typename T>
void SmartContainer<T>::add(T newElement)
{
}

template <typename T>
void SmartContainer<T>::remove(size_t index)
{
}
