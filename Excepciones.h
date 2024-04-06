#pragma once
#include <iostream>
#include <exception>

class Exception: public _exception {
public:
    virtual const char* what() const throw () = 0;
};
