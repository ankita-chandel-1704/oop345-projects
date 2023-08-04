/*
* Name      : Dhruv Chawla
* Student id: 158310219
* Section   : NCC
* Date      : 12-Feb-2023
*
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <string>

namespace sdds {
	class Toy {
	private:
		int orderID {};
		std::string t_name{};
		int t_numOfItems{};
		double t_price{};
		double t_hst{ 13 };
	public:
		Toy();
		Toy(const std::string& toy);
		void update(int numItems);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
		int getOrderId() const { return orderID; }
	};
}

#endif