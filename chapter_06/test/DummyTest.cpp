#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "EatingTestImpl.cpp"
#include "../src/Animal.cpp"

TEST(DummyTest, simpleTest)
{
    {
        Animal<EatingTestImpl> animal("Test animal");
        animal._eater.doEat();
        animal._eater.makeNoise();
    }

    {
        Animal<> animal("Default animal");
        animal._eater.doEat();
        animal._eater.makeNoise();
    }
}