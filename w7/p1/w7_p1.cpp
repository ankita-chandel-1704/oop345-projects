/*
***************************
						Workshop 7 - Part - 1
Full Name  :  Ankita Chandel
Student ID#:161317219
Email      : achandel1@myseneca.ca
Section    :ZBB
Date       : 17 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***************************
*/
#include <iostream>
#include <iomanip>
#include "Bakery.h"
#include "Bakery.h"

using namespace sdds;

void printstars(std::ostream& os, size_t cnt) {
	for (auto i = 0u; i < cnt; ++i)
		os << "*";
	os << std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Bakery bakery(argv[1]);
	std::cout << std::left << std::setw(15) << "Type" << std::setw(23) << "Description"
		<< std::setw(8) << "Shelf" << std::setw(8) << "Stock"
		<< std::right << std::setw(8) << "Price" << std::endl;
	printstars(std::cout, 64);
	bakery.showGoods(std::cout);
	printstars(std::cout, 64);
}