#include "mainDish.h"
#include <iostream>

MainDish::MainDish(string n, int p, bool m, int cals)
    : Recepy(n, p, m), calories(cals) {
    std::cout << "Main dish created: " << n << " with " << calories << " calories" << std::endl;
}

void MainDish::recepyStatus() const {    //
    std::cout << "[MainDish] ";
    Recepy::recepyStatus();
}

void MainDish::meatStatus() const {      //
    std::cout << "[MainDish] ";
    Recepy::meatStatus();
}

void MainDish::showCalories() const {
    std::cout << "Calories: " << calories << std::endl;
}

void MainDish::showType() const {
    std::cout << "This is a MainDish type" << std::endl;   //
}

void MainDish::cook() const {
    std::cout << "Cooking MainDish: " << getName() << std::endl;
}
