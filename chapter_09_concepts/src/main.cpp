/*
    Playground project for C++
*/

#include <iostream>

template <class T>
concept Unchangeable = std::is_const<T>::value;

template <class T>
concept EasilyIncDecrementable = std::is_integral<T>::value&& std::is_trivial<T>::value&& std::is_arithmetic_v<T>;

template <typename T>
requires Unchangeable<T>&& EasilyIncDecrementable<T> void calculationFunction(T num1, T num2)
{
    std::cout << "Diff is " << (num1 - num2) << std::endl;
    std::cout << "Sum is " << (num1 + num2) << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    // supported by at least gcc 10
    calculationFunction<const int>(1, 5);
    calculationFunction<int>(1, 5);                     //not compileable, T is not "const"
    calculationFunction<std::string>("aa", "bb");       //not compileable, T is not "const". If it is "EasilyIncDecrementable" is not evaluated
    calculationFunction<const std::string>("aa", "bb"); //not compileable, T is not "EasilyIncDecrementable"

    return 0;
}
