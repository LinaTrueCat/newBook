#ifndef MAINDISH_H
#define MAINDISH_H

#include "recepy.h"

class MainDish : public Recepy {
private:
    int calories;

public:
    MainDish(string n, int p, bool m, int cals);
    void showCalories() const;
};

#endif // MAINDISH_H
