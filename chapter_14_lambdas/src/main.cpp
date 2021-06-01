/*
    Playground project for C++
*/
#include <iostream>
#include <vector>
#include <algorithm>

void lambdaFunction()
{
    int globalVar = 42;
    std::vector<int> values{1, 2, 3, 4, 5};

    auto lambdaFunc = [&](int input) { std::cout << (input + globalVar) << ", "; };

    // 1st approach
    for(auto i : values)
    {
        lambdaFunc(i);
    }

    std::cout << std::endl;
    // 2nd approach
    std::for_each(values.begin(), values.end(), lambdaFunc);

    std::cout << std::endl;
}

int main()
{
    lambdaFunction();

    return 0;
}
