#include <iostream>
#include "recepy.h"
#include "nps.h"
#include "recepyBook.h"

using namespace std;

int main() {
    cout << "\n--- Creating Books ---\n";
    RecepyBook book1("Grandma's Recipes", 200, "This book contains ancient cooking secrets...");

    cout << "\n--- Moving Book ---\n";
    RecepyBook book2 = move(book1); // ������� move-�����������

    Recepy grecha("Grecha", 20);
    Recepy potato("Potato", 30);
    Recepy surnuku("Surnuku", 40, false);

    cout << "Amount of Recepy is: " << Recepy::getAmountOfRecepy() << endl;

    grecha.recepyStatus();
    grecha.meatStatus();
    Recepy vegGrecha = grecha;
    vegGrecha.recepyStatus();
    vegGrecha.meatStatus();

    potato.recepyStatus();
    potato.meatStatus();
    Recepy vegPotato = potato;
    vegPotato.recepyStatus();
    vegPotato.meatStatus();

    surnuku.recepyStatus();
    surnuku.meatStatus();
    Recepy vegSurnuku = surnuku;
    vegSurnuku.recepyStatus();
    vegSurnuku.meatStatus();

    cout << endl;

    Nps bob("Bob", 1, false);
    Nps gigi("Gigi", 2, true);
    Nps maruna("Maruna", 3, false);

    bob.chooseRecepy(grecha);
    gigi.chooseRecepy(potato);
    maruna.chooseRecepy(surnuku);

    cout << endl;

    return 0;
}
