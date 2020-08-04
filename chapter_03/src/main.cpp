/*
    Playground project for C++
*/
#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>
#include "SmartContainer.hpp"

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Smart template container" << std::endl;

    return 0;
}
