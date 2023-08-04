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

#include "ConfirmOrder.h"

using namespace std;

namespace sdds {
    size_t ConfirmOrder::size() const
    {
        return c_numOfToys;
    }

    ConfirmOrder::~ConfirmOrder()
    {
        if (c_numOfToys > 0)
            delete[] c_toys;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
    {
        bool found = false;
        for (size_t i = 0; i < c_numOfToys; i++)
        {
            if (c_toys[i]->getOrderId() == toy.getOrderId())
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            const Toy** temp = new const Toy * [c_numOfToys + 1];
            for (size_t i = 0; i < c_numOfToys; i++)
            {
                temp[i] = c_toys[i];
            }
            temp[c_numOfToys] = &toy;
            if (c_toys != nullptr)
                delete[] c_toys;
            c_toys = temp;
            c_numOfToys++;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
    {
        bool found = false;
        size_t index = 0;
        for (size_t i = 0; i < c_numOfToys; i++)
        {
            if (c_toys[i]->getOrderId() == toy.getOrderId())
            {
                found = true;
                index = i;
                break;
            }
        }
        if (found)
        {
            if (c_numOfToys == 1)
            {
                delete[] c_toys;
                c_toys = nullptr;
                c_numOfToys = 0;
                return *this;
            }

            const Toy** temp = new const Toy * [c_numOfToys - 1];
            for (size_t i = 0; i < index; i++)
            {
                temp[i] = c_toys[i];
            }
            for (size_t i = index; i < c_numOfToys - 1; i++)
            {
                temp[i] = c_toys[i + 1];
            }
            delete[] c_toys;
            c_toys = temp;
            c_numOfToys--;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order)
    {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;
        if (order.c_numOfToys == 0)
        {
            os << "There are no confirmations to send!" << endl;
        }
        else
        {
            for (size_t i = 0; i < order.c_numOfToys; i++)
            {
                os << *order.c_toys[i];
            }
        }
        os << "--------------------------" << endl;
        return os;
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& src)
    {
        c_numOfToys = src.c_numOfToys;
        c_toys = new const Toy * [c_numOfToys];
        for (size_t i = 0; i < c_numOfToys; i++)
        {
            c_toys[i] = src.c_toys[i];
        }
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src)
    {
        if (this != &src)
        {
            for (size_t i = 0; i < c_numOfToys; i++)
            {
                if (c_toys[i] != nullptr)
                    delete c_toys[i];
            }
            if (c_numOfToys > 0)
                delete[] c_toys;

            c_numOfToys = src.c_numOfToys;
            c_toys = new const Toy * [c_numOfToys];
            for (size_t i = 0; i < c_numOfToys; i++)
            {
                c_toys[i] = src.c_toys[i];
            }
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& src)
    {
        c_numOfToys = src.c_numOfToys;
        c_toys = src.c_toys;
        src.c_numOfToys = 0;
        src.c_toys = nullptr;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src)
    {
        if (this != &src)
        {
            if (c_numOfToys > 0)
                delete[] c_toys;

            c_numOfToys = src.c_numOfToys;
            c_toys = src.c_toys;
            src.c_numOfToys = 0;
            src.c_toys = nullptr;
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder()
    {
        c_numOfToys = 0;
        c_toys = nullptr;
    }
}