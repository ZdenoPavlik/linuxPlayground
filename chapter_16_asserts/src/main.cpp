#include <type_traits>
#include <assert.h>
#include <iostream>

template <typename T, typename R>
void calculateSomething(T i, R j, int* third)
{
    assert((std::is_same_v<T, R>));                                   // runtime, watch out for passing two arguments to assert....
    static_assert((std::is_same_v<T, R>), "Types are not the same!"); // compile time

    assert(third != nullptr); // meaningfull usage of runtime assert

    std::cout << "- " << i + j << std::endl;
    std::cout << "- " << i - j << std::endl;
    std::cout << "- " << &third << " " << third << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    calculateSomething<int, int>(1, 2, (int*)5);
    // calculateSomething<int, short>(1, 2, (int*)5);
    // calculateSomething<int, int>(1, 2, nullptr);

    return 0;
}
