/*
*****************************************************************************
						Workshop 4 - Part - 1
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 12 feb 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef __SDDS_TOY_H__
#define __SDDS_TOY_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>

namespace sdds
{
    class Toy
    {
        int orderId;
        std::string name;
        int numOfItems;
        double price;
        double Tax;

    public:
        Toy();
        void update(int numItems);
        Toy(const std::string& toy);
        friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
    };
}

#endif