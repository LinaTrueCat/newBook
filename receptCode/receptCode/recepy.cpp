#include "recepy.h"

int Recepy::amountOfRecepy = 0;

int Recepy::getAmountOfRecepy() {
    return amountOfRecepy;
}

Recepy::Recepy(string n, int p, bool m) : name(n), page(p), meat(m) {
    amountOfRecepy++;
}

Recepy::Recepy(const Recepy& other) : name(other.name), page(other.page), meat(false) {
    cout << "\033[32mCopying Recepy: \033[0m" << name << " on page " << page << " (meat removed)" << endl;
}

Recepy& Recepy::operator=(const Recepy& other) {
    if (this != &other) {
        name = other.name;
        page = other.page;
        meat = false;
    }
    return *this;
}

void Recepy::recepyStatus() const {
    cout << name << " on page " << page << endl;
}

void Recepy::meatStatus() const {
    if (meat) cout << "Has meat" << endl;
    else cout << "Has no meat" << endl;
    cout << endl;
}

Recepy::~Recepy() {
    cout << "Page with " << name << " is closed" << endl;    //
}
