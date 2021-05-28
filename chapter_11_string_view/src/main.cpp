
#include <iostream>
#include <chrono>
#include <string_view>

std::string returnString()
{
    return "raw string";
}

const std::string stringViewOrigin("string view");
std::string_view returnStringView()
{
    return stringViewOrigin;
}

int main()
{
    const int counter = 10'000'000;

    //--Test string
    auto start = std::chrono::system_clock::now();

    for(int i = 0; i < counter; i++)
    {
        returnString();
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::endl
              << "Elapsed time for RAW string: " << elapsed.count() << std::endl;

    //--Test string view
    start = std::chrono::system_clock::now();

    for(int i = 0; i < counter; i++)
    {
        returnStringView();
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::endl
              << "Elapsed time for string VIEW: " << elapsed.count() << std::endl;

    return 0;
}
