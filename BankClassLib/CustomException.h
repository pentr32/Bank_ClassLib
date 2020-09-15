#pragma once

#include <exception>

struct OverdraftException : public std::exception
{
    const char* what() const throw ()
    {
        return "Overdraft!";
    }
};