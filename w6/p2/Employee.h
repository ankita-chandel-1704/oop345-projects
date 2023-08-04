

#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include "Person.h"
#include <iostream>

namespace sdds {
    class Employee : public Person {
    private:
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
    public:

        std::string m_dept{};
        Employee() = default;

        Employee(std::istream& is);

        std::string status() const;

        std::string name() const;

        std::string id() const;

        std::string age() const;

        void display(std::ostream& out = std::cout) const;

    };
};

#endif // SDDS_EMPLOYEE_H