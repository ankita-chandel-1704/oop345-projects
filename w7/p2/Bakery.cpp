/*
*****************************************************************************
                        Workshop 7 - Part - 2
Full Name  :  Ankita Chandel
Student ID#:  161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 18 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "Bakery.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
using std::endl;

namespace sdds {
    Bakery::Bakery(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            throw "Error: Could not open file";
        }
        std::string data{};
        while (std::getline(file, data)) {
            BakedGood bakedGood{};
            std::string bakedType = data.substr(0, 8);
            transform(bakedType.begin(), bakedType.end(), bakedType.begin(), ::toupper);
            bakedGood.bakedType = strip(bakedType) == "BREAD" ? BakedType::BREAD : BakedType::PASTERY;
            bakedGood.desc = strip(data.substr(8, 20));
            bakedGood.shelfLife = std::stoi(strip(data.substr(28, 14)));
            bakedGood.stock = std::stoi(strip(data.substr(42, 8)));
            bakedGood.price = std::stod(strip(data.substr(50, 6)));
            m_collection.push_back(bakedGood);
        }
        file.close();
    }

    void Bakery::showGoods(std::ostream& os) const {
        std::for_each(m_collection.begin(), m_collection.end(), [&os](auto bakedGood) { os << bakedGood << endl; });
        auto total_stock = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](int acc, const BakedGood& good) { return acc + good.stock; });
        auto total_price = std::accumulate(m_collection.begin(), m_collection.end(), 0.00, [](double acc, const BakedGood& good) { return acc + good.price; });
        os << "Total Stock: " << total_stock << endl;
        os << "Total Price: " << std::fixed << std::setprecision(2) << total_price << endl;
    }

    void Bakery::sortBakery(std::string field) {
        std::transform(field.begin(), field.end(), field.begin(), ::toupper);
        std::sort(m_collection.begin(), m_collection.end(), [field](const BakedGood& bakedGood1, const BakedGood& bakedGood2) {
            bool returnVal{};
        (field == "DESCRIPTION") ? returnVal = bakedGood1.desc < bakedGood2.desc : returnVal;
        (field == "SHELF") ? returnVal = bakedGood1.shelfLife < bakedGood2.shelfLife : returnVal;
        (field == "STOCK") ? returnVal = bakedGood1.stock < bakedGood2.stock : returnVal;
        (field == "PRICE") ? returnVal = bakedGood1.price < bakedGood2.price : returnVal;
        return returnVal;
            });
    }

    std::vector<BakedGood> Bakery::combine(Bakery& bakery) {
        std::vector<BakedGood> combined(m_collection.size() + bakery.m_collection.size());
        sortBakery("Price");
        bakery.sortBakery("Price");

        std::merge(m_collection.begin(), m_collection.end(), bakery.m_collection.begin(), bakery.m_collection.end(), combined.begin(), [](const BakedGood& bg1, const BakedGood& bg2) {
            return bg1.price < bg2.price;
            });
        return combined;
    }

    bool Bakery::inStock(const std::string desc, const BakedType& bt) const {
        return std::any_of(m_collection.begin(), m_collection.end(), [desc, bt](const BakedGood& bg) {
            return bg.desc == desc && bg.bakedType == bt;
            });
    }

    std::list<BakedGood> Bakery::outOfStock(BakedType bt) const {
        std::list<BakedGood> outOfStockItems;
        std::copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(outOfStockItems), [bt](const BakedGood& bg) {
            return bg.bakedType == bt && bg.stock == 0;
            });
        outOfStockItems.sort([](const BakedGood& bg1, const BakedGood& bg2) {
            return bg1.price < bg2.price;
            });
        return outOfStockItems;
    }

    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        out << "* " << std::left << std::setw(10) << (b.bakedType == BakedType::BREAD ? "Bread" : "Pastry");
        out << " * " << std::left << std::setw(20) << b.desc;
        out << " * " << std::left << std::setw(5) << b.shelfLife;
        out << " * " << std::left << std::setw(5) << b.stock;
        out << " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.price;
        out << " * ";
        return out;
    }

    std::string strip(const std::string& str) {
        std::string returnVal{};
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }
}