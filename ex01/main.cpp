#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!\n";
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF detected. Exiting.\n";
            break;
        }

        // normalize command to uppercase for robustness
        for (size_t i = 0; i < command.length(); ++i)
            command[i] = std::toupper(command[i]);

        if (command == "ADD")
        {
            phonebook.addContactInteractively();
        }
        else if (command == "SEARCH")
        {
            if (phonebook.getCount() == 0)
            {
                std::cout << "PhoneBook is empty. Add some contacts first.\n";
                continue;
            }
            phonebook.displayContacts();
            std::cout << "Enter index to view details: ";
            std::string idxStr;
            if (!std::getline(std::cin, idxStr)) {
                std::cout << "\nEOF detected. Exiting.\n";
                break;
            }
            // trim spaces
            std::stringstream ss(idxStr);
            int idx;
            if (!(ss >> idx) || !ss.eof()) {
                std::cout << "Invalid input. Please enter a numeric index.\n";
                continue;
            }
            phonebook.displayContactDetails(idx);
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else if (command.empty())
        {
            // ignore empty line
            continue;
        }
        else
        {
            std::cout << "Unknown command. Please use ADD, SEARCH or EXIT.\n";
        }
    }

    return 0;
}
