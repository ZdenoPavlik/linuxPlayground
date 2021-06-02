#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main()
{
    const std::vector<int> values{0, 1, 2, 3, 4, 5, 6};
    auto even = [](const int i) { return 0 == i % 2; };
    auto square = [](const int i) { return i * i; };

    // VIEWS
    // 1st approach
    for(int i : values | std::views::filter(even) | std::views::transform(square))
    {
        std::cout << i << " ";
    };

    std::cout << std::endl << std::endl;

    // 2nd approach
    for(int i : std::views::transform(std::views::filter(values, even), square))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;

    // 3rd approach
    auto filtered = std::views::transform(std::views::filter(values, even), square);
    std::for_each(filtered.begin(), filtered.end(), [](auto i) { std::cout << i << " "; });

    std::cout << std::endl << std::endl;

    // RANGES
    // https://hannes.hauswedell.net/post/2019/11/30/range_intro/
    std::vector<int> valuesRanges(20);
    std::generate(valuesRanges.begin(), valuesRanges.end(), [n = 0]() mutable { return n++; }); // 0,1,2,3,...
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end());                              // random shuffle
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 1st
    std::cout << std::endl << std::endl << "Old school sorting with begin() + end()" << std::endl;
    std::sort(valuesRanges.begin(), valuesRanges.end());
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 2nd
    std::cout << std::endl << std::endl << "begin() + end(), filtering only first 5 elements. This is advantage of being+end approach" << std::endl;
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end()); // random shuffle
    std::sort(valuesRanges.begin(), valuesRanges.begin() + 5);
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 3rd
    std::cout << std::endl << std::endl << "begin() + end(),reverse filtering" << std::endl;
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end()); // random shuffle
    std::sort(valuesRanges.rbegin(), valuesRanges.rend());
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 4th
    std::cout << std::endl << std::endl << "std::ranges::sort" << std::endl;
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end()); // random shuffle
    std::ranges::sort(valuesRanges);
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 5th
    std::cout << std::endl << std::endl << "std::ranges::sort, only elements after 5th" << std::endl;
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end()); // random shuffle
    std::ranges::sort(std::views::drop(valuesRanges, 5));
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    // 6th
    std::cout << std::endl << std::endl << "std::ranges::sort, reverse sorting" << std::endl;
    std::random_shuffle(valuesRanges.begin(), valuesRanges.end()); // random shuffle
    std::ranges::sort(std::views::reverse(valuesRanges));
    std::for_each(valuesRanges.begin(), valuesRanges.end(), [](auto i) { std::cout << i << " "; });

    //
    std ::cout << std::endl << std::endl;
    std::vector vec{1, 2, 3, 4, 5, 6};
    auto v = vec | std::views::reverse | std::views::drop(2);
    std::ranges::for_each(v, [](auto i) { std::cout << i << " "; });
    std ::cout << std::endl << std::endl << *v.begin() << '\n';

    //
    //  vec | foo | bar(3) | baz(7) is equivalent to baz(bar(foo(vec), 3), 7). -> evaluated from LEFT to RIGHT
    std ::cout << std::endl << std::endl;
    auto evenView = vec | std::views::filter([](auto i) { return 0 == i % 2; }) | std::views::transform([](auto i) { return i * i; });
    std::ranges::for_each(evenView, [](auto i) { std::cout << i << " "; });

    std::cout << std::endl << std::endl;
    return 0;
}
