#pragma once

#include "BookInterface.hpp"
class Book final : public BookInterface
{
public:
    Book(string bookName);
    virtual ~Book() {};
    std::string getBookName() override;
};