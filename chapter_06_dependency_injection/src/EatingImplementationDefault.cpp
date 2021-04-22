#include <iostream>
#include "EatingInterface.cpp"

class EatingImplementationDefault : public EatingInterface
{
public:
    void doEat()
    {
        std::cout << "[EatingImplementationDefault] doEat" << std::endl;
    };

    void makeNoise()
    {
        std::cout << "[EatingImplementationDefault] makeNoise" << std::endl;
    };
};
