export module rudePrinting;

#include <iostream>
#include <string>

export void rudePrintout(std::string_view input)
{
    std::cout << "HEY YOU! " << input << " !!!" << std::endl;
}