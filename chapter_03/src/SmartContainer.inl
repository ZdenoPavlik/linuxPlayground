#include "SmartContainer.hpp"

template <typename T>
SmartContainer<T>::SmartContainer()
{
    _storage = new T;

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

//Partial template specialization, only for fun. Remeber with std::array<T> what will be T*
template <>
SmartContainer<int>::SmartContainer()
{
    std::cout << "[SmartContainer] using partialy template specialization";

    _referenceCounter++;
    std::cout << "[SmartContainer] _referenceCounter increased to " << _referenceCounter << std::endl;
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer& other)
{
}

template <typename T>
SmartContainer<T>::SmartContainer(const SmartContainer&& other) noexcept
{
}

template <typename T>
SmartContainer<T>& SmartContainer<T>::operator=(const SmartContainer& other)
{
}

template <typename T>
SmartContainer<T>& SmartContainer<T>::operator=(const SmartContainer&& other) noexcept
{
}
//Test line

template <typename T>
SmartContainer<T>::~SmartContainer()
{
    _referenceCounter--;
    if(_referenceCounter == 0)
    {
        delete _referenceCounter;
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
