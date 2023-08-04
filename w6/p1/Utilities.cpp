
#include "Utilities.h"
#include "Employee.h"


#include <iostream>

namespace sdds {

    Person* buildInstance(std::istream& in) {
        char tag{};
        in >> tag;

        if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        }


        in.ignore(1000, '\n');
        return nullptr;
    }
}