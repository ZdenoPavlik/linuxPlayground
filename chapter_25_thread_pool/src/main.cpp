
#include <iostream>
#include <atomic>
#include <queue>
#include <functional>
#include <thread>
#include <threadSafeQeueue.hpp>

// https://github.com/ZdenoPavlik/cpp_concurrency_masterclass/blob/master/s8_simple_threadpool/simple_thread_pool.h#L32

class thread_pool
{
public:
    thread_pool()
        : done(false)
    {
        unsigned int const thread_count = std::thread::hardware_concurrency();

        try
        {
            for(int i = 0; i < thread_count; i++)
            {
                threads.push_back(std::thread(&thread_pool::worker_thread, this));
            }
        }
        catch(...)
        {
            done = true;
            std::cout << "ERROR!" << std::endl;
            throw;
        }
    }

    ~thread_pool()
    {
        done = false;
    }

    template <typename function_type>
    void submit(function_type f)
    {
        work_queue.push(std::function<void()>(f));
    }

private:
    std::atomic_bool done; // global command to terminate all threads
    thread_safe_queue<std::function<void()>> work_queue;
    std::vector<std::jthread> threads;

    void worker_thread()
    {
        while(!done)
        {
            std::function<void()> task;
            if(work_queue.pop(task))
            {
                task();
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }
};

int main()
{
    std::cout << "Testing thread pool!" << std::endl;

    thread_pool pool;
    for(unsigned int i = 0; i < 100; i++)
    {
        pool.submit([=]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << i << " - Printed by thread " << std::this_thread::get_id() << std::endl;
        });
    }

    return 0;
}
