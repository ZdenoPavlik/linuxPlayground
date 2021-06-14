#pragma once
#include <iostream>
#include <bitset>

/*
TASK:
    Switch bit pair in integer
    ie ->       11 00 10 01
    will become 11 00 01 10
*/

void task1_invertBitPairs()
{
    unsigned int input = 0b11001001;

    std::cout << std::bitset<8>(input) << std::endl;

    for(size_t i = 0; i < sizeof(input); i++)
    {
        bool areBitsDifferent = ((input >> (i * 2)) & 0b1) ^ ((input >> ((i * 2) + 1)) & 0b1);

        if(areBitsDifferent) // 10, 01
        {
            input = input ^ 0b1 << (i * 2);
            input = input ^ 0b1 << ((i * 2) + 1);
        }
        else // 11,00
        {
            // do nothing
        }
    }

    std::cout << std::bitset<8>(input) << std::endl << std::endl;
}

bool checkTrueBit(const uint8_t bitField, const int pos)
{
    return (bitField & (1 << pos)) != 0;
}

void toggleBit(uint8_t& bitField, const int pos)
{
    bitField ^= (uint8_t)(1 << pos);
}

void task1_invertBitPairs_MD()
{
    uint8_t b2 = 0b11000110;
    std::cout << "MD begin: " << std::bitset<8>(b2) << std::endl << std::endl;

    for(int i = 0; i < (int)(sizeof(b2) * 8);)
    {
        if(checkTrueBit(b2, i) != checkTrueBit(b2, i + 1))
        {
            toggleBit(b2, i);
            toggleBit(b2, i + 1);
        }
        i += 2;
    }

    std::cout << "MD end: " << std::bitset<8>(b2) << std::endl << std::endl;
}