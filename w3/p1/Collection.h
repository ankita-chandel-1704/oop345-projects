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
#ifndef __SDDS_COLLECTION_H__
#define __SDDS_COLLECTION_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Collection
    {
        T data[CAPACITY];
        size_t dataSize = 0;
        size_t m_capacity = CAPACITY;

        static T m_temp;

    public:
        Collection()
        {
            m_temp = {};
        };
        template <typename = Pair>
        Collection()
        {
            m_temp = Pair("No Key", "No Value");
        }
        int size()
        {
            return dataSize;
        }
        void display(std::ostream& ostr = std::cout)
        {
            ostr << "----------------------" << std::endl;
            ostr << "| Collection Content |" << std::endl;
            ostr << "----------------------" << std::endl;
            for (size_t i = 0; i < dataSize; i++)
            {
                ostr << data[i] << std::endl;
            }
            ostr << "----------------------" << std::endl;
        }
        bool add(const T& item)
        {
            if (dataSize >= m_capacity)
            {

                return false;
            }
            data[dataSize] = item;
            dataSize++;
            return true;
        }
        T operator[](size_t index)
        {
            if (index >= 0 && index < dataSize)
            {
                return data[index];
            }
            else
            {
                return m_temp;
            }
        }
    };

    template <typename T, size_t CAPACITY>
    T Collection<T, CAPACITY>::m_temp;
}
#endif