#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main()
{
    using namespace std::chrono_literals; // 2000 ms instead of std::chrono::microseconds(2000)
    using namespace std;

    // stopwatch
    auto system_start = chrono::system_clock::now();
    std::this_thread::sleep_for(1'000'000us);
    auto system_end = chrono::system_clock::now();
    auto system_elapsed = system_end - system_start;
    std::cout << "System clock, elapsed " << chrono::duration_cast<chrono::microseconds>(system_elapsed).count() << " us" << std::endl;

    auto steady_start = chrono::steady_clock::now();
    std::this_thread::sleep_for(1'000'000us);
    auto steady_end = chrono::steady_clock::now();
    auto steady_elapsed = steady_end - steady_start;
    std::cout << "Steady clock, elapsed " << chrono::duration_cast<chrono::microseconds>(steady_elapsed).count() << " us" << std::endl;

    std::chrono::duration<double, std::milli> elapsed_mili = steady_end - steady_start;
    std::cout << "Steady clock, elapsed in miliseconds " << elapsed_mili.count() << " ms" << std::endl;

    //
    const std::time_t t_c = chrono::system_clock::to_time_t(chrono::system_clock::now());
    std::cout
        << "System clock, now "
        << std::put_time(std::localtime(&t_c),
               "ISO 8601 Time[%T] --- ISO 8601 Date[%F] --- Minute Hour[%R] --- time zone name[%Z] --- Full weekday[%A] --- Week of the year[%V]")
        << std::endl; // https://en.cppreference.com/w/cpp/io/manip/put_time

    // const std::time_t steady_t_c = chrono::system_clock::to_time_t(chrono::steady_clock::now()); // intended nonsense, fortunatelly not even
    // compileable

    const std::time_t t_c_2 = chrono::system_clock::to_time_t(chrono::system_clock::now() + 17min);
    std::cout << "In 17 minutes it will be " << std::put_time(std::localtime(&t_c_2), "%R") << std::endl;

    const std::time_t t_c_3 = chrono::system_clock::to_time_t(chrono::system_clock::now() - 23min - 2h - 30s);
    std::cout << "Before 2hours, 23 min and 30sec was " << std::put_time(std::localtime(&t_c_3), "%T") << std::endl;

    const std::time_t t_c_4 = chrono::system_clock::to_time_t(chrono::system_clock::now() - 3600s);
    std::cout << "3600 seconds ago was " << std::put_time(std::localtime(&t_c_4), "%T") << std::endl;

    // Time since epoch
    const auto epoch = std::chrono::system_clock::to_time_t(std::chrono::time_point<std::chrono::system_clock>{});
    std::cout << "Epoch: " << std::ctime(&epoch) << std::endl;

    std::cout << "Hours since epoch: " << std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now().time_since_epoch()).count()
              << std::endl;

    std::cout << "Yesterday Hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>((std::chrono::system_clock::now() - 24h).time_since_epoch()).count() << std::endl;

    std::cout << std::endl << std::endl;

    return 0;
}
