//*
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

#include "Child.h"

using namespace std;

namespace sdds {
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		c_name = name;
		c_age = age;
		c_numOfToys = count;
		c_toys = new const Toy * [count];
		for (size_t i = 0; i < count; i++)
		{
			c_toys[i] = new Toy(*toys[i]);
		}
	}

	size_t Child::size() const {
		return c_numOfToys;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child) {
		static int counter = 1;

		os << "--------------------------" << endl;
		os << "Child " << counter << ": " << child.c_name << " " << child.c_age << " years old:" << endl;
		os << "--------------------------" << endl;
		counter++;
		if (child.c_numOfToys == 0) {
			os << "This child has no toys!" << endl;
		}
		else {
			for (size_t i = 0; i < child.c_numOfToys; i++) {
				os << *child.c_toys[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

	Child::~Child()
	{
		for (size_t i = 0; i < c_numOfToys; i++)
		{
			delete c_toys[i];
		}
		if (c_numOfToys > 0)
			delete[] c_toys;
	}

	Child::Child(const Child& src)
	{
		c_name = src.c_name;
		c_age = src.c_age;
		c_numOfToys = src.c_numOfToys;
		c_toys = new const Toy * [src.c_numOfToys];
		for (size_t i = 0; i < src.c_numOfToys; i++)
		{
			c_toys[i] = new Toy(*src.c_toys[i]);
		}
	}

	Child& Child::operator=(const Child& src)
	{
		if (this != &src)
		{
			if (c_numOfToys > 0)
			{
				for (size_t i = 0; i < c_numOfToys; i++)
				{
					delete c_toys[i];
				}
				delete[] c_toys;
			}
			c_name = src.c_name;
			c_age = src.c_age;
			c_numOfToys = src.c_numOfToys;
			c_toys = new const Toy * [src.c_numOfToys];
			for (size_t i = 0; i < src.c_numOfToys; i++)
			{
				c_toys[i] = new Toy(*src.c_toys[i]);
			}
		}
		return *this;
	}

	Child::Child(Child&& src)
	{
		c_name = src.c_name;
		c_age = src.c_age;
		c_numOfToys = src.c_numOfToys;
		c_toys = src.c_toys;
		src.c_name = "";
		src.c_age = 0;
		src.c_numOfToys = 0;
		src.c_toys = nullptr;
	}

	Child& Child::operator=(Child&& src)
	{
		if (this != &src)
		{
			c_name = src.c_name;
			c_age = src.c_age;
			c_numOfToys = src.c_numOfToys;
			c_toys = src.c_toys;
			src.c_name = "";
			src.c_age = 0;
			src.c_numOfToys = 0;
			src.c_toys = nullptr;
		}
		return *this;
	}
}