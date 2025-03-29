#ifndef NPS_H
#define NPS_H

#include <iostream>
#include <string>
#include "recepy.h"
#include "recepyBook.h"

using namespace std;

class Nps {
private:
    string name;
    bool vegStatus;
    int wish;

public:
    Nps(string n, int w, bool v);
    Nps(string n, bool v);
    ~Nps();

    void showVegStatus() const;
    void showWish() const;
    void chooseRecepy(const Recepy& recepy) const;
};

#endif // NPS_H

