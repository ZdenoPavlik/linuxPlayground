#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <ctime>

void doSomeCalculation(std::shared_future<int> future, int numberOfRetries, std::string name)
{
    using namespace std::chrono_literals;
    std::cout << name << " - Entry" << std::endl;

    // 1sec loop
    for(int i = 0; i < numberOfRetries; i++)
    {
        auto status = future.wait_for(1s);

        switch(status)
        {
            case std::future_status::ready:
            {
                std::cout << name << " - Success, exit with value " << future.get() << std::endl;
                return;
                break;
            }
            case std::future_status::deferred:
            {
                std::cout << name << " - Failure, deferred" << std::endl;
                break;
            }
            case std::future_status::timeout:
            {
                std::cout << name << " - Failure, timeout" << std::endl;
                break;
            }
        }
    }

    std::cout << name << " - Value not retrieved in given time, aborting waiting loop" << std::endl;
}

void example2_shared_future()
{
    std::cout << "--------------------------------------\n\n"
              << "Example 2, shared future" << std::endl;

    std::promise<int> uberPromise;
    std::shared_future<int> sharedFtr1 = uberPromise.get_future();
    std::shared_future<int> sharedFtr2 = sharedFtr1; // waste of stack size, but intended to visualize possibility of copying
    std::shared_future<int> sharedFtr3 = sharedFtr1;
    std::shared_future<int> sharedFtr4 = sharedFtr1;
    std::shared_future<int> sharedFtr5 = sharedFtr1;

    std::thread t1(doSomeCalculation, sharedFtr1, 1, "t1");
    std::thread t2(doSomeCalculation, sharedFtr1, 2, "t2");
    std::thread t3(doSomeCalculation, sharedFtr1, 3, "t3");
    std::thread t4(doSomeCalculation, sharedFtr1, 4, "t4");
    std::thread t5(doSomeCalculation, sharedFtr1, 5, "t5");

    std::this_thread::sleep_for(std::chrono::seconds(3));
    uberPromise.set_value(42);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}