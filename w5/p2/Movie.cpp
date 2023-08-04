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
#include <string>
#include "Movie.h"

namespace sdds {
	std::string Movie::clrSpace(const std::string strin) {
		std::string strcleared = strin.substr(0, strin.find_first_of(','));
		strcleared.erase(0, strcleared.find_first_not_of(' '));
		strcleared.erase(strcleared.find_last_not_of(' ') + 1);
		return strcleared;
	}

	const std::string& Movie::title()const {
		return movieTitle;
	}

	Movie::Movie(const std::string& strMovie) {
		if (!strMovie.empty())
		{
			std::string info = strMovie;
			movieTitle = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			yearRelease = stoi(info.substr(0, info.find_first_of(',')));

			info.erase(0, info.find_first_of(',') + 1);
			movieDesc = info.substr(info.find_first_not_of(' '));
		}
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.movieTitle << " | " << movie.yearRelease << " | " << movie.movieDesc << std::endl;
		return os;
	}
}