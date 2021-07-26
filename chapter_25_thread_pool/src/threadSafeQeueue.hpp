#pragma once
#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

template <typename T>
class thread_safe_queue
{
    mutable std::mutex m;
    std::queue<T> queue;

public:
    thread_safe_queue() = default;
    ~thread_safe_queue() = default;
    thread_safe_queue(const thread_safe_queue& other) = delete;                // copy constructor
    thread_safe_queue(thread_safe_queue&& other) noexcept = delete;            // move constructor
    thread_safe_queue& operator=(const thread_safe_queue& other) = delete;     // copy assignment
    thread_safe_queue& operator=(thread_safe_queue&& other) noexcept = delete; // move assignment

    void push(T item)
    {
        std::lock_guard<std::mutex> guard(m);
        queue.push(item);
    }

    T pop(void)
    {
        std::lock_guard<std::mutex> guard(m);
        if(queue.empty())
        {
            throw std::runtime_error("Popping from empty queue");
        }

        auto retF = queue.front();
        queue.pop();
        return retF;
    }

    size_t size() const
    {
        std::lock_guard<std::mutex> guard(m);
        return queue.size();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> guard(m);
        return queue.empty();
    }
};