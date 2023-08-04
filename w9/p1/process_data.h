/*
*****************************************************************************
Workshop 9 - Part - 1
Full Name : Ankkita Chandel
Student ID# : 161317219
Email : achandel1@myseneca.ca
Section : ZBB
Date : 02 April 2023
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include<iostream>
#include<string>
#include<fstream>
#include<functional>

namespace sdds_ws9 {
	void computeAvgFactor(const int*, int, int, double&);
	void computeVarFactor(const int*, int, int, double, double&);
	class ProcessData {
		int total_items{};
		int* data{};
	public:
		ProcessData(std::string);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(std::string, double&, double&);
	};
	
	
}



#endif 