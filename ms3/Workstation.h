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

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include "CustomerOrder.h"
#include "Station.h"
#include <iostream>
#include <deque>

namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
    private:
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{ nullptr };
    public:
        Workstation() = default;
        Workstation(const std::string& str);
        Workstation(const Workstation&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(Workstation&&) = delete;
        void fill(std::ostream& os = std::cout);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os = std::cout) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif