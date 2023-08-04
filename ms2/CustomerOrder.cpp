/*
*****************************************************************************
                        Milestone - 2
Full Name  :  Ankita Chandel
Student ID#:  161317219
Email      :  achandel1@myseneca.ca
Section    :  ZBB
Date       :  24 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using std::endl;

namespace sdds {
    size_t CustomerOrder::m_widthField = 0;
    CustomerOrder::CustomerOrder(const std::string& str) {
        size_t next_pos = 0;
        bool more = true;
        Utilities util{};
        size_t startCpy{};
        m_name = util.extractToken(str, next_pos, more);
        m_product = util.extractToken(str, next_pos, more);
        startCpy = next_pos;
        while (more) {
            util.extractToken(str, next_pos, more);
            m_cntItem++;
        }
        next_pos = startCpy;
        more = true;

        m_lstItem = new Item * [m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
        }

        (m_widthField < util.getFieldWidth()) ? m_widthField = util.getFieldWidth() : m_widthField;
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& other) { throw "Attempting to copy. Operation not allowed."; }

    CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept {
        *this = std::move(co);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept {
        if (this != &co) {
            for (size_t i = 0; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
            m_name = co.m_name;
            co.m_name = "";
            m_product = co.m_product;
            co.m_product = "";
            m_cntItem = co.m_cntItem;
            co.m_cntItem = 0;
            m_lstItem = co.m_lstItem;
            co.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                flag = false;
            }
        }
        return flag;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++) {
            if (m_lstItem[i]->m_itemName == itemName) {
                if (!m_lstItem[i]->m_isFilled) {
                    flag = false;
                }
            }
        }
        return flag;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        bool filled{ false };
        for (size_t i = 0; i < m_cntItem && !filled; i++) {
            if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() > 0)) {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber++;
                m_lstItem[i]->m_isFilled = true;
                filled = true;
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
            else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0)) {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
            os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
            os << std::endl;
        }
    }
}