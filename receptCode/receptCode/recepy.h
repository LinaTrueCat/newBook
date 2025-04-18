#ifndef RECEPY_H
#define RECEPY_H

#include <iostream>
using namespace std;

class Recepy {
private:
    string name;
    int page;
    bool meat;
    static int amountOfRecepy;

public:
    static int getAmountOfRecepy();
    Recepy(string n, int p = 0, bool m = true);
    Recepy(const Recepy& other);
    Recepy& operator=(const Recepy& other);
    virtual ~Recepy();

    virtual void recepyStatus() const;
    virtual void meatStatus() const;
    virtual void showType() const = 0;

    string getName() const { return name; }
    int getPage() const { return page; }
};

#endif