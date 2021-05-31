#include <iostream>
#include <type_traits>
#include <utility>

double a;

decltype(a) probablyDouble;
decltype(&a) probablyDoublePointer;

// --
int globInt = 1;
int& globIntRef = globInt;

int foo(int i)
{
    return i;
}

std::string foo(std::string i)
{
    return i;
}

bool foo(bool i)
{
    return i;
}

int main()
{
    // decltype
    std::cout << std::boolalpha;

    std::cout << "Double:" << std::endl;
    std::cout << " - " << std::is_same_v<double, decltype(a)> << std::endl;
    std::cout << " - " << std::is_same_v<double, decltype(probablyDouble)> << std::endl;
    std::cout << " - " << std::is_same_v<double*, decltype(probablyDoublePointer)> << std::endl;      //_v
    std::cout << " - " << std::is_same<double*, decltype(probablyDoublePointer)>::value << std::endl; //::value

    decltype(1) i = 42;
    std::cout << "Integer:" << std::endl;
    std::cout << " - " << std::is_same_v<int, decltype(i)> << std::endl;
    std::cout << " - " << std::is_same_v<int*, decltype(&i)> << std::endl; //_v

    std::cout << "Reference to integer:" << std::endl;
    std::cout << " - " << std::is_same_v<int, decltype(globInt)> << std::endl;
    std::cout << " - " << std::is_same_v<int&, decltype(globIntRef)> << std::endl;

    // decltype vs auto
    // https://stackoverflow.com/questions/12084040/decltype-vs-auto
    decltype(globIntRef) reference = globInt;
    auto rawInt = globIntRef;

    std::cout << " - " << std::is_same_v<int&, decltype(reference)> << std::endl; // decltype gives EXACT type, in this case int&
    std::cout << " - " << std::is_same_v<int, decltype(rawInt)> << std::endl;     // auto will give you only the type, in this case int

    // declval
    std::cout << "Declval:" << std::endl;

    decltype(foo(std::declval<int>())) deductedInt; // what type will I get when I call foo with "int" as input?
    std::cout << " - " << std::is_same_v<int, decltype(deductedInt)> << std::endl;

    decltype(foo(std::declval<std::string>())) deductedString; // -- "string" --
    std::cout << " - " << std::is_same_v<std::string, decltype(deductedString)> << std::endl;

    decltype(foo(std::declval<bool>())) deductedBool; // -- "bool" --
    std::cout << " - " << std::is_same_v<bool, decltype(deductedBool)> << std::endl;

    decltype(foo(std::declval<short>())) deductedShort; // -- "short" is casted to "int" --
    std::cout << " - " << std::is_same_v<int, decltype(deductedShort)> << std::endl;

    return 0;
}
