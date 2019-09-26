/*
    Playground project for C++
*/
#include "stdafx.h"
#include "Library/Bookshelf.hpp"
#include "Library/BookFactory.hpp"
#include "Library/Book/Book.hpp"

void addOutOfScopeBooks(Bookshelf &bookshelf)
{
    BookFactory *bookFactory = BookFactory::getInstance();

    bookshelf.addBook(bookFactory->createBook("Eragon"));
    bookshelf.addBook(bookFactory->createBook("Eldest"));
}

int main(int argc, char **argv)
{
    Bookshelf bookshelf;
    BookFactory *bookFactory = BookFactory::getInstance();

    bookshelf.addBook(bookFactory->createBook("White Fang"));
    bookshelf.addBook(bookFactory->createBook("Lord of the Rings"));

    addOutOfScopeBooks(bookshelf);

    bookshelf.listAllBooks();

    char *intendedMemoryLeak = (char *)calloc(1, 100);
    strcpy(intendedMemoryLeak, "This is my intended memory leak");

    return 0;
}
