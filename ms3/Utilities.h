/*
*****************************************************************************
                        Milestone - 3
Full Name  :  Ankita Chandel
Student ID#:  161317219
Email      :  achandel1@myseneca.ca
Section    :  ZBB
Date       :  08 April 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds {
    class Utilities {
    private:
        size_t m_widthField{ 1 };
        inline static char m_delimiter{};
    public:
        Utilities() = default;
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        std::string strip(const std::string& str);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}

#endif 