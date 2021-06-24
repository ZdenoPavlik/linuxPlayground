/*
    Playground project for C++
*/
#include <iostream>
#include "thread_guard.hpp"

#include "exercise1.cpp"
#include "exercise2_ship.cpp"
#include "exercise3_parallel_accumulate.cpp"
#include "exercise4_condition_variable.cpp"
#include "exercise5_parallel_accumulate_async.cpp"

int main()
{
    std::cout << "Hello World!" << std::endl;

    /*exercise1();
    std::thread t1([]() { std::cout << std::endl << "print from " << std::this_thread::get_id() << std::endl; });
    thread_guard tg(t1);*/

    // exercise2_ship();
    // exercise3_parallel_accumulate();

    // example4::exercise4_condition_variable();

    exercise5::exercise5_parallel_accumulate_async();

    return 0;
}
