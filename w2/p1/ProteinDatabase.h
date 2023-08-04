#ifndef __SDDS_PROTEINDATABASE_H__
#define __SDDS_PROTEINDATABASE_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <string>

namespace sdds
{
    class ProteinDatabase
    {
        //  that manages a dynamically allocated array of elements of type std::string. Your class keeps track of the number of strings currently stored and defines the following member functions:
        std::string *prt;
        size_t numOfprt;

    public:
        ProteinDatabase();
        ProteinDatabase(const char *filename);
        // copy constructor
        ProteinDatabase(const ProteinDatabase &copy);
        // copy assignment operator
        ProteinDatabase &operator=(const ProteinDatabase &copy);
        size_t size();
        std::string operator[](size_t);
        ~ProteinDatabase();
    };
}

#endif