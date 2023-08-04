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

#ifndef _SDDS_SET_H
#define _SDDS_SET_H
#include <cmath>
#include "Collection.h"
namespace sdds
{
    template <typename T, size_t CAPACITY = 100>
    class Set : public Collection<T, CAPACITY>
    {
        using Collection<T, CAPACITY>::data;
        using Collection<T, CAPACITY>::dataSize;
        using Collection<T, CAPACITY>::m_capacity;
        using Collection<T, CAPACITY>::m_temp;
        

    public:
        Set() : Collection<T, CAPACITY>()
        {
        }
        template <typename = Pair>
        Set() : Collection<T, CAPACITY>()
        {
            m_temp = Pair("No Key", "No Value");
        }
        ~Set()
        {
        }
        template <typename = double>
        bool add(const T& item)
        {
            if (dataSize >= m_capacity)
            {
                return false;
            }
            else
            {
                for (size_t i = 0; i < dataSize; i++)
                {
                    if (fabs(data[i] - item) <= 0.1)
                    {
                        return false;
                    }
                }
                data[dataSize] = item;
                dataSize++;
                return true;
            }
        }

        bool add(const T& item)
        {
            if (dataSize >= m_capacity)
            {
                return false;
            }
            else
            {
                for (size_t i = 0; i < dataSize; i++)
                {
                    if (typeid(T) == typeid(double))
                    {
                        if (fabs(data[i] - item) <= 0.1)
                        {
                            return false;
                        }
                    }
                    else if (data[i] == item)
                    {
                        return false;
                    }
                }
                data[dataSize] = item;
                dataSize++;
                return true;
            }
        }
    };

    template <size_t CAPACITY>
    class Set<Pair, CAPACITY> : public Collection<Pair, CAPACITY>
    {
        using Collection<Pair, CAPACITY>::data;
        using Collection<Pair, CAPACITY>::dataSize;
        using Collection<Pair, CAPACITY>::m_capacity;
        using Collection<Pair, CAPACITY>::m_temp;

    public:
        Set() : Collection<Pair, CAPACITY>()
        {
            m_temp = Pair("No Key", "No Value");
        }
        ~Set()
        {
        }

        bool add(const Pair& item)
        {
            if (dataSize >= m_capacity)
            {
                return false;
            }
            else
            {
                for (size_t i = 0; i < dataSize; i++)
                {
                    if (data[i] == item)
                    {
                        return false;
                    }
                }
                data[dataSize] = item;
                dataSize++;
                return true;
            }
        }
    };

} // namespace sdds
#endif