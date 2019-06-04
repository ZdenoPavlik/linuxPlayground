#pragma once
#include "stdafx.h"
#include "Book/Book.hpp"

class BookFactory
{
private:
    BookFactory();
    static BookFactory *instance;

public:
    static BookFactory *getInstance();
    std::shared_ptr<Book> createBook(std::string bookName);
};