// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
//name-Ankita Chandel
//Student  id= 161317219

#include <fstream>
#include <iomanip>
#include <iostream>

#include "Book.h"

using namespace sdds;

enum AppErrors {
    CannotOpenFile = 1,    // An input file cannot be opened
    BadArgumentCount = 2,  // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // get the books
    sdds::Book library[7];
    size_t cnt = 0;
    if (argc == 2) {
        // TODO: load the collection of books from the file "argv[1]".
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
            exit(AppErrors::CannotOpenFile);
        }

        std::string book{};
        do {
            std::getline(file, book);
            if (file) {
                if (book[0] != '#') {
                    library[cnt++] = sdds::Book(book);
                }
            }
        } while (file);
        file.close();
    } else {
        std::cerr << "ERROR: Incorrect number of arguments.\n";
        exit(AppErrors::BadArgumentCount);
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // TODO: create a lambda expression that fixes the price of a book accoding to the rules
    auto changePrice = [&](Book& book) {
        if (book.country() == "US") {
            book.price() *= usdToCadRate;
        }
        if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
            book.price() *= gbpToCadRate;
        }
    };

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    // TODO: iterate over the library and print each book to the screen
    for (auto i = 0u; i < cnt; ++i) {
        std::cout << library[i];
    }
    std::cout << "-----------------------------------------\n\n";

    // TODO: iterate over the library and update the price of each book
    //         using the lambda defined above.
    for (auto i = 0u; i < cnt; ++i) {
        changePrice(library[i]);
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    // TODO: iterate over the library and print each book to the screen
    for (auto i = 0u; i < cnt; ++i) {
        std::cout << library[i];
    }
    std::cout << "-----------------------------------------\n";

    return 0;
}