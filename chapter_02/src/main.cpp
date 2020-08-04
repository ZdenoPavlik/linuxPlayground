/*
    std::atomic vs lock_guard
*/
#include "test1.cpp"
#include "test2.cpp"

#include <iostream>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#define UNUSED(expr) (void)(expr) //clang-tidy

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    srand(static_cast<unsigned int>(time(NULL)));

    test1::test1_withLockGuard();
    test1::test1_withoutLockGuard();

    test2::test2_withAtomic();
    test2::test2_withoutAtomic();

    return 0;
}
