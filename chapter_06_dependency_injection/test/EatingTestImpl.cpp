#include <iostream>
#include "../src/EatingInterface.cpp"

class EatingTestImpl : public EatingInterface
{
public:
    void doEat()
    {
        std::cout << "[EatingTESTImpl] doEat" << std::endl;
    };

    void makeNoise()
    {
        std::cout << "[EatingTESTImpl] makeNoise" << std::endl;
    };
};
