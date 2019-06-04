#pragma once

#include "BookInterface.hpp"
class Book : public BookInterface
{
public:
    Book(string bookName);
    std::string getBookName() override;
};