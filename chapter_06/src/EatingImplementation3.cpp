#include <iostream>
#include "EatingInterface.cpp"

class EatingImplementation3 : public EatingInterface
{
public:
    void doEat()
    {
        std::cout << "[EatingImplementation3] doEat" << std::endl;
    };

    void makeNoise()
    {
        std::cout << "[EatingImplementation3] makeNoise" << std::endl;
    };
};
