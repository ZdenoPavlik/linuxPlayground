#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <functional>
#include <numeric>
#include <cassert>

namespace exercise5 {
const unsigned int MIN_BLOCK_SIZE = 1000;

template <typename iterator, typename T>
T parallel_accumulate_async(iterator begin, iterator end)
{
    unsigned int sampleCount = std::distance(begin, end);
    unsigned int parallelTaskAmount = std::min(std::thread::hardware_concurrency(), (sampleCount / MIN_BLOCK_SIZE));
    unsigned int blockSize = sampleCount / parallelTaskAmount;

    if constexpr(true)
    {
        std::cout << "[ConstExprLog] Thread count - " << parallelTaskAmount << std::endl;
        std::cout << "[ConstExprLog] Block size -  " << blockSize << std::endl;
    }

    // std::vector<T> results(parallelTaskAmount);
    std::vector<std::future<T>> tasks(parallelTaskAmount);

    iterator blockEnd = begin;
    for(unsigned int i = 0; i < (parallelTaskAmount - 1); i++)
    {
        std::advance(blockEnd, blockSize);
        tasks[i] = std::async(std::launch::async, std::accumulate<iterator, T>, begin, blockEnd, 0);
        begin = blockEnd;
    }

    tasks[parallelTaskAmount - 1] = std::async(std::launch::async, std::accumulate<iterator, T>, blockEnd, end, 0);

    T result = 0;
    for(std::future<T>& task : tasks)
    {
        result += task.get();
    }

    return result;
}

void exercise5_parallel_accumulate_async()
{
    std::cout << "------------------- BEGIN exercise5_parallel_accumulate_async -------------------" << std::endl;
    const int elementSize = 100'000'123;
    std::vector<int> numbers(elementSize);
    std::generate(numbers.begin(), numbers.end(), [n = 0]() mutable { return n++; });

    auto start = std::chrono::steady_clock::now();

    auto resultSimple = std::accumulate(numbers.begin(), numbers.end(), 0); // Expensive operation

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result is " << resultSimple << std::endl;
    std::cout << "Elapsed time for ACCUMULATE, serial variant: " << elapsed.count() << std::endl;

    //---------------------------
    start = std::chrono::steady_clock::now();

    auto resultParallel = parallel_accumulate_async<decltype(numbers.begin()), std::decay_t<decltype(*numbers.begin())>>(
        numbers.begin(), numbers.end()); // Parallelized operation

    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result is " << resultParallel << std::endl;
    std::cout << "Elapsed time for ACCUMULATE, parallel variant with async: " << elapsed.count() << std::endl;
    std::cout << "------------------- END exercise5_parallel_accumulate_async -------------------" << std::endl << std::endl;

    assert(resultSimple == resultParallel && "Results are different!");
}
} // namespace exercise5