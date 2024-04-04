#pragma once
#include <iostream>
#include <exception>

class Exception: public exception {
public:
    virtual const char* what() const throw () = 0;
};
