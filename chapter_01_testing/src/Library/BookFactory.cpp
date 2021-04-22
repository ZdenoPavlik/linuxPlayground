#include "BookFactory.hpp"

BookFactory *BookFactory::instance = nullptr;

BookFactory::BookFactory()
{
    std::cout << "Instantiating BookFactory" << std::endl;
}

BookFactory *BookFactory::getInstance()
{
    if (BookFactory::instance == nullptr)
    {
        BookFactory::instance = new BookFactory();
    }
    return BookFactory::instance;
}

std::shared_ptr<Book> BookFactory::createBook(std::string bookName)
{
    return std::make_shared<Book>(Book(bookName));
}