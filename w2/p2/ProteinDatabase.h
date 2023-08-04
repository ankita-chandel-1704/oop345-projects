//
//  ProteinDatabase.h
//  ws2

#ifndef ProteinDatabase_h
#define ProteinDatabase_h
#include <iostream>
using namespace std;
namespace sdds
{
    class ProteinDatabase
    {
        int size_t;
        string * str_pointer;
    public:
        ProteinDatabase();
        ProteinDatabase(ProteinDatabase &);
        ProteinDatabase(string file_name);
        int size();
        string operator[](int index);
        ProteinDatabase& operator=(ProteinDatabase&);
        ProteinDatabase(ProteinDatabase &&);
        ProteinDatabase& operator=(ProteinDatabase&&);
        ~ProteinDatabase();
    };
}
#endif /* ProteinDatabase_h */
