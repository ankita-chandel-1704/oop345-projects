#include "ProteinDatabase.h"

using namespace std;

namespace sdds
{
     

    ProteinDatabase::ProteinDatabase()
    {
        prt = nullptr;
        numOfprt = 0;
    }

    ProteinDatabase::ProteinDatabase(const char *filename)
    {
        prt= nullptr;
        numOfprt = 0;
        ifstream file(filename);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                if (line[0] == '>')
                {
                    numOfprt++;
                }
            }
            file.clear();
            file.seekg(0);
            prt = new string[numOfprt];
            int i = 0;
            getline(file, line);
            while (file.good())
            {
                if (line[0] == '>')
                {
                    getline(file, line);
                    if (file.peek() == '\n')
                    {
                        file.get();
                    }
                    while (line[0] != '>' && file.good())
                    {
                        prt[i] += line;
                        getline(file, line);
                        if (file.peek() == '\n')
                        {
                            file.get();
                        }
                    }
                    i++;
                }
            }
        }
    }

    size_t ProteinDatabase::size()
    {
        return numOfprt;
    }

    std::string ProteinDatabase::operator[](size_t index)
    {
        if (index < numOfprt && index >= 0)
        {
            return prt[index];
        }
        else
        {
            return "";
        }
    }

    ProteinDatabase::~ProteinDatabase()
    {
        if (prt != nullptr)
            delete[] prt;
       prt = nullptr;
    }

    // copy constructor
    ProteinDatabase::ProteinDatabase(const ProteinDatabase &copy)
    {
       prt = nullptr;
        numOfprt = 0;
        if (copy.numOfprt == 0)
        {
            return;
        }
        numOfprt = copy.numOfprt;
        prt = new string[numOfprt];
        for (size_t i = 0; i < numOfprt; i++)
        {
            prt[i] = copy.prt[i];
        }
    }

    // copy assignment operator
    ProteinDatabase &ProteinDatabase::operator=(const ProteinDatabase &copy)
    {
        if (this != &copy)
        {
            if (prt!= nullptr)
            {
                delete[] prt;
                prt = nullptr;
            }
            numOfprt = 0;
            if (copy.numOfprt == 0)
            {
                return *this;
            }

            numOfprt = copy.numOfprt;
            prt = new string[numOfprt];
            for (size_t i = 0; i < numOfprt; i++)
            {
                prt[i] = copy.prt[i];
            }
        }
        return *this;
    }

}
