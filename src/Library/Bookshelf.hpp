#pragma once
#include "stdafx.h"

#include "Book/BookInterface.hpp"

class Bookshelf
{
public:
    void addBook(std::shared_ptr<BookInterface> book);
    void listAllBooks();

private:
    std::list<std::shared_ptr<BookInterface>> _books;
};