//
// Created by Clark on 4/26/2016.
//

#ifndef TESTSDL_EBASIC_HPP
#define TESTSDL_EBASIC_HPP

#include <exception>

struct e_bad_allocation : public std::exception{
    virtual const char* what() const throw()
    {
        return "Bad Memory Allocation";
    }
};

struct e_unhandled_state : public std::exception{
    virtual const char* what() const throw()
    {
        return "Unhandled State";
    }
};
#endif //TESTSDL_EBASIC_HPP
