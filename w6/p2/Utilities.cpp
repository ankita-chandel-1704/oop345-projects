/*
***************************
                        Workshop 6 - Part - 1
Full Name  :  Ankita Chandel
Student ID#:161317219
Email      : achandel1@myseneca.ca
Section    :ZBB
Date       : 12 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***************************
*/

#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include <iostream>

namespace sdds {

    Person* buildInstance(std::istream& in) {
        char tag{};
        in >> tag;

        if (tag == 's' || tag == 'S') {
            return new Student(in);
        }

        if (tag == 'p' || tag == 'P') {
            return new Professor(in);
        }

        if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        }


        in.ignore(1000, '\n');
        return nullptr;
    }
}