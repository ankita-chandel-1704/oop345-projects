/*
*****************************************************************************
                        Workshop 8 - Part - 1 
Full Name  :  Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 24 March 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/



#include "Database.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

namespace sdds {
    Database::Database(const std::string& filename) {
        m_filename = filename;
        m_entries = 0;
        std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
        std::ifstream file(filename);
        std::string key{}, value{};
        while (file >> key >> value) {
            std::replace(key.begin(), key.end(), '_', ' '); 
            SetValue(key, value);
        }
        file.close();
    }

    std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
        return (m_database) ? m_database : m_database = std::shared_ptr<Database>(new Database(filename));
    }

    Err_Status Database::GetValue(const std::string& key, std::string& value) {
        Err_Status status{ Err_Status::Err_NotFound };
        int flag = 0;
        for (size_t i = 0; i < m_entries && flag == 0; i++) {
            if (m_keys[i] == key) {
                value = m_values[i];
                status = Err_Status::Err_Success;
                flag = 1;
            }
        }
        return status;
    }
    Err_Status Database::SetValue(const std::string& key, const std::string& value) {
        Err_Status status{ Err_Status::Err_OutOfMemory };
        if (m_entries < max_entries) {
            m_keys[m_entries] = key;
            m_values[m_entries] = value;
            m_entries++;
            status = Err_Status::Err_Success;
        }
        return status;
    }

    Database::~Database() {
        std::cout << "[" << this << "]" << " ~Database()" << std::endl;
        std::ofstream databaseBackup(m_filename + ".bkp.txt");
        for (size_t i = { 0 }; i < m_entries; i++) {
            databaseBackup << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
        }
    }

    std::string strip(const std::string& str) {
        std::string returnVal{};
        size_t first = str.find_first_not_of(" \t\r\n");
        size_t last = str.find_last_not_of(" \t\r\n");
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }
}