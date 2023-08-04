/*
*****************************************************************************
                        Workshop 8 - Part - 1 
Full Name  :  Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 24 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <memory>

namespace sdds {
    const size_t max_entries{ 20 };

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database {
    private:
        inline static std::shared_ptr<Database> m_database{};
        size_t m_entries;
        std::string m_keys[20]{};
        std::string m_values[20]{};
        std::string m_filename;
        Database(const std::string& filename);
        std::string strip(const std::string& str);
    public:
        static std::shared_ptr<Database> getInstance(const std::string& filename);
        Err_Status GetValue(const std::string& key, std::string& value);
        Err_Status SetValue(const std::string& key, const std::string& value);
        ~Database();
    };
}

#endif
