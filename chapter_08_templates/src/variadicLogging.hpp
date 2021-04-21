#pragma once
#include <iostream>

template <typename T>
void variadicTemplateLogging(T last)
{
    std::cout << last << " DONE" << std::endl;
}

template <typename First, typename... Args>
void variadicTemplateLogging(First first, Args... numbers)
{
    std::cout << first << ", ";
    variadicTemplateLogging(numbers...);
}