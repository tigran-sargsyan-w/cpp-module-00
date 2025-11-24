/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:27:53 by tsargsya          #+#    #+#             */
/*   Updated: 2025/11/24 15:27:52 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <string>

namespace {
    /**
     * Prompt the user until a non-empty line is entered or EOF occurs.
     * @param prompt Text to display when asking the user.
     * @param out Reference to string where the entered value will be stored.
     * @return true if a non-empty line was read, false on EOF.
     */
    bool askNonEmpty(const std::string& prompt, std::string& out)
    {
        while (true)
        {
            std::cout << prompt;
            if (!std::getline(std::cin, out)) return false; // EOF
            if (!out.empty()) return true;
            std::cout << "Field cannot be empty. Please try again.\n";
        }
    }

    /**
     * Format a string for table display, fitting it into 10 characters.
     * If the input is longer than 10 chars it is truncated and ends with '.'.
     * @param s Input string to format.
     * @return Formatted string of width 10.
     */
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

/**
 * Default constructor.
 * Initializes internal counters for stored contacts.
 */
PhoneBook::PhoneBook()
    : count(0), nextIndex(0) {}

/**
 * Copy constructor.
 * Copies contacts array and counter values from another PhoneBook.
 * @param other PhoneBook to copy from.
 */
PhoneBook::PhoneBook(const PhoneBook& other)
    : count(other.count), nextIndex(other.nextIndex)
{
    for (int i = 0; i < MAX; ++i)
    {
        contacts[i] = other.contacts[i];
    }
}

/**
 * Copy assignment operator.
 * Copies contacts and counters from another PhoneBook.
 * @param other PhoneBook to assign from.
 * @return reference to this PhoneBook.
 */
PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
    if (this != &other)
    {
        count = other.count;
        nextIndex = other.nextIndex;
        for (int i = 0; i < MAX; ++i)
        {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}

/**
 * Destructor. No dynamic resources to free.
 */
PhoneBook::~PhoneBook() {}

/**
 * Prompt the user for contact fields and add the new contact.
 * Stops early if EOF is reached while reading input.
 */
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

/**
 * Display a table of stored contacts with truncated fields.
 * @param index Zero-based index of the desired contact.
 */
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

/**
 * Print full stored details for the contact at `index`.
 * @param index Zero-based index of the desired contact.
 */
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

/**
 * Return the current number of stored contacts.
 * @return contact count (0..MAX).
 */
int PhoneBook::getCount() const { return count; }
