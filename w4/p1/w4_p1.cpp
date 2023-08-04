// Workshop 4 - Containers
// 2020/01/28 - Cornel
// 2021/01/19 - Chris
// 2021/10/01 - Cornel
/*
*****************************************************************************
						Workshop 4 - Part - 1
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 12 feb 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
s
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Toy.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	sdds::Toy** ppToys = nullptr;
	size_t cnt = 0;

	if (argc > 1) {
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strToy;
		do
		{
			std::getline(file, strToy);

			if (file)
			{
				if (strToy[0] != '#')
					++cnt;
			}
		} while (file);

		ppToys = new sdds::Toy * [cnt];
		cnt = 0;

		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strToy);

			if (file)
			{
				if (strToy[0] != '#')
				{
					ppToys[cnt] = new sdds::Toy(strToy);
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nToys\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppToys[i];
	}
	std::cout << "--------------------------\n\n";

	if (cnt > 2)
	{
		ppToys[0]->update(6);
		ppToys[2]->update(4);
	}

	std::cout << "\nUpdated Toys\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppToys[i];
	}
	std::cout << "--------------------------\n\n";

	for (auto i = 0u; i < cnt; ++i)
		delete ppToys[i];
	delete[] ppToys;

	return 0;
}