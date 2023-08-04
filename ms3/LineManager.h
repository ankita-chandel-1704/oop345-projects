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

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include "Workstation.h"
#include <iostream>
#include <vector>

namespace sdds {
    class LineManager {
    private:
        std::vector<Workstation*> m_activeLine{};
        size_t m_cntCustomer{ 0 };
        Workstation* m_firstStation{ nullptr };
    public:
        
        LineManager() = default;
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os = std::cout);
        void display(std::ostream& os = std::cout) const;
    };
}

#endif 