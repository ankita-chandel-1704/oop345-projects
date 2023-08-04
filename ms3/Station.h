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

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
    class Station {
    private:
        size_t id{};
        std::string itemName{};
        std::string desc{};
        size_t serialNum{};
        size_t inStockQuantity{ 0 };
        inline static size_t m_widthField{ 0 };
        inline static size_t id_generator{ 0 };
    public:
        Station() = default;
        Station(const std::string str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif