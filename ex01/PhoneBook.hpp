#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    static const int MAX = 8;
    Contact contacts[MAX];
    int count;      // total contacts stored (<= MAX)
    int nextIndex;  // next position to write (0..MAX-1)

    static std::string formatField(const std::string& s);

public:
    PhoneBook();
    void addContactInteractively();
    void displayContacts() const;
    void displayContactDetails(int index) const;
    int getCount() const;
};

#endif
