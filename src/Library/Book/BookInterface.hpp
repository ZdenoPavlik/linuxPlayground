#pragma once
#include "stdafx.h"

using std::string;

class BookInterface
{
public:
    BookInterface(string bookName) : _bookName(bookName){};
    virtual ~BookInterface(){};
    virtual string getBookName() = 0;

protected:
    string _bookName;
};