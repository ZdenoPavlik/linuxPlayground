#include <iostream>
#include <thread>
#include <condition_variable>
#include <stack>

namespace example4 {
std::mutex m_mutex;
std::condition_variable m_cv;
std::stack<int> m_stack;

void waitingForNumber(std::string name)
{
    std::unique_lock<std::mutex> uLock(m_mutex);
    m_cv.wait(uLock, []() { return !m_stack.empty(); });
    std::cout << name << " got number " << m_stack.top() << std::endl;
    m_stack.pop();
}

void generateNumber()
{
    for(int i = 0; i < 5; i++)
    {
        m_stack.emplace(i);
        m_cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void exercise4_condition_variable()
{
    std::thread generator(generateNumber);

    std::thread t1(waitingForNumber, "t1");
    std::thread t2(waitingForNumber, "t2");
    std::thread t3(waitingForNumber, "t3");
    std::thread t4(waitingForNumber, "t4");
    std::thread t5(waitingForNumber, "t5");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    generator.join();
}
} // namespace example4