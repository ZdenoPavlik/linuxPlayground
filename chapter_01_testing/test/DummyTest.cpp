#include "test/stdafx_test.h"

TEST(DummyTest, simpleTest)
{
    EXPECT_EQ(1, 1);
    EXPECT_LE(1,2); //less or equal
    EXPECT_LE(1,2); //less or equal

    EXPECT_LT(1,3); //less than

    EXPECT_NEAR(1,2,1); //close to 

    EXPECT_NO_THROW(std::cout << "I am not throwind exception" << std::endl);
    EXPECT_ANY_THROW(throw std::runtime_error((std::string)"no reason"));

}