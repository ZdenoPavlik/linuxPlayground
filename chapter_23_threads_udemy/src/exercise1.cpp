#pragma once
#include <iostream>
#include <thread>

class CallableClass
{
public:
    void operator()()
    {
        std::cout << "Hello from CallableClass. Thread Id " << std::this_thread::get_id() << std::endl;
    }
};

void exercise1()
{
    std::cout << std::endl << std::endl << "-------------------------- Exercise 1 --------------------------" << std::endl;

    std::thread t1([]() {
        std::cout << "Hello from T1. Thread Id " << std::this_thread::get_id() << std::endl;
        CallableClass clazz;
        std::thread t2(clazz);

        t2.join();
    });

    t1.join();

    // std::thread t4;
}