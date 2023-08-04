/*
******************************************************
                              reflect.txt
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
******************************************************
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

namespace sdds {
	unsigned  counter = 0u;

	SpellChecker::SpellChecker(const char* filename) {
		if (filename)
		{
			std::ifstream fin(filename);
			if (!fin)
			{
				throw "Bad file name!";
			}

			unsigned noOfWords = 0u;
			while (fin >> badWords[noOfWords] >> goodWords[noOfWords])
			{
				noOfWords++;
			}
		}
	}

	void SpellChecker::operator()(std::string& text) {
		if (!text.empty())
		{
			for (unsigned i = 0u; i < 6; i++)
			{
				while (text.find(badWords[i]) < text.size())
				{
					text.replace(text.find(badWords[i]), badWords[i].size(), goodWords[i]);
					m_counter[i]++;
				}
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) {
		out << "Spellchecker Statistics" << std::endl;
		for (unsigned i = 0; i < 6; i++) {
			out << std::setw(15) << std::right << badWords[i] << ": " << m_counter[i] << " replacements" << std::endl;
		}
	}
}