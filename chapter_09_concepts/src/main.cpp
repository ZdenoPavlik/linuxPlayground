#include <iostream>
#include <type_traits>

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

//----------------------
struct MyFunctor
{
    void operator()()
    {
        std::cout << "Functor object" << std::endl;
    }
};

template <typename T>
concept FunctorsOnly = std::is_invocable<void, T, void>::value;
//std::is_invocable_r_v<void()(), decltype(T), void>;

template <typename Functor>
requires FunctorsOnly<Functor> void printOutFunctor(Functor& i)
{
    i();
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    //Benefits -> in case of compilation fail the error message is way more meaningfull

    // supported by at least gcc 10
    calculationFunction<const int>(1, 5);
    //calculationFunction<int>(1, 5);                     //not compileable, T is not "const"
    //calculationFunction<std::string>("aa", "bb");       //not compileable, T is not "const". If it is "EasilyIncDecrementable" is not evaluated
    //calculationFunction<const std::string>("aa", "bb"); //not compileable, T is not "EasilyIncDecrementable"

    //---------------
    MyFunctor test;
    test();
    //printOutFunctor<MyFunctor>(test);
    //printOutFunctor<int>(15);

    return 0;
}
