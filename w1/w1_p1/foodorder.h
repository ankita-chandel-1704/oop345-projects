/*
*****************************************************************************
                        Workshop 1 - Part - 1
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achadnel1@myseneca.ca
Section    : ZBB
Date       : 22 January 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef __SDDS_FOODORDER_H__
#define __SDDS_FOODORDER_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds
{

    class FoodOrder
    {
        char name[10];
        char desc[25];
        double price;
        bool daily_special;

    public:
        FoodOrder();
        void read(std::istream& in = std::cin);
        void display(std::ostream& out = std::cout) const;
    };
}

#endif