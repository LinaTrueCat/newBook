#include "RecepyBook.h"

RecepyBook::RecepyBook(string n, int pages, string text)
    : name(n), numbPages(pages), content(text) {
    cout << "\n --- Created book: " << "--- \n" << name << endl;
    cout << text << endl;
}

RecepyBook::RecepyBook(RecepyBook&& other) noexcept
    : name(std::move(other.name)), numbPages(other.numbPages), content(std::move(other.content)) {
    cout << "\n --- Moved book: " << name << "--- \n" << endl;
    other.numbPages = 0;
}

void RecepyBook::showSize() const {
    cout << numbPages << " pages" << endl;
}

RecepyBook::~RecepyBook() {
    cout << "\n --- Closing " << name << "--- \n" << endl;
}
