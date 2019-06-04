#include "test/stdafx_test.h"
#include "src/Library/Bookshelf.hpp"
#include "src/Library/Book/BookInterface.hpp"

TEST(BookshelfTest, simpleTest)
{
    EXPECT_EQ(1, 1);
}

class BookMock : BookInterface
{
};