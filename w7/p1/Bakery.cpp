
#include "Bakery.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <functional>
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

            // Assigning data
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
        for_each(m_collection.begin(), m_collection.end(), [&os](auto bakedGood) { os << bakedGood; });
    }

    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        out << "* " << std::left << std::setw(10) << (b.bakedType == BakedType::BREAD ? "Bread" : "Pastry");
        out << " * " << std::left << std::setw(20) << b.desc;
        out << " * " << std::left << std::setw(5) << b.shelfLife;
        out << " * " << std::left << std::setw(5) << b.stock;
        out << " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.price;
        out << " * " << endl;
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