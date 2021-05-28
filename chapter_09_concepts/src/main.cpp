/*
    Playground project for C++
*/
#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>

/*template <class T>
concept Incrementable = std::is_integral<T>::value;

template <class T>
concept Decrementable = std::is_integral<T>::value;

template <typename T>
requires Incrementable<T>&& Decrementable<T> void calculationFunction(T num1, T num2)
{
    std::cout << "Diff is " << (num1 - num2) << std::endl;
    std::cout << "Sum is " << (num1 + num2) << std::endl;
}*/

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Hello World!" << std::endl;

    //calculationFunction<int>(1, 5); // supported by at least gcc 10

    return 0;
}
