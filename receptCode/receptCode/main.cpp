#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "recepy.h"
#include "mainDish.h"
#include "nps.h"
#include "recepyBook.h"
#include "cooking.h"

using namespace std;

vector<Recepy*> recipes;
const string ADMIN_PASSWORD = "1";
const string DATA_FILE = "recipes.txt";
const string USER_LOG = "user_history.txt";

bool isDigitsOnly(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return !str.empty();
}

int safeInputInt() {
    string input;
    cin >> input;
    while (!isDigitsOnly(input)) {
        cout << "Invalid input. Enter a number: ";
        cin >> input;
    }
    return stoi(input);
}

void saveRecipesToFile() {
    ofstream out(DATA_FILE);
    for (const auto& r : recipes) {
        out << r->getName() << " " << r->getPage() << endl;
    }
    out.close();
}

void loadRecipesFromFile() {
    recipes.clear();
    ifstream in(DATA_FILE);
    string name;
    int page;
    while (in >> name >> page) {
        recipes.push_back(new MainDish(name, page, true, 500));
    }
    in.close();
}

void deleteRecipe() {
    cout << "\nAvailable recipes:\n";
    for (int i = 0; i < recipes.size(); ++i) {
        cout << i + 1 << ". " << recipes[i]->getName() << endl;
    }
    cout << "Enter recipe number to delete: ";
    int choice = safeInputInt();
    if (choice < 1 || choice > recipes.size()) {
        cout << "Invalid choice!\n";
        return;
    }
    delete recipes[choice - 1];
    recipes.erase(recipes.begin() + (choice - 1));
    saveRecipesToFile();
    cout << "Recipe deleted.\n";
}

void logUserAction(const string& action) {
    ofstream log(USER_LOG, ios::app);
    log << action << endl;
    log.close();
}

void adminMenu() {             //-----
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add recipe\n2. Delete recipe\n3. Show all recipes\n4. Exit\nChoice: ";
        choice = safeInputInt();

        switch (choice) {
        case 1: {
            string name;
            int page;
            cout << "Enter recipe name: ";
            cin >> name;
            cout << "Enter page: ";
            page = safeInputInt();
            recipes.push_back(new MainDish(name, page, true, 500));
            saveRecipesToFile();
            break;
        }
        case 2:
            deleteRecipe();
            break;
        case 3:
            for (const auto& r : recipes)
                r->recepyStatus();
            break;
        case 4:
            cout << "Exiting admin menu...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
    } while (choice != 4);
}

void userMenu() {               //----
    int choice;
    do {
        cout << "\n--- User Menu ---\n";
        cout << "1. View recipes\n2. Cook recipe\n3. Exit\nChoice: ";
        choice = safeInputInt();

        switch (choice) {
        case 1:
            for (const auto& r : recipes)
                r->recepyStatus();
            break;
        case 2: {
            cout << "Choose recipe number to cook:\n";
            for (int i = 0; i < recipes.size(); ++i)
                cout << i + 1 << ". " << recipes[i]->getName() << endl;
            int pick = safeInputInt();
            if (pick >= 1 && pick <= recipes.size()) {
                recipes[pick - 1]->recepyStatus();
                logUserAction("User chose to cook: " + recipes[pick - 1]->getName());
            }
            else {
                cout << "Invalid choice\n";
            }
            break;
        }
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

int main() {
    loadRecipesFromFile();

    cout << "Login as (1 - Admin, 2 - User): ";
    int role = safeInputInt();

    if (role == 1) {
        string pass;
        cout << "Enter admin password: ";
        cin >> pass;
        if (pass == ADMIN_PASSWORD) {
            adminMenu();
        }
        else {
            cout << "Incorrect password!\n";
        }
    }
    else if (role == 2) {
        userMenu();
    }
    else {
        cout << "Invalid role selected!\n";
    }

    for (auto& r : recipes)
        delete r;
    recipes.clear();

    return 0;
}
