#include "recepyBook.h"

RecepyBook::RecepyBook(string n, int pages, string text)
    : name(n), numbPages(pages), content(text) {
    cout << "\n --- Created book: --- \n" << name << endl;
    cout << text << endl;
}

RecepyBook::RecepyBook(const RecepyBook& other)
    : name(other.name), numbPages(other.numbPages), content(other.content) {
    cout << "\n --- Copied book: " << name << "--- \n" << endl;
}

RecepyBook::RecepyBook(RecepyBook&& other) noexcept
    : name(move(other.name)), numbPages(other.numbPages), content(move(other.content)) {
    cout << "\n --- Moved book: " << name << "--- \n" << endl;
    other.numbPages = 0;
}

RecepyBook& RecepyBook::operator=(const RecepyBook& other) {
    if (this != &other) {
        name = other.name;
        numbPages = other.numbPages;
        content = other.content;
    }
    return *this;
}

RecepyBook& RecepyBook::operator=(RecepyBook&& other) noexcept {
    if (this != &other) {
        name = move(other.name);
        numbPages = other.numbPages;
        content = move(other.content);
        other.numbPages = 0;
    }
    return *this;
}

void RecepyBook::showSize() const {
    cout << numbPages << " pages" << endl;
}

RecepyBook::~RecepyBook() {
    cout << "\n --- Closing " << name << "--- \n" << endl;
}
