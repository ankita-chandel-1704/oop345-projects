/*
*****************************************************************************
                        Workshop 7 - Part - 2
Full Name  :  Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 18 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <vector>
#include <list>

namespace sdds {
    enum class BakedType {
        BREAD, PASTERY
    };

    struct BakedGood {
        BakedType bakedType{};
        std::string desc{};
        int shelfLife{};
        int stock{};
        double price;
    };

    class Bakery {
    private:
        std::vector<BakedGood> m_collection;
    public:
        Bakery() = default;
        Bakery(const char* filename);
        void showGoods(std::ostream& os = std::cout) const;
        void sortBakery(std::string field);
        std::vector<BakedGood> combine(Bakery& bakery);
        bool inStock(const std::string desc, const BakedType& bt) const;
        std::list<BakedGood> outOfStock(BakedType bt) const;
    };
    std::ostream& operator<<(std::ostream& out, const BakedGood& b);
    std::string strip(const std::string& str);
}

#endif