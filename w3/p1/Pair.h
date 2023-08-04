/*
*****************************************************************************
Workshop 3 - Part - 2
Full Name : Ankkita Chandel
Student ID# : 161317219
Email : achandel1@myseneca.ca
Section : ZBB
Date : 05 February 2023
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/
#ifndef __SDDS_PAIR_H__
#define __SDDS_PAIR_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string& getKey() { return m_key; }
        const std::string& getValue() { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
        friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
        Pair();
        Pair& operator=(const Pair& pair);
    };
}

#endif