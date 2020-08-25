#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>
#include "Derived.hpp"

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Hello World!" << std::endl;

    Derived derivedClass;
    derivedClass.doSomething();

    return 0;
}
