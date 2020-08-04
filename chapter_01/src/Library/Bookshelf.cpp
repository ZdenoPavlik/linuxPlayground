#include "Bookshelf.hpp"

void Bookshelf::addBook(std::shared_ptr<BookInterface> book)
{
    std::cout << "Adding book " << book->getBookName() << std::endl;
    _books.push_back(book);
}

void Bookshelf::listAllBooks()
{
    std::cout << "List of books :" << std::endl;
    for (auto book : _books)
    {
        std::cout << " - " << book->getBookName() << std::endl;
    }
}