#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Hello World!" << std::endl;

    return 0;
}
