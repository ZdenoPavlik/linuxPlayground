#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <boost/current_function.hpp>

namespace test2 {

int sharedNumber = 0;
std::atomic<int> atomicSharedNumber;

std::chrono::milliseconds getRandomTime()
{
    auto returnVal = (rand() % 50) * 10;
    return static_cast<std::chrono::milliseconds>(returnVal);
}

void task_withAtomic(std::string threadName, int appendVal)
{
    for(int i = 0; i < 5; i++)
    {
        atomicSharedNumber += appendVal;
        std::cout << "[task_withAtomic]Thread " << threadName << " modified atomicSharedNumber to " << atomicSharedNumber << std::endl;
        std::this_thread::sleep_for(getRandomTime());
    }
}

void taskWithoutAtomic(std::string threadName, int appendVal)
{
    for(int i = 0; i < 5; i++)
    {
        sharedNumber += appendVal;
        std::cout << "[taskWithoutAtomic] Thread " << threadName << " modified sharedNumber to " << sharedNumber << std::endl;
        std::this_thread::sleep_for(getRandomTime());
    }
}

void test2_withAtomic()
{
    std::thread t1(task_withAtomic, "t1", 1);
    std::thread t2(task_withAtomic, "t2", 10);
    std::thread t3(task_withAtomic, "t3", 100);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "********************************************" << std::endl;
}

void test2_withoutAtomic()
{
    std::thread t1(taskWithoutAtomic, "t1", 1);
    std::thread t2(taskWithoutAtomic, "t2", 10);
    std::thread t3(taskWithoutAtomic, "t3", 100);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "********************************************" << std::endl;
}

} // namespace test2