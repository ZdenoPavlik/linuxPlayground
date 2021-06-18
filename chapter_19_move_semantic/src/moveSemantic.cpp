#pragma once
#include <iostream>

// Purpose:
/*
Check for "Purpose" label in this file.
Intention of this move semantic is not duplicate resources, instead copy only pointer to resource and delete it only once
*/

class MovingClass
{
public:
    MovingClass(std::string name) // parametric constructor
    {
        m_name = name;
        std::cout << "[" << m_name << "] Calling constructor" << std::endl;
        m_memory = malloc(1024 * 1024 * 1024 * 1024); // Purpose: Creating HUGE resource which is expensive to create.
        std::cout << "[" << m_name << "] Allocated memory at " << m_memory << std::endl;
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

        m_memory = other.m_memory; // Purpose: THIS IS MAIN GOAL! Copy only pointer to expensive resource instead of allocating new resource+copy
                                   // content+delete old resource
        other.m_memory = nullptr;  // Purpose: Set old pointer to nullptr in order to prevent "double free"
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
        if(m_memory != nullptr) // Purpose: Delete huge resource
        {
            std::cout << "[" << m_name << "] DEallocated memory at " << m_memory << std::endl;
            free(m_memory);
            m_memory = nullptr;
        }
    }

private:
    std::string m_name;
    void* m_memory{nullptr};
};

MovingClass constructClass()
{
    MovingClass clazz("insider");
    return std::move(clazz);
}

void moveSemantic()
{
    std::cout << "---------------------- moveSemantic ----------------------" << std::endl;
    { // Hint: this curly brackets will limit scope of function to only intended size
        MovingClass class4 = constructClass();
    }
    {
        MovingClass class1("test");
        MovingClass class2 = std::move(class1);
        MovingClass class3 = class2;
    }
}