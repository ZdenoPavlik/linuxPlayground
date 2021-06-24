#include <iostream>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <functional>

namespace exercise3 {
const unsigned int MIN_BLOCK_SIZE = 10000;

template <typename iterator, typename T>
void my_accumulate(iterator begin, iterator end, T& ref)
{
    ref = std::accumulate(begin, end, 0);
}

template <typename iterator, typename T>
T parallel_accumulate(iterator begin, iterator end, T ref)
{
    auto inputSize = std::distance(begin, end);
    unsigned int allowedThreadsByElement = inputSize / MIN_BLOCK_SIZE;
    unsigned int allowedThreadsByHwCores = std::thread::hardware_concurrency();
    unsigned int finalParallelThreads = std::min(allowedThreadsByElement, allowedThreadsByHwCores);

    const int enableLogs = true;

    if constexpr(enableLogs)
    {
        std::cout << "[ConstExprLog] Thread count to be spawned is " << finalParallelThreads << std::endl;
    }

    auto blockSize = (inputSize + 1) / finalParallelThreads;

    std::vector<T> results(finalParallelThreads);
    std::vector<std::thread> runningThreads(finalParallelThreads - 1);

    iterator last;
    for(unsigned int i = 0; i < finalParallelThreads - 1; i++) // Spawn one thread less than allowed to calculate.
    {
        last = begin;
        std::advance(last, blockSize);
        runningThreads[i] = std::thread(my_accumulate<iterator, T>, begin, last, std::ref(results[i]));
        begin = last;
    }

    results[finalParallelThreads - 1] = std::accumulate(begin, end, results[finalParallelThreads - 1]); // Spare last thread to calculate remaining
    std::for_each(runningThreads.begin(), runningThreads.end(), std::mem_fn(&std::thread::join));       // Call join upon every single running thread

    return std::accumulate(results.begin(), results.end(), ref);
}

void exercise3_parallel_accumulate()
{
    const int elementSize = 100'000'123;
    std::vector<int> numbers(elementSize);
    std::generate(numbers.begin(), numbers.end(), [n = 0]() mutable { return n++; });

    auto start = std::chrono::steady_clock::now();

    auto result = std::accumulate(numbers.begin(), numbers.end(), 0); // Expensive operation

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result is " << result << std::endl;
    std::cout << "Elapsed time for ACCUMULATE, serial variant: " << elapsed.count() << std::endl;

    //---------------------------
    start = std::chrono::steady_clock::now();

    int init = 0;
    result = parallel_accumulate<decltype(numbers.begin()), std::decay_t<decltype(*numbers.begin())>>(
        numbers.begin(), numbers.end(), std::ref(init)); // Parallelized operation

    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result is " << result << std::endl;
    std::cout << "Elapsed time for ACCUMULATE, parallel variant: " << elapsed.count() << std::endl;
}
} // namespace exercise3