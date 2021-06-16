#include <future>
#include <iostream>
#include <thread>
#include <chrono>

void doSummary(std::promise<int> sumPromise, int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    sumPromise.set_value(a + b);
}

void doDivision(std::promise<int> divPromise, int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    divPromise.set_value(b / a);
}

void example1()
{
    int a = 10;
    int b = 20;

    std::promise<int> sumPromise;
    std::promise<int> divPromise;

    std::future<int> sumResult = sumPromise.get_future();
    std::future<int> divResult = divPromise.get_future();

    std::thread t1(doSummary, std::move(sumPromise), a, b);
    std::thread t2(doDivision, std::move(divPromise), a, b);

    auto sumStatus = sumResult.wait_for(std::chrono::seconds(8)); // wait for max 8 seconds;
    auto divStatus = divResult.wait_for(std::chrono::seconds(8));

    if((sumStatus == std::future_status::ready) && (divStatus == std::future_status::ready))
    {
        std::cout << "futures are ready" << std::endl;
        std::cout << "a+b is " << sumResult.get() << std::endl;
        std::cout << "b/a is " << divResult.get() << std::endl;
    }
    else if((sumStatus == std::future_status::timeout) || (divStatus == std::future_status::timeout))
    {
        std::cout << "some of the futures timeouted!" << std::endl;
    }

    t1.join();
    t2.join();
}