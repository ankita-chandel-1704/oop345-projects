/*
*****************************************************************************
                        Workshop 1 - Part - 1
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : Zbb
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

double g_taxrate = 0;
double g_dailydiscount = 0;
namespace sdds
{
    FoodOrder::FoodOrder()
    {
        name[0] = '\0';
        desc[0] = '\0';
        price = 0;
        daily_special = false;
    }

    void FoodOrder::read(istream& is)
    {

        if (is.good())
        {
            string temp;
            getline(is, temp, ',');
            strcpy(name, temp.c_str());
            getline(is, temp, ',');
            strcpy(desc, temp.c_str());
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
        if (name[0] == '\0')
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
}

