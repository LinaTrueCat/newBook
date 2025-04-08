#include <iostream>
#include <vector>
#include "recepy.h"
#include "mainDish.h"
#include "nps.h"
#include "recepyBook.h"
#include "cooking.h"

using namespace std;

int main() {
    RecepyBook book1("Grandma's Recipes", 200, "This book contains ancient cooking secrets...");
    RecepyBook book2 = move(book1);

   
    Recepy* staticGrecha = new MainDish("StaticGrecha", 10, false, 400);  //
    cout << "\n--- Static Binding Example ---\n";
    staticGrecha->Recepy::recepyStatus(); // Static call викличе MainDish
    staticGrecha->recepyStatus();         // Virtual call викличе MainDish::recepyStatus
    delete staticGrecha;

    vector<Recepy*> recipes;
    recipes.push_back(new MainDish("Plov", 50, true, 850));
    recipes.push_back(new MainDish("Soup", 60, false, 300));

    cout << "\n--- Dynamic Polymorphism (Pointer) ---\n";
    for (Recepy* r : recipes) {
        r->recepyStatus();
        r->showType();
        delete r;
    }

    MainDish dumplings("Dumplings", 70, true, 600);   //
    Recepy& ref = dumplings;
    cout << "\n--- Dynamic Polymorphism (Reference) ---\n";
    ref.recepyStatus();
    ref.showType();

    cout << "\n--- Interface Usage ---\n";
    cooking* c1 = new MainDish("Borscht", 30, true, 500);
    cooking* c2 = new RecepyBook("Modern Meals", 150, "Healthy & tasty!");

    c1->cook();
    c2->cook();

    delete c1;
    delete c2;

    return 0;
}
