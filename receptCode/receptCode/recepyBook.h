#ifndef RECEPYBOOK_H
#define RECEPYBOOK_H

#include <iostream>
#include <string>
#include "cooking.h"

using namespace std;

class RecepyBook : public cooking {
private:
    string name;
    int numbPages = 20;
    string content;

public:
    RecepyBook(string n, int numPages, string text);
    RecepyBook(const RecepyBook& other);
    RecepyBook(RecepyBook&& other) noexcept;
    RecepyBook& operator=(const RecepyBook& other);
    RecepyBook& operator=(RecepyBook&& other) noexcept;
    ~RecepyBook();
    void showSize() const;

    void cook() const override;
};

#endif 
