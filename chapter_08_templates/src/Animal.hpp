#pragma once

#include <iostream>
#include <type_traits>

template <class T = int> // <-128,127>
class Animal
{
public:
    Animal(std::string name, T legCount)
        : m_name(name)
        , m_legCount(legCount)
    {
        std::cout << "Name: [" << m_name << "], legCount: [" << m_legCount << "]" << std::endl;
        std::cout << "Name: [" << m_name << "], m_legCount is_signed [" << std::is_signed<T>::value << "], is_integer [" << std::is_integral<T>::value << "], is_floating_point [" << std::is_floating_point<T>::value << "], is_pointer [" << std::is_pointer<T>::value << "], is_fundamental [" << std::is_fundamental<T>::value << "]" << std::endl;
    }

private:
    std::string m_name;
    T m_legCount = 0;
};

void playingWithAnimals()
{
    Animal<> anim1("Dog", 2);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    Animal<short> anim2("Caterpillar", SHRT_MAX);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    Animal<short> anim3("Caterpillar Extended", SHRT_MAX + 100); //!!! will intentionally overflow
    std::cout << "-----------------------------------------------------------------" << std::endl;
}