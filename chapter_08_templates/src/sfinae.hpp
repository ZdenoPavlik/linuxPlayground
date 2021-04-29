#pragma once

#include <iostream>
#include <cassert>
#include <exception>

//https://www.bfilipek.com/2016/02/notes-on-c-sfinae.html
//https://en.cppreference.com/w/cpp/language/sfinae
//https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error

struct Bar
{
    typedef int m_memberVariable;
};

template <typename T>
typename T::m_memberVariable foo(const T& t)
{
    std::cout << "foo<T>" << std::endl;
    return 0;
}

//template <typename T, typename std::enable_if<std::is_same<T, foundation::Bool>::value>::type* = nullptr> //only for foundation::Bool

template <typename T,
    std::enable_if_t<std::is_integral<T>::value, bool> = true>
void compileableOnlyWithIntegers(T input)
{
    std::cout << "[Integer] Input is " << input << std::endl;
}

template <typename T>
void throwsExceptionIfNotString(T input)
{
    if constexpr(std::is_same<T, std::string>::value)
    {
        std::cout << "[String] Input is " << input << std::endl;
    }
    else
    {
        std::cout << "Throwing exception" << std::endl;
        throw std::runtime_error("Input parameter is not string!");
    }
}

void sfinaePlayground()
{
    try
    {
        std::cout << "-----------------------------------------------------------------" << std::endl;
        foo(Bar());
        //foo(0); // error, missing m_memberVariable
        std::cout << "-----------------------------------------------------------------" << std::endl;
        //BOOST_ASSERT_MSG(1 > 2, "1 is not bigger than 2");
        //assert(1 > 2 && "1 is not bigger than 2");
        std::cout << "-----------------------------------------------------------------" << std::endl;
        compileableOnlyWithIntegers<int>(2);
        //compileableOnlyWithIntegers<std::string>("2");
        std::cout << "-----------------------------------------------------------------" << std::endl;
        throwsExceptionIfNotString<std::string>("Valid");
        throwsExceptionIfNotString<int>(5);
        std::cout << "-----------------------------------------------------------------" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Exception..." << std::endl;
    }
}