export module nicePrintout;

#include <iostream>
#include <string>

export void nicePrintout(std::string_view input)
{
    std::cout << "May I? " << input << " Thanks.." << std::endl;
}