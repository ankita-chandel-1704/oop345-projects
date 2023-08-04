/*
*****************************************************************************
                        Workshop 9 - Part - 2
Full Name  :  Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZBB
Date       : 02 April 2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// Workshop 9 - Multi-Threading, Thread Class
 // process_data.cpp
 // 2021/1/5 - Jeevan Pant

#include "process_data.h"

namespace sdds_ws9
{

    void computeAvgFactor(const int* arr, int size, int divisor, double& avg)
    {
        avg = 0;
        for (int i = 0; i < size; i++)
        {
            avg += arr[i];
        }
        avg /= divisor;
    }

    void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var)
    {
        var = 0;
        for (int i = 0; i < size; i++)
        {
            var += (arr[i] - avg) * (arr[i] - avg);
        }
        var /= divisor;
    }

    ProcessData::operator bool() const
    {
        return total_items > 0 && data != nullptr;
    }

    ProcessData::ProcessData(std::string filename, int n_threads)
    {
        std::ifstream in(filename, std::ios::in | std::ios::binary);
        if (!in)
        {
            std::cout << "Cannot read file '" << filename << "'.\n";
            exit(1);
        }
        in.read((char*)&total_items, sizeof(total_items));
        data = new int[total_items];
        in.read((char*)data, sizeof(int) * total_items);
        in.close();
        std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
        std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
            << data[total_items - 3] << ", " << data[total_items - 2] << ", "
            << data[total_items - 1] << "]\n";
        num_threads = n_threads;
        averages = new double[num_threads] {};
        variances = new double[num_threads] {};
        p_indices = new int[num_threads + 1] {};
        for (int i = 0; i < num_threads + 1; i++)
            p_indices[i] = i * (total_items / num_threads);
    }

    ProcessData::~ProcessData()
    {
        delete[] data;
        delete[] averages;
        delete[] variances;
        delete[] p_indices;
    }

    int ProcessData::operator()(std::string filename, double& avg, double& var)
    {
        std::ofstream out(filename, std::ios::out | std::ios::binary);
        if (!out)
        {
            std::cout << "Cannot write file '" << filename << "'.\n";
            exit(1);
        }
        computeAvgFactor(data, total_items, total_items, avg);
        computeVarFactor(data, total_items, total_items, avg, var);
        out.write((char*)&total_items, sizeof(total_items));
        out.write((char*)data, sizeof(int) * total_items);
        out.close();
        return 1;
    }

}