#include "nps.h"

Nps::Nps(string n, int w, bool v) {
    this->name = n;
    this->wish = w;
    this->vegStatus = v;
    cout << name << " wishes ";
    showWish();
    showVegStatus();
    cout << endl;
}
Nps::Nps(string n, bool v) {
    this->name = n;
    this->wish = 0;
    this->vegStatus = v;
}

void Nps::showWish() const {
    switch (wish) {
    case 1:
        cout << "grecha" << endl;
        break;
    case 2:
        cout << "potato" << endl;
        break;
    case 3:
        cout << "surnuku" << endl;
        break;
    default:
        cout << "nothing specific" << endl;
    }
}

void Nps::showVegStatus() const {
    if (vegStatus) {
        cout << "is vegetarian" << endl;
    }
    else {
        cout << "is not vegetarian" << endl;
    }
}

void Nps::chooseRecepy(const Recepy& recepy) const {
    cout << name << " decides to cook: " << endl;
    cout << "Recipe: " << recepy.getName() << ", Page: " << recepy.getPage() << endl;


    recepy.meatStatus();

}

Nps::~Nps() {}
