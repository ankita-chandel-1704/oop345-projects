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

#include "Workstation.h"
#include <iostream>

namespace sdds {
    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_incomplete;

    Workstation::Workstation(const std::string& str) : Station(str) {}
    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder() {
        bool moved{};
        if (!m_orders.empty()) {
            if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName())) {
                if (!m_pNextStation) {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                else {
                    *m_pNextStation += std::move(m_orders.front());
                }
                m_orders.pop_front();
                moved = true;
            }
        }
        return moved;
    }

    void Workstation::setNextStation(Workstation* station) { m_pNextStation = station; }

    Workstation* Workstation::getNextStation() const { return m_pNextStation; }

    void Workstation::display(std::ostream& os) const {
        os << (this)->getItemName() << " --> ";
        (m_pNextStation) ?
            (os << m_pNextStation->getItemName()) :
            (os << "End of Line");
        os << "\n";
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}