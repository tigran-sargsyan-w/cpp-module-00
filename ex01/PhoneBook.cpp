#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <string>

namespace {
    bool askNonEmpty(const std::string& prompt, std::string& out) {
        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, out)) return false; // EOF
            if (!out.empty()) return true;
            std::cout << "Field cannot be empty. Please try again.\n";
        }
    }

    std::string formatField(const std::string& s)
    {
        if (s.length() <= 10)
        {
            std::ostringstream oss;
            oss << std::setw(10) << s;
            return oss.str();
        }
        // truncate and put a dot at the end
        std::string res = s.substr(0, 9);
        res.push_back('.');
        return res;
    }
}

PhoneBook::PhoneBook()
    : count(0), nextIndex(0) {}

void PhoneBook::addContactInteractively()
{
    std::string first, last, nick, phone, secret;

    if (!askNonEmpty("First name: ", first)) return;
    if (!askNonEmpty("Last name: ", last)) return;
    if (!askNonEmpty("Nickname: ", nick)) return;
    if (!askNonEmpty("Phone number: ", phone)) return;
    if (!askNonEmpty("Darkest secret: ", secret)) return;

    contacts[nextIndex].setAll(first, last, nick, phone, secret);
    nextIndex = (nextIndex + 1) % MAX;
    if (count < MAX) ++count;
    std::cout << "Added contact.\n";
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < count; ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << "\n";
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    const Contact& c = contacts[index];
    std::cout << "First name: " << c.getFirstName() << "\n";
    std::cout << "Last name: " << c.getLastName() << "\n";
    std::cout << "Nickname: " << c.getNickname() << "\n";
    std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}

int PhoneBook::getCount() const { return count; }
