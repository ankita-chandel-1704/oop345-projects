
#include "Employee.h"
#include <iostream>
#include <iomanip>

namespace sdds {

    Employee::Employee(std::istream& is) {
        std::string data{};
        is.ignore(1);

        std::getline(is, data);
        size_t startIndex{ 0 };
        size_t endIndex = data.find(',');


        m_name = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);


        m_age = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
        m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);


        for (auto& ch : m_age) {
            if (std::isdigit(ch) == 0) {
                throw m_name + "++Invalid record!";
            }
        }


        m_id = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
        m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);


        if (tolower(m_id[0]) != 'e') {
            throw m_name + "++Invalid record!";
        }


        m_dept = data.substr(startIndex, (endIndex - startIndex));
        m_dept.erase(0, m_dept.find_first_not_of(" \t\r\n"));
        m_dept.erase(m_dept.find_last_not_of(" \t\r\n") + 1);
    }


    std::string Employee::status() const { return "Employee"; }


    std::string Employee::name() const { return m_name; }


    std::string Employee::id() const { return m_id; }


    std::string Employee::age() const { return m_age; }

    void Employee::display(std::ostream& out) const {
        out << std::left;
        out << "| " << std::setw(10) << "Employee" << "| ";
        out << std::setw(10) << m_id << "| ";
        out << std::setw(20) << m_name << " | ";
        out << std::setw(3) << m_age << " |";
    }
}