#include <iostream>
#include "EatingInterface.cpp"

class EatingImplementation2 : public EatingInterface
{
public:
    void doEat()
    {
        std::cout << "[EatingImplementation2] doEat" << std::endl;
    };

    void makeNoise()
    {
        std::cout << "[EatingImplementation2] makeNoise" << std::endl;
    };
};
