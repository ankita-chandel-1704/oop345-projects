
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include "Person.h"
#include <iostream>

namespace sdds {
    class Student : public Person {
    private:
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        std::string* m_courses{ nullptr };
        std::string m_count{};
        int m_c{};
    public:
        Student() = default;
        ~Student();

        Student(std::istream& is);

        Student(const Student&) = delete;
        Student& operator=(const Student&) = delete;

        std::string status() const;

        std::string name() const;

        std::string id() const;

        std::string age() const;

        void display(std::ostream& out = std::cout) const;
    };
}

#endif // SDDS_STUDENT_H