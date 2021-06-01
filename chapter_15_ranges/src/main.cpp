#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    const std::vector<int> values{0, 1, 2, 3, 4, 5, 6};
    auto even = [](const int i) { return 0 == i % 2; };
    auto square = [](const int i) { return i * i; };

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

    return 0;
}
