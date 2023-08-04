/*
* Name      : Dhruv Chawla
* Student id: 158310219
* Section   : NCC
* Date      : 12-Feb-2023
*
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include "Toy.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
	Toy::Toy(const std::string& toy) {
		size_t firstIndex = 0;
		size_t lastIndex = toy.find(':');

		orderID = std::stoi(toy.substr(firstIndex, (lastIndex - firstIndex)));
		firstIndex = lastIndex + 1;
		lastIndex = toy.find(':', firstIndex);

		t_name = toy.substr(firstIndex, (lastIndex - firstIndex));

		t_name.erase(0, t_name.find_first_not_of(" \t\r\n"));
		t_name.erase(t_name.find_last_not_of(" \t\r\n") + 1);

		firstIndex = lastIndex + 1;
		lastIndex = toy.find(':', firstIndex);

		t_numOfItems = std::stoi(toy.substr(firstIndex, (lastIndex - firstIndex)));
		firstIndex = lastIndex + 1;
		lastIndex = toy.find(':', firstIndex);

		t_price = std::stod(toy.substr(firstIndex, (lastIndex - firstIndex)));
	}

	void Toy::update(int numItems) {
		t_numOfItems = numItems;
	}

	std::ostream& operator<<(std::ostream& os, const Toy& toy) {
		double subTotal = toy.t_price * toy.t_numOfItems;
		double tax = subTotal * (toy.t_hst / 100);
		double total = subTotal + tax;

		os << "Toy" << right << setw(8) << toy.orderID << ":";
		os << right << setw(18) << toy.t_name;
		os << right << setw(3) << toy.t_numOfItems << " items";
		os << setw(8) << toy.t_price << "/item";
		os << "  subtotal:";
		os << right << setw(7) << fixed << setprecision(2) << subTotal;
		os << right << " tax:" << setw(6) << tax;
		os << right << " total:" << setw(7) << total << endl;
		return os;
	}
}