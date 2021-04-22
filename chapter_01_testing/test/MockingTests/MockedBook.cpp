#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/Library/Book/BookInterface.hpp"

class MockedBook : public BookInterface
{
public:
    MockedBook(string bookName)
        : BookInterface(bookName){};
    MOCK_METHOD(string, getBookName, (), (override));
};