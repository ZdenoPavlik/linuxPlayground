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
        std::cout << "Hello from clazz 1" << std::endl;
    }

    void hello1() const
    {
        std::cout << "Clazz 1: Hello" << std::endl;
    }
};

class Clazz2
{
public:
    void operator()() const
    {
        std::cout << "Hello from clazz 2" << std::endl;
    }
};

class Clazz3
{
public:
    void hello() const
    {
        std::cout << "Hello from clazz 3" << std::endl;
    }
};

struct DetermingVisitor
{
    void operator()(const Clazz1& c1)
    {
        c1.hello1();
    }
    void operator()(const Clazz2& c2)
    {
        c2();
    }
    void operator()(const Clazz3& c3)
    {
        c3.hello();
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

    std::variant<int, bool, char> newApproach;
    // newApproach = 42;
    std::cout << "Variant1: " << std::get<int>(newApproach) << std::endl;
    newApproach = 42;
    newApproach = true;
    std::cout << "Variant2: " << std::get<bool>(newApproach) << std::endl;
    // std::cout << "Variant3: " << std::get<int>(newApproach) << std::endl;

    std::cout << "Variant4: holds currently alternative for char: " << std::holds_alternative<char>(newApproach) << std::endl;
    std::cout << "Variant4: holds currently alternative for bool: " << std::holds_alternative<bool>(newApproach) << std::endl;

    std::cout << "Variant5: pointer to bool: " << std::get_if<bool>(&newApproach) << std::endl;
    std::cout << "Variant6: pointer to int: " << std::get_if<int>(&newApproach) << std::endl;

    //----------------------------
    // https://en.cppreference.com/w/cpp/utility/variant
    // https://en.cppreference.com/w/cpp/utility/variant/visit
    // https://www.bfilipek.com/2018/06/variant.html
    // https://www.bfilipek.com/2018/09/visit-variants.html
    // https://www.bfilipek.com/2020/04/variant-virtual-polymorphism.html
    // https://bitbashing.io/std-visit.html

    std::variant<Clazz1, Clazz2> clazzesVariant;

    auto myVisitor = [](auto input) { input(); };
    std::visit(myVisitor, clazzesVariant);
    clazzesVariant = Clazz2();
    std::visit(myVisitor, clazzesVariant);

    //-----------------------------
    std::variant<Clazz1, Clazz2, Clazz3, int, std::string> anotherClazzesVariant;
    std::visit(DetermingVisitor(), anotherClazzesVariant);

    anotherClazzesVariant = Clazz2();
    std::visit(DetermingVisitor(), anotherClazzesVariant);

    anotherClazzesVariant = Clazz3();
    std::visit(DetermingVisitor(), anotherClazzesVariant);

    anotherClazzesVariant = 42;
    std::visit(DetermingVisitor(), anotherClazzesVariant);

    anotherClazzesVariant = "43";
    std::visit(DetermingVisitor(), anotherClazzesVariant);

    // M.CH. std::overloaded

    return 0;
}
