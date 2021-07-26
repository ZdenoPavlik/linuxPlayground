
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
        auto thread_count = std::thread::hardware_concurrency();
        std::cout << "Using " << thread_count << " threads" << std::endl;

        try
        {
            for(unsigned int i = 0; i < thread_count; i++)
            {
                threads.push_back(std::jthread(thread_pool::worker_function, this));
                std::cout << std::hex << "Added to pool thread ID 0x" << threads[i].get_id() << std::endl;
            }
            std::cout << std::endl;
        }
        catch(...)
        {
            done.store(true);
            std::cout << "ERROR!" << std::endl;
            throw;
        }
    }

    ~thread_pool()
    {
        std::cout << "Setting DONE to TRUE" << std::endl;
        done.store(true);
    }

    template <typename function_type>
    void submit(function_type f)
    {
        work_queue.push(std::function<void()>(f));
        // this->workerCV.notify_one();
    }

    bool workQueueEmpty() const
    {
        return work_queue.empty();
    }

    void setWorkDone()
    {
        this->done.store(true);
        // this->workerCV.notify_all();
    }

private:
    std::atomic_bool done; // global command to terminate all threads
    thread_safe_queue<std::function<void()>> work_queue;
    std::vector<std::jthread> threads;
    // std::condition_variable workerCV;
    // std::mutex workerM;

    static void worker_function(thread_pool* instance)
    {
        while(!instance->done.load())
        {
            // std::unique_lock<std::mutex> lk(instance->workerM);
            // instance->workerCV.wait(lk, [&instance] { return !instance->work_queue.empty(); });

            std::this_thread::sleep_for(std::chrono::milliseconds(30));

            if(!instance->work_queue.empty())
            {
                auto function = instance->work_queue.pop();
                function();
            }
            // else
            //{
            //    std::this_thread::yield();
            //}

            // lk.unlock();
            // instance->workerCV.notify_one();
        }
    }
};

int main()
{
    std::cout << "-------- Thread pool --------" << std::endl;
    std::cout << std::hex << "ID of main thread is 0x" << std::this_thread::get_id() << std::endl;

    thread_pool pool;
    for(unsigned int i = 0; i < 20; i++)
    {
        pool.submit([=]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << std::dec << i << " - Printed by thread 0x" << std::hex << std::this_thread::get_id() << std::endl;
        });
    }

    while(!pool.workQueueEmpty())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    pool.setWorkDone();

    return 0;
}