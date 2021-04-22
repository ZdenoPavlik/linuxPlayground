#include <iostream>
#include "EatingInterface.cpp"

class EatingImplementation1 : public EatingInterface
{
public:
    void doEat()
    {
        std::cout << "[EatingImplementation1] doEat" << std::endl;
    };

    void makeNoise()
    {
        std::cout << "[EatingImplementation1] makeNoise" << std::endl;
    };
};
