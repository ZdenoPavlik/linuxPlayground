/*
    Playground project for C++
*/
#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>
#include <memory>
#include <string>
#include "SmartContainer.hpp"

void localPlayground()
{
    SmartContainer<std::array<std::string, 4>> arrayContainer({"a", "b", "c", "d"});

    SmartContainer<std::string> stringContainer(static_cast<std::string>("test string"));

    SmartContainer<int> intContainer((int)42);

    SmartContainer<char> charContainer('a');
}

int main(int argc, char** argv)
{
    //Note -> urobit template dynamic array

    localPlayground();

    return 0;
}
