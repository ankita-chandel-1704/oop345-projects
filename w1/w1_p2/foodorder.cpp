/*
*****************************************************************************
                        Workshop 1 - Part - 2
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 22 January 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "foodorder.h"

using namespace std;

// global variables
double g_taxrate = 0;
double g_dailydiscount = 0;
namespace sdds
{

    FoodOrder::FoodOrder()
    {
        name = nullptr;
        desc = nullptr;
        price = 0;
        daily_special = false;
    }

    void FoodOrder::read(istream& is)
    {
        // If the istream is in a good state, this function will attempt to read from the istream and store the information read into current object. The data read in will be in the following format:
        // <Customer Name>,<Order Description>,<Price>,<Daily Special Status>[newline]
        // The daily special status can be of two values: 'Y' for it is a special and 'N' for it is not.

        if (is.good())
        {
            string temp;
            getline(is, temp, ',');
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;
            }
            if (temp.length() > 0)
            {
                name = new char[temp.length() + 1];
                strcpy(name, temp.c_str());
            }
            getline(is, temp, ',');
            if (desc != nullptr)
            {
                delete[] desc;
                desc = nullptr;
            }
            if (temp.length() > 0)
            {
                desc = new char[temp.length() + 1];
                strcpy(desc, temp.c_str());
            }

            is >> price;
            is.ignore();
            char dailySpecial = 'N';
            is >> dailySpecial;
            if (dailySpecial == 'Y')
            {
                daily_special = true;
            }
            else
            {
                daily_special = false;
            }
            is.ignore();
        }
    }

    void FoodOrder::display(ostream& os) const
    {
        static int counter = 0;
        if (name == nullptr)
        {
            os << setw(2) << left << ++counter << ". No Order" << endl;
        }
        else
        {
            os << setw(2) << left << ++counter << ". " << setw(10) << left << name << "|" << setw(25) << left << desc << "|" << setw(12) << fixed << setprecision(2) << left << price * (1 + g_taxrate) << "|";
            if (daily_special)
            {
                os << setw(13) << right << (price * (1 + g_taxrate)) - (g_dailydiscount);
            }
            os << endl;
        }
    }

    FoodOrder::~FoodOrder()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        if (desc != nullptr)
        {
            delete[] desc;
        }
    }

    // Copy constructor
    FoodOrder::FoodOrder(const FoodOrder& other)
    {
        name = nullptr;
        desc = nullptr;
        *this = other;
    }

    // Copy assignment operator
    FoodOrder& FoodOrder::operator=(const FoodOrder& other)
    {
        if (this != &other)
        {
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;
            }
            if (desc != nullptr)
            {
                delete[] desc;
                desc = nullptr;
            }
            if (other.name != nullptr)
            {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            if (other.desc != nullptr)
            {
                desc = new char[strlen(other.desc) + 1];
                strcpy(desc, other.desc);
            }
            price = other.price;
            daily_special = other.daily_special;
        }
        return *this;
    }

}
