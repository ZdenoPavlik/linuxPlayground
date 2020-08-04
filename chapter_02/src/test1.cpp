#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

namespace test1 {

std::mutex lock;
std::string sharedString;

std::chrono::milliseconds getRandomTime()
{
    auto returnVal = (rand() % 50) * 10;
    return static_cast<std::chrono::milliseconds>(returnVal);
}

void task_withoutGuard(std::string threadName, char appendChar)
{
    sharedString.clear();
    for(int i = 0; i < 5; i++)
    {
        sharedString += appendChar;
        std::cout << "[task_withoutGuard] Thread " << threadName << " modified sharedString to " << sharedString << std::endl;
        std::this_thread::sleep_for(getRandomTime());
    }
}

void task_withGuard(std::string threadName, char appendChar)
{
    std::lock_guard<std::mutex> myLock(lock);
    sharedString.clear();
    for(int i = 0; i < 5; i++)
    {
        sharedString += appendChar;
        std::cout << "[task_withGuard] Thread " << threadName << " modified sharedString to " << sharedString << std::endl;
        std::this_thread::sleep_for(getRandomTime());
    }
}

void test1_withoutLockGuard()
{
    std::thread t1(task_withoutGuard, "t1", 'a');
    std::thread t2(task_withoutGuard, "t2", 'b');
    std::thread t3(task_withoutGuard, "t3", 'c');

    t1.join();
    t2.join();
    t3.join();

    std::cout << "********************************************" << std::endl;
}

void test1_withLockGuard()
{
    std::thread t1(task_withGuard, "t1", 'a');
    std::thread t2(task_withGuard, "t2", 'b');
    std::thread t3(task_withoutGuard, "t3", 'c');

    t1.join();
    t2.join();
    t3.join();

    std::cout << "********************************************" << std::endl;
}

}