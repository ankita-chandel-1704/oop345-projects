
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"
#include <iostream>

namespace sdds {

    Person* buildInstance(std::istream& in);
}

#endif // SDDS_UTILITIES_H