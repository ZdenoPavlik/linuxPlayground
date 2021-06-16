#include <future>
#include <iostream>
#include <thread>
//#include <utility>

#include "example1.cpp"
#include "example2.cpp"

int main()
{
    std::cout << "Hello World!" << std::endl;

    example1();
    std::cout << std::endl << std::endl;

    example2_shared_future();
    std::cout << std::endl << std::endl;

    return 0;
}
