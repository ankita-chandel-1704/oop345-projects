//
//  ProteinDatabase.cpp
//  ws2

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds
{
    ProteinDatabase::ProteinDatabase()
    {
        size_t=0;
        str_pointer=nullptr;
    }
    ProteinDatabase::ProteinDatabase(ProteinDatabase &k)
    {
        size_t=k.size_t;
        str_pointer=new string [size_t];
        for(int i=0;i<size_t;i++)
        {
            str_pointer[i]=k.str_pointer[i];
        }
        
    }
    ProteinDatabase::ProteinDatabase(string file_name)
    {
        size_t=0;
        std::ifstream myfile(file_name);
        std::string count;
        while (!myfile.eof())
        {
            getline(myfile,count,'\n');
            if (count[0] == '>')
            {
                size_t++;
            }
        }
        myfile.clear();
        myfile.seekg(0, ios::beg);
        str_pointer=new string [size_t];
        for (int i=0;i<size_t;i++)
        {
            getline(myfile,count,'\n');
            getline(myfile,count,'\n');
            while (!myfile.eof() && (count.length()==60))
            {
                str_pointer[i]=str_pointer[i]+count;
                getline(myfile,count,'\n');
            }
            str_pointer[i]=str_pointer[i]+count;
        }
        myfile.close();
    }
    int ProteinDatabase::size()
    {
        return size_t;
    }
    string ProteinDatabase::operator[](int index)
    {
        int size_check= size();
        if (str_pointer == nullptr)
        {
            return"";
        }
        else
        {
            if (index < size_check)
            return str_pointer[index];
            else
            return"";
        }
    }
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase& k)
    {
        if(str_pointer!= k.str_pointer)
        {
            size_t=k.size_t;
            if (str_pointer!=nullptr)
            {
                delete[] str_pointer;
                str_pointer=nullptr;
            }
            str_pointer=new string [size_t];
            for(int i=0;i<size_t;i++)
            {
                str_pointer[i]=k.str_pointer[i];
            }
            
        }
        return *this;
    }
    ProteinDatabase::~ProteinDatabase()
    {
        delete [] str_pointer;
        str_pointer=nullptr;
    }
    ProteinDatabase::ProteinDatabase(ProteinDatabase && k)
    {
        
        size_t=k.size_t;
        str_pointer = k.str_pointer;
        k.str_pointer=nullptr;
        k.size_t=0;
    }
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase &&k)
    {
        if(str_pointer!= k.str_pointer)
        {
            if (str_pointer!=nullptr)
            {
                delete[]str_pointer;
                str_pointer=nullptr;
            }
            size_t=k.size_t;
            str_pointer = k.str_pointer;
            k.str_pointer=nullptr;
            k.size_t=0;
           
        }
        return *this;
    }
}
