
#include "Professor.h"
#include <iostream>
using std::cout;
using std::endl;

namespace sdds {

    Professor::Professor(std::istream& in) : Employee(in) {
        m_department = Employee::m_dept;
    }


    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department;
        out << "| Professor";
    }


    std::string Professor::status() const { return "Professor"; }


    std::string Professor::department() const { return m_department; }
}