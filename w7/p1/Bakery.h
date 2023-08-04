

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <vector>

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
    };

    std::ostream& operator<<(std::ostream& out, const BakedGood& b);

    std::string strip(const std::string& str);
}

#endif 