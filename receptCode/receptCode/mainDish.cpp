#include "mainDish.h"
#include <iostream>

MainDish::MainDish(string n, int p, bool m, int cals)
    : Recepy(n, p, m), calories(cals) {
    std::cout << "Main dish created: " << n << " with " << calories << " calories" << std::endl;
}

void MainDish::showCalories() const {
    std::cout << "Calories: " << calories << std::endl;
}
