
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include "Person.h"
#include <iostream>
#include <vector>
#include <list>

namespace sdds {
    class College {
    private:
        std::vector<Person*> m_persons{};
    public:
        College() = default;
        virtual ~College();

        College(const College&) = delete;
        College& operator=(const College&) = delete;

        College& operator +=(Person* thePerson);

        void display(std::ostream& out = std::cout) const;

        template <typename T>
        void select(const T& src, std::list<const Person*>& persons) {
            for (const auto& person : m_persons) {
                if (src(person)) {
                    persons.push_back(person);
                }
            }
        }
    };
}

#endif // SDDS_COLLEGE_H