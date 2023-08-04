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

#include "Toy.h"

using namespace std;

namespace sdds
{

    Toy::Toy()
    {
        orderId = 0;
        name = "";
        numOfItems = 0;
        price = 0.0;
        Tax = 13.0;
    }

    void Toy::update(int numItems)
    {
        numOfItems = numItems;
    }

    Toy::Toy(const std::string& toy)
    {
        orderId = 0;
        name = "";
        numOfItems = 0;
        price = 0.0;
        Tax = 13.0;

        string temp = toy;
        int pos = 0;
        int pos2 = 0;
        int pos3 = 0;
        int pos4 = 0;

        pos = temp.find(":");
        orderId = stoi(temp.substr(0, pos));
        temp.erase(0, pos + 1);

        pos2 = temp.find(":");
        name = temp.substr(0, pos2);
        temp.erase(0, pos2 + 1);

        pos3 = temp.find(":");
        numOfItems = stoi(temp.substr(0, pos3));
        temp.erase(0, pos3 + 1);

        pos4 = temp.find(":");
        price = stod(temp.substr(0, pos4));
        temp.erase(0, pos4 + 1);

        int start = name.find_first_not_of(' ');
        int end = name.find_last_not_of(' ');
        name = name.substr(start, end - start + 1);
    }

    std::ostream& operator<<(std::ostream& os, const Toy& toy)
    {
        os << "Toy";
        os << setw(8) << right << toy.orderId << ":";
        os << setw(18) << right << toy.name;
        os << setw(3) << right << toy.numOfItems << " items";
        os << setw(8) << right << fixed << setprecision(2) << toy.price;
        os << "/item  subtotal:";
        os << setw(7) << right << fixed << setprecision(2) << toy.price * toy.numOfItems;
        os << " tax:";
        os << setw(6) << right << fixed << setprecision(2) << toy.price * toy.numOfItems * toy.Tax / 100;
        os << " total:";
        os << setw(7) << right << fixed << setprecision(2) << toy.price * toy.numOfItems * (1 + toy.Tax / 100);
        os << endl;
        return os;
    }
}
