#include "test/stdafx_test.h"
#include "src/Library/Book/Book.hpp"

TEST(SimpleUnitTestForBook, simpleTest)
{
    Book myBook("Shawshank");

    EXPECT_STREQ(myBook.getBookName().c_str(), "Shawshank");
    std::cout << "Here is book name " << myBook.getBookName() << std::endl;
}

TEST(SimpleUnitTestForBook, strictText)
{
    Book myBook("Shawshank");

    EXPECT_STREQ(myBook.getBookName().c_str(), "Green Mile");
    std::cout << "PRINTED - Here is book name " << myBook.getBookName() << std::endl;

    ASSERT_STREQ(myBook.getBookName().c_str(), "Hannibal");
    std::cout << "NOT PRINTED - Here is book name " << myBook.getBookName() << std::endl;
}