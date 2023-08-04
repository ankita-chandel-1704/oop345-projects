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
#ifndef MOVIE_H
#define MOVIE_H
#include <cstring>
#include <iostream>
namespace sdds {
	class Movie {
		std::string movieTitle{};
		size_t yearRelease{ 0 };
		std::string movieDesc{};
		std::string clrSpace(const std::string strin);
	public:
		Movie() {};
		const std::string& title()const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(movieTitle);
			spellChecker(movieDesc);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};

}
#endif
