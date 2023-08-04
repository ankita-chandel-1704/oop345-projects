/*
***************************
                        Workshop 6 - Part - 1
Full Name  :  Ankita Chandel
Student ID#:161317219
Email      : achandel1@myseneca.ca
Section    :ZBB
Date       : 12 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***************************
*/

#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

#include <iostream>
#include <iomanip>

namespace sdds {

    Student::Student(std::istream& is) {
        std::string data{};
        is.ignore(1);

        std::getline(is, data);
        size_t startIndex{ 0 };
        size_t endIndex = data.find(',');


        m_name = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);


        m_age = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
        m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);


        for (auto& ch : m_age) {
            if (std::isdigit(ch) == 0) {
                throw m_name + "++Invalid record!";
            }
        }


        m_id = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
        m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);


        if (tolower(m_id[0]) != 's') {
            throw m_name + "++Invalid record!";
        }


        m_count = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_count.erase(0, m_count.find_first_not_of(" \t\r\n"));
        m_count.erase(m_count.find_last_not_of(" \t\r\n") + 1);


        for (auto& ch : m_count) {
            if (std::isdigit(ch) == 0) {
                throw m_name + "++Invalid record!";
            }
        }


        m_c = std::stoi(m_count);
        m_courses = new std::string[m_c];

        for (int i = 0; i < m_c; i++) {
            m_courses[i] = data.substr(startIndex, (endIndex - startIndex));
            startIndex = endIndex + 1;
            endIndex = data.find(',', startIndex);
            m_courses[i].erase(0, m_courses[i].find_first_not_of(" \t\r\n"));
            m_courses[i].erase(m_courses[i].find_last_not_of(" \t\r\n") + 1);
        }
    }


    std::string Student::id() const { return m_id; }


    std::string Student::age() const { return m_age; }


    std::string Student::status() const { return "Student"; }


    std::string Student::name() const { return m_name; }


    void Student::display(std::ostream& out) const {
        out << "| " << std::setw(10) << std::left << "Student"
            << "| " << std::setw(10) << std::left << m_id
            << "| " << std::setw(20) << std::left << m_name
            << " | " << std::setw(3) << std::left << m_age
            << " |" << m_courses[0];
        for (int i = 1; i < m_c; i++) {
            out << ", " << m_courses[i];
        }
    }

    Student::~Student() {
        delete[] m_courses;
    }
}