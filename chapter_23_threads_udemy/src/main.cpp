/*
    Playground project for C++
*/
#include <iostream>
#include "thread_guard.hpp"

#include "exercise1.cpp"
#include "exercise2_ship.cpp"
#include "exercuse3_parallel_acumulate.cpp"

int main()
{
    std::cout << "Hello World!" << std::endl;

    /*exercise1();
    std::thread t1([]() { std::cout << std::endl << "print from " << std::this_thread::get_id() << std::endl; });
    thread_guard tg(t1);*/

    // exercise2_ship();
    example3();

    return 0;
}
