/*
* Name      : Dhruv Chawla
* Student id: 158310219
* Section   : NCC
* Date      : 12-Feb-2023
*
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#ifndef __SDDS_CONFIRMORDER_H__
#define __SDDS_CONFIRMORDER_H__

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Toy.h"

namespace sdds {
	class ConfirmOrder {
		const Toy** c_toys = nullptr;
		size_t c_numOfToys = 0;
	public:
		ConfirmOrder();
		size_t size() const;
		~ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
		ConfirmOrder(const ConfirmOrder& src);
		ConfirmOrder& operator=(const ConfirmOrder& src);
		ConfirmOrder(ConfirmOrder&& src);
		ConfirmOrder& operator=(ConfirmOrder&& src);
	};
}

#endif