#include <type_traits>

#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Is FLOAT with decimal point? Answer is " << std::is_floating_point<float>::value << std::endl;
    std::cout << "Is INT with decimal point? Answer is " << std::is_floating_point<int>::value << std::endl;

    int iOrigin = 42;

    int* i0 = nullptr;
    i0 = new int(42);
    *i0 = 43;

    const int* i1 = nullptr; //pointer to const object
    i1 = new int(42);
    //*i1 = 45;

    int* const i2 = nullptr; //const pointer to object
    //i2 = new int(42);

    int const* i3 = nullptr; // pointer to const object
    i3 = new int(42);
    //*i3 = 43;

    std::cout << std::endl;
    return 0;
}
