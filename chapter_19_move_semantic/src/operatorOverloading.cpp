#pragma once
#include <iostream>
#include <string>

// https://www.geeksforgeeks.org/operator-overloading-c/
// https://en.cppreference.com/w/cpp/language/operators

class AnotherClass
{
public:
    AnotherClass(std::string name)
    {
        m_name = name;
        std::cout << "[" << m_name << "] Constructor" << std::endl;
    }

    AnotherClass(const AnotherClass& other) // copy constructor
    {
        m_name = other.m_name;
        std::cout << "[" << m_name << "] Calling COPY constructor" << std::endl;
    }

    AnotherClass(AnotherClass&& other) noexcept = delete; // move constructor

    AnotherClass& operator=(const AnotherClass& other) // copy assignment // class2 = class2 + class1;
    {
        std::cout << "[" << m_name << "] Calling COPY assignment" << std::endl;
        return *this = AnotherClass(other);
    }

    AnotherClass& operator=(AnotherClass&& other) noexcept // move assignment
    {
        std::swap(m_name, other.m_name);
        std::cout << "[" << m_name << "] Calling MOVE assignment" << std::endl;
        return *this;
    }
    // end of rule of five

    void operator()()
    {
        std::cout << "I am functor of name " << m_name << std::endl;
    }

    // https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
    friend std::ostream& operator<<(std::ostream& os, const AnotherClass& in);

    AnotherClass& operator+(const AnotherClass& other)
    {
        std::cout << "+" << std::endl;
        m_name = m_name + ' ' + other.m_name;
        return *this;
    }

    // https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
    // https://en.cppreference.com/w/cpp/memory/new/operator_delete
    static void* operator new(size_t size)
    {
        AnotherClass* newClass = (AnotherClass*)::operator new(size);
        std::cout << "Created class " << newClass->m_name << std::endl;
        return newClass;
    }

    static void operator delete(void* ptr) noexcept
    {
        std::cout << "Freed class " << ((AnotherClass*)ptr)->m_name << std::endl;
        free(ptr);
    }

private:
    std::string m_name;
};

std::ostream& operator<<(std::ostream& os, const AnotherClass& in) // copy&pasterfrom internet. Ostream is required due to std::cout
{
    os << "[" << in.m_name << "] Hello!";
    return os;
}

void operatorOverloading()
{
    std::cout << "---------------------- operatorOverloading ----------------------" << std::endl;

    AnotherClass class1("clazz1");
    std::cout << "Logging class " << class1 << std::endl;

    AnotherClass class2("clazz2");
    class2.operator+(class1); // equivalent to following line
    class2 = class2 + class1; // equivalent to previous line
    class2 = class1;

    class2();

    AnotherClass* class3 = new AnotherClass("clazz4");
    delete class3;

    std::cout << std::endl;
}