/*
* Name      : Dhruv Chawla
* Student id: 158310219
* Section   : NCC
* Date      : 12-Feb-2023
*
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#ifndef __SDDS_CHILD_H__
#define __SDDS_CHILD_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Toy.h"

namespace sdds {
	class Child {
		std::string c_name;
		int c_age;
		const Toy** c_toys = nullptr;
		size_t c_numOfToys = 0;
	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
		~Child();
		Child(const Child& src);
		Child& operator=(const Child& src);
		Child(Child&& src);
		Child& operator=(Child&& src);
	};
}

#endif