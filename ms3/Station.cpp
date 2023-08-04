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

#include "Station.h"
#include <iostream>
#include <iomanip>
#include "Utilities.h"

namespace sdds {
    Station::Station(const std::string str) {
        Utilities utils{};
        size_t next_pos{ 0 };
        bool more = true;
        itemName = utils.extractToken(str, next_pos, more);
        serialNum = std::stoi(utils.extractToken(str, next_pos, more));
        inStockQuantity = std::stoi(utils.extractToken(str, next_pos, more));
        m_widthField = std::max(m_widthField, utils.getFieldWidth());
        desc = utils.extractToken(str, next_pos, more);
        id = ++id_generator;
    }

    const std::string& Station::getItemName() const { return itemName; }

    size_t Station::getNextSerialNumber() { return serialNum++; }

    size_t Station::getQuantity() const { return inStockQuantity; }

    void Station::updateQuantity() { (inStockQuantity > 0) ? inStockQuantity -= 1 : inStockQuantity; }

    void Station::display(std::ostream& os, bool full) const {
        os << std::setfill('0') << std::right << std::setw(3) << id << " | ";
        os << std::setw(m_widthField + 1) << std::left << std::setfill(' ') << itemName << " | ";
        os << std::setw(6) << std::right << std::setfill('0') << serialNum << " | ";
        if (full) {
            os << std::setfill(' ') << std::setw(4) << std::right << inStockQuantity << " | ";
            os << std::left << desc;
        }
        os << std::endl;
    }
}