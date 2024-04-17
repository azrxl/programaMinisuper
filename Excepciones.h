#pragma once
#include <iostream>
#include <exception>

class Exception: public std::exception {
public:
    virtual const char* what() const throw () = 0;
};
 