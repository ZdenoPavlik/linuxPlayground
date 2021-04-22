#include <iostream>
#include <string>

//#include "EatingInterface.cpp"
#include "EatingImplementationDefault.cpp"

template <typename EatingInterface = EatingImplementationDefault>
class Animal
{
public:
    Animal(std::string animalName)
        : _animalName(animalName)
    {
        std::cout << "Creating animal of name " << _animalName << std::endl;
    }

    virtual ~Animal()
    {
        std::cout << "Destructing animal of name " << _animalName << std::endl;
    }

    EatingInterface _eater;

private:
    std::string _animalName;
};