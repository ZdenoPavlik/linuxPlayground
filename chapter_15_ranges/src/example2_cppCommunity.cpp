#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <execution>

template <typename T>
void logValues(const std::string& tag, const std::vector<T>& values)
{
    std::cout << std::endl << tag << " ----------------------" << std::endl;
    for(auto i : values)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl << tag << " ----------------------" << std::endl;
}

template <typename iter>
void logValues(const std::string& tag, iter begin, iter end)
{
    std::cout << std::endl << tag << " ----------------------" << std::endl;
    while(begin != end)
    {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl << tag << " ----------------------" << std::endl;
}

void logValues(const std::string& tag, auto myView)
{
    std::cout << std::endl << tag << " ----------------------" << std::endl;
    for(int i : std::views::all(myView))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl << tag << " ----------------------" << std::endl;
}

void example2_cppCommunity()
{
    // https://hannes.hauswedell.net/post/2019/11/30/range_intro/
    std::cout << "Hello World C++ community" << std::endl;

    std::vector<int> values(20);
    std::generate(values.begin(), values.end(), [n = 0]() mutable { return n++; });
    std::random_shuffle(values.begin(), values.end());
    logValues("default", values.begin(), values.end());

    std::sort(std::execution::par, values.begin(), values.end());
    logValues("old_1", values.begin(), values.end());

    std::sort(values.rbegin(), values.rend());
    logValues("old_2", values.begin(), values.end());

    // RANGES
    std::random_shuffle(values.begin(), values.end());
    std::ranges::sort(values);
    logValues("ranges_1", values.begin(), values.end());

    if(std::ranges::all_of(values, [](const auto i) { return i % 2 == 0; })) // none_of, any_of
    {
        std::cout << "All of values are even" << std::endl;
    }
    else
    {
        std::cout << "Some of values are NOT even" << std::endl;
    }

    // all_of, any_of, none_of
    // std::ranges::binary_search
    // std::ranges::copy_if
    // std::ranges::for_each
    // std::ranges::min
    // std::ranges::partial_sort
    // std::ranges::remove_if

    // VIEW
    std::random_shuffle(values.begin(), values.end());
    std::ranges::sort(values);

    auto view1 = values | std::views::drop(10);
    logValues("view1_1", values);
    logValues("view1_2", view1);

    auto evenLmbd = [](const auto i) { return i % 2 == 0; };
    std::random_shuffle(values.begin(), values.end());
    logValues("view1_3", view1);

    auto view2 = values | std::views::filter(evenLmbd);
    logValues("view2_1", view2);

    auto squareRoot = [](auto i) { return i * i; };
    auto view3 = values | std::views::filter(evenLmbd) | std::views::transform(squareRoot);
    logValues("view3_1", view3);
    logValues("view3_2", values);
}
