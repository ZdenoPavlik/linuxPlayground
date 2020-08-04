#include "test/stdafx_test.h"
#include "test/MockingTests/MockedBook.cpp"
#include "src/Library/Bookshelf.hpp"
#include "src/Library/Book/BookInterface.hpp"

using ::testing::AtLeast;
using ::testing::Return;

TEST(MockedBookTest, simpleTest)
{
  MockedBook dummyBook("Not important name");

  EXPECT_CALL(dummyBook, getBookName())
      .Times(AtLeast(1))
      .WillOnce(Return("Lord of the Rings"))
      .WillRepeatedly(Return("Harry Potter"));

  std::cout << dummyBook.getBookName() << std::endl;
  std::cout << dummyBook.getBookName() << std::endl;
  std::cout << dummyBook.getBookName() << std::endl;
}

TEST(MockedBookTest, failingTest)
{
  MockedBook dummyBook("Not important name");

  EXPECT_CALL(dummyBook, getBookName())
      .Times(AtLeast(1));
}