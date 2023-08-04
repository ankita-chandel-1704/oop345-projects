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
#ifndef BOOK_H
#define BOOK_H
#include <iostream>

namespace sdds {
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{ 0 };
		double m_price{ 0.0 };
		std::string m_description{};

		std::string clrSpace(const std::string strin);
	public:
		Book() {};
		const std::string& title()const;
		const std::string& country()const;
		const size_t& year()const;
		double& price();
		Book(const std::string& strBook);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}
#endif
