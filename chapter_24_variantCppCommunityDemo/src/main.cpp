#include <iostream>
#include <variant>

union oldApproach
{
    int intUn;
    bool boolUn;
    char charUn;
};

class Clazz1
{
public:
    void operator()() const
    {
        std::cout << "Hello from clazz1" << std::endl;
    }
};

class Clazz2
{
public:
    void operator()() const
    {
        std::cout << "Hello from clazz2" << std::endl;
    }
};

struct DetermingVisitor
{
    void operator()(const Clazz1& c1)
    {
        c1();
    }
    void operator()(const Clazz2& c2)
    {
        c2();
    }
    void operator()(const int i)
    {
        std::cout << "Int: " << i << std::endl;
    }
    void operator()(const std::string& s)
    {
        std::cout << "String: " << s << std::endl;
    }
};

int main()
{
    std::cout << std::boolalpha;

    oldApproach union1;
    union1.intUn = 64;
    std::cout << "Union: " << union1.boolUn << std::endl;
    std::cout << "Union: " << union1.intUn << std::endl;
    std::cout << "Union: " << union1.charUn << std::endl;

    std::variant<int, bool, char> newApproach; // default initializes 1st element
    std::cout << "Variant: " << std::get<int>(newApproach) << std::endl;
    std::cout << "Variant currently holds alternative for char - " << std::holds_alternative<char>(newApproach) << std::endl;
    // std::cout << "Variant: " << std::get<char>(newApproach) << std::endl;
    std::cout << "Variant: " << std::get_if<bool>(&newApproach) << std::endl;
    std::cout << "Variant: " << std::get_if<int>(&newApproach) << std::endl;

    // https://en.cppreference.com/w/cpp/utility/variant
    // https://en.cppreference.com/w/cpp/utility/variant/visit
    // https://www.bfilipek.com/2018/06/variant.html
    // https://www.bfilipek.com/2018/09/visit-variants.html
    // https://www.bfilipek.com/2020/04/variant-virtual-polymorphism.html
    // https://bitbashing.io/std-visit.html
    std::variant<Clazz1, Clazz2> clazzesVariant;

    auto visitor = [](auto in) {
        in(); // in.sayHello()
    };        // Callable object, functor, lambda,
    std::visit(visitor, clazzesVariant);
    clazzesVariant = Clazz2();
    std::visit(visitor, clazzesVariant);

    std::variant<Clazz1, Clazz2, int, std::string> mixedVariant;
    std::visit(DetermingVisitor{}, mixedVariant);
    mixedVariant = 42;
    std::visit(DetermingVisitor{}, mixedVariant);
    mixedVariant = "Meow"; // or string("Meow")
    std::visit(DetermingVisitor{}, mixedVariant);

    /**
     std::variant<Fluid, LightItem, HeavyItem, FragileItem> package;

     std::visit(overload{
            [](Fluid& ) { cout << "fluid\n"; },
            [](LightItem& ) { cout << "light item\n"; },
            [](HeavyItem& ) { cout << "heavy item\n"; },
            [](FragileItem& ) { cout << "fragile\n"; }
        }, package);
     *
     */
    // Possible uses
    // Input, where you can get different types (i.e. input process args, ini files, ..)
    // Returning error result of operation, where you need more than std::optional -> i.e. std::variant<int errorCode, class successResult>
    // Polymorphism without vtables and inheritance

    return 0;
}
