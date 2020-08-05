/*
    Playground project for C++
*/
#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>
#include <memory>
#include <string>
#include "SmartContainer.hpp"

int main(int argc, char** argv)
{
    //Note -> urobit template dynamic array

    //TODO
    SmartContainer<std::array<std::string, 4>> arrayContainer;

    SmartContainer<std::string> stringContainer;
    stringContainer.add("First");
    stringContainer.add("Second");
    stringContainer.add("Third");

    SmartContainer<int> intContainer;
    intContainer.add(1);
    intContainer.add(2);
    intContainer.add(3);

    SmartContainer<char> charContainer;
    charContainer.add('a');
    charContainer.add('b');
    charContainer.add('c');

    SmartContainer<void*> pointerContainer;
    pointerContainer.add(malloc(10));
    pointerContainer.add(malloc(10));
    pointerContainer.add(malloc(10));

    SmartContainer<std::shared_ptr<std::string>> sharedPtrContainer;
    sharedPtrContainer.add(std::make_shared<std::string>("shared pointer to first"));
    sharedPtrContainer.add(std::make_shared<std::string>("shared pointer to second"));
    sharedPtrContainer.add(std::make_shared<std::string>("shared pointer to third"));

    std::cout
        << "Smart template container" << std::endl;

    return 0;
}
