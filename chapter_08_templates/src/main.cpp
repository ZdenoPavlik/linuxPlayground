#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>
#include <climits>
#include <vector>

#include "Animal.hpp"
#include "sfinae.hpp"
#include "variadicLogging.hpp"

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    playingWithAnimals();
    std::cout << "-----------------------------------------------------------------" << std::endl;
    variadicTemplateLogging<int>(1, 2, 3, 4, 5);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    sfinaePlayground();

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}
