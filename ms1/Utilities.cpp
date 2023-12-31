/*
*****************************************************************************
                        Milestone - 1
Full Name  :  Ankita Chandel
Student ID#:  161317219
Email      :  achandel1@myseneca.ca
Section    :  ZBB
Date       :  18 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "Utilities.h"
#include <iostream>

namespace sdds {
    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

    size_t Utilities::getFieldWidth() const { return m_widthField; }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string extractedToken{};
        size_t endPos = str.find(m_delimiter, next_pos);
        if (endPos != std::string::npos) {
            extractedToken = str.substr(next_pos, endPos - next_pos);
            next_pos = endPos + 1;
            more = true;
        }
        else {
            extractedToken = str.substr(next_pos);
            more = false;
        }

        extractedToken = strip(extractedToken);
        (extractedToken.length() > m_widthField) ? m_widthField = extractedToken.length() : m_widthField;
        if (extractedToken.empty()) {
            more = false;
            throw "ERROR: Token is empty!";
        }
        return extractedToken;
    }

    std::string Utilities::strip(const std::string& str) {
        std::string returnVal{};
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }

    void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

    char Utilities::getDelimiter() { return m_delimiter; }
}