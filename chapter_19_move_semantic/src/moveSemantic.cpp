#pragma once
#include <iostream>

class MovingClass
{
public:
    MovingClass(std::string name) // parametric constructor
    {
        m_name = name;
        std::cout << "[" << m_name << "] Calling constructor" << std::endl;
    };

    MovingClass(const MovingClass& other) // copy constructor
    {
        m_name = other.m_name;
        std::cout << "[" << m_name << "] Calling COPY constructor" << std::endl;
    }

    MovingClass(MovingClass&& other) noexcept // move constructor
    {
        m_name = other.m_name;
        other.m_name.clear();
        std::cout << "[" << m_name << "] Calling MOVE constructor" << std::endl;
    }

    MovingClass& operator=(const MovingClass& other) = delete; // copy assignment
    /*{
        std::cout << "[" << m_name << "] Calling COPY assignment" << std::endl;
        return *this = MovingClass(other);
    }*/

    MovingClass& operator=(MovingClass&& other) noexcept // move assignment
    {
        std::swap(m_name, other.m_name);
        std::cout << "[" << m_name << "] Calling MOVE assignment" << std::endl;
        return *this;
    }

    ~MovingClass() // destructor
    {
        std::cout << "[" << m_name << "] Calling destructor" << std::endl;
    }

private:
    std::string m_name;
};

void moveSemantic()
{
    std::cout << "---------------------- moveSemantic ----------------------" << std::endl;
    {
        MovingClass class1("test");
        MovingClass class2 = std::move(class1);
        MovingClass class3 = class2;
    }
}