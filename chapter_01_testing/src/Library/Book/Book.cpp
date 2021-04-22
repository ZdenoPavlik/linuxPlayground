#include "Book.hpp"

Book::Book(string bookName) : BookInterface(bookName)
{
    std::cout << "Created book with name " << _bookName << std::endl;
}

std::string Book::getBookName()
{
    return _bookName;
}