/*
*****************************************************************************
                        Workshop 8 - Part - 2
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

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>
#include <algorithm>

namespace sdds {
    const size_t max_entries{ 20 };

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database {
    private:
        inline static std::shared_ptr<Database> m_database{};
        size_t m_entries;
        std::string m_keys[max_entries]{};
        T m_values[max_entries]{};
        std::string m_filename;

        Database(const std::string& filename) {
            m_filename = filename;
            m_entries = 0;
            std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
            std::ifstream file(filename);
            std::string key{};
            T value{};
            while ((file >> key >> value) && m_entries < max_entries) {
                std::replace(key.begin(), key.end(), '_', ' '); 
                encryptDecrypt(value);
                SetValue(key, value);
            }
            file.close();
        }

        void encryptDecrypt(T& value) {};
    public:

        static std::shared_ptr<Database> getInstance(const std::string& filename) {
            return (m_database) ? m_database : m_database = std::shared_ptr<Database<T>>(new Database<T>(filename));
        }
        Err_Status GetValue(const std::string& key, T& value) {
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

        Err_Status SetValue(const std::string& key, const T& value) {
            Err_Status status{ Err_Status::Err_OutOfMemory };
            if (m_entries < max_entries) {
                m_keys[m_entries] = key;
                m_values[m_entries] = value;
                m_entries++;
                status = Err_Status::Err_Success;
            }
            return status;
        }

        ~Database() {
            std::cout << "[" << this << "]" << " ~Database()" << std::endl;
            std::ofstream databaseBackup(m_filename + ".bkp.txt");
            for (size_t i = { 0 }; i < m_entries; i++) {
                encryptDecrypt(m_values[i]);
                databaseBackup << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
            }
        }
    };

 
    template<>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[]{ "secret encryption key" };
        for (char& c : value) {
            for (const char& k : secret) {
                c = c ^ k;
            }
        }
    }

    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };
        char* bytes = reinterpret_cast<char*>(&value);
        size_t numBytes = sizeof(value);
        for (size_t i = 0; i < numBytes; i++) {
            for (const char& k : secret) {
                bytes[i] = bytes[i] ^ k;
            }
        }
    }
}

#endif 
