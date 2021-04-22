/*
    Dependency injection for C++
*/
#define UNUSED(expr) (void)(expr) //clang-tidy

#include <iostream>

#include "Animal.cpp"
#include "EatingImplementation1.cpp"
#include "EatingImplementation2.cpp"
#include "EatingImplementation3.cpp"

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Hello World!" << std::endl;

    //EatingImplementation1 ei1;
    //EatingImplementation2 ei2;
    //EatingImplementation3 ei3;

    {
        Animal<EatingImplementation1> animal1(static_cast<std::string>("Falco"));
        animal1._eater.doEat();
        animal1._eater.makeNoise();
    }
    {
        Animal<EatingImplementation2> animal2(static_cast<std::string>("Rex"));
        animal2._eater.doEat();
        animal2._eater.makeNoise();

        Animal<EatingImplementation3> animal3(static_cast<std::string>("Eagle"));
        animal3._eater.doEat();
        animal3._eater.makeNoise();
    }
    {
        Animal<> animal4(static_cast<std::string>("Fishy fishy"));
        animal4._eater.doEat();
        animal4._eater.makeNoise();
    }

    return 0;
}
