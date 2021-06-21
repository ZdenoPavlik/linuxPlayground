#pragma once
#include <thread>

class thread_guard
{
public:
    explicit thread_guard(std::thread& t)
        : _t(t){};

    ~thread_guard()
    {
        if(_t.joinable())
        {
            _t.join();
        }
    }

    thread_guard(const thread_guard& other) = delete;
    thread_guard(thread_guard&& other) noexcept = delete;
    thread_guard& operator=(const thread_guard& other) = delete;
    thread_guard& operator=(thread_guard&& other) noexcept = delete;

private:
    std::thread& _t;
};
