#ifndef MAINDISH_H
#define MAINDISH_H

#include "recepy.h"
#include "cooking.h"

class MainDish final : public Recepy, public cooking {     
private:
    int calories;

public:
    MainDish(string n, int p, bool m, int cals);
    void showCalories() const;

    void recepyStatus() const override;
    void meatStatus() const override;
    void showType() const override;

    void cook() const override;
};

#endif 
