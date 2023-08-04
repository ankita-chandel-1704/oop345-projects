/*
*****************************************************************************
                        Workshop 3 - Part - 2
Full Name  : Ankkita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 05 February 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "Pair.h"

using namespace std;

namespace sdds
{
    Pair::Pair()
    {
    }
    std::ostream& operator<<(std::ostream& os, const Pair& pair)
    {
        os << setw(20) << right << pair.m_key << ": " << pair.m_value;
        return os;
    }
  
    bool Pair::operator==(const Pair& other)
    {
        return m_key == other.m_key;
    }
 
    float Pair::operator-(const Pair& other)
    {
        return 0;
    }
}