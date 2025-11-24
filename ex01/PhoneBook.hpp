/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:27:54 by tsargsya          #+#    #+#             */
/*   Updated: 2025/11/24 15:27:55 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX = 8;
    Contact contacts[MAX];
    int count;      // total contacts stored (<= MAX)
    int nextIndex;  // next position to write (0..MAX-1)

public:
    PhoneBook();
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook& other);
    ~PhoneBook();
    
    void addContactInteractively();
    void displayContacts() const;
    void displayContactDetails(int index) const;
    int getCount() const;
};

#endif
