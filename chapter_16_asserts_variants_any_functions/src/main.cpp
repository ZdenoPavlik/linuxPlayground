#include <type_traits>
#include <assert.h>
#include <iostream>
#include <variant>
#include <any>
#include <functional>

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

int thirdSquare(int i)
{
    return i * i * i;
}

int minus(int i, int j)
{
    return i - j;
}

int main()
{
    std::cout << std::boolalpha;

    std::cout << "----------------- ASSERTIONS -----------------" << std::endl;
    calculateSomething<int, int>(1, 2, (int*)5);
    // calculateSomething<int, short>(1, 2, (int*)5);
    // calculateSomething<int, int>(1, 2, nullptr);

    std::cout << "----------------- VARIANT -----------------" << std::endl;
    std::variant<int, char, std::string> var; // ! holds a value of one of its alternative types

    // var = 15;
    var = 'a';
    // var = "test";

    try
    {
        // std::cout << "Int: " << std::get<int>(var) << std::endl;
        std::cout << "Char: " << std::get<char>(var) << std::endl;
        // std::cout << "String: " << std::get<std::string>(var) << std::endl;

        //
        std::cout << "Index: " << var.index() << ", is in ivalid state:" << var.valueless_by_exception() << std::endl;
        std::cout << "Holds alternative: int[" << std::holds_alternative<int>(var) << "], char[" << std::holds_alternative<char>(var) << "], string["
                  << std::holds_alternative<std::string>(var) << "]" << std::endl;

        if(auto pval = std::get_if<char>(&var))
            std::cout << "variant value: " << *pval << '\n';
        else
            std::cout << "failed to get value!" << '\n';
    }
    catch(std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------------- ANY -----------------" << std::endl;
    std::any a = 1;
    std::cout << std::endl << a.type().name() << ": " << std::any_cast<int>(a) << std::endl;

    a = true;
    // std::cout << std::any_cast<int>(a); //! will cause "bad any_cast" exception
    std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << std::endl;

    a = (std::string) "any cast";
    std::cout << a.type().name() << ": " << std::any_cast<std::string>(a) << std::endl
              << std::endl; // Does not work perfectly with other than primitive types, but works...

    // FUNCTION
    std::cout << "----------------- FUNCTION -----------------" << std::endl;
    std::function f1 = [](int i) { return i * i; }; // 1st lambra expression
    std::cout << f1(5) << std::endl;

    std::function f2 = thirdSquare; // 2nd function wrapper
    std::cout << f2(5) << std::endl;

    std::function<int(int, int)> f3 = std::bind(minus, std::placeholders::_2, std::placeholders::_1); // 3rd bind expression
    std::cout << minus(5, 2) << ", " << f3(5, 2) << std::endl;

    std::cout << std::endl << std::endl;

    return 0;
}
