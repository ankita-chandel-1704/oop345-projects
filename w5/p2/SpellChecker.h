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
#pragma once
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>

#define constexpr unsigned M_WORDS{ 6 };

namespace sdds {
	class SpellChecker {
		std::string badWords[6]{};
		std::string goodWords[6]{};
		unsigned m_counter[6]{ 0 };
	public:
		SpellChecker() {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out);
	};
}
#endif
