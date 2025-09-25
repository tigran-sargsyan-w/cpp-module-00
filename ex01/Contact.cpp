#include "Contact.hpp"

Contact::Contact()
    : firstName(""), lastName(""), nickname(""),
      phoneNumber(""), darkestSecret("") {}

void Contact::setAll(const std::string& first,
                     const std::string& last,
                     const std::string& nick,
                     const std::string& phone,
                     const std::string& secret)
{
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isEmpty() const
{
    return firstName.empty() && lastName.empty() && nickname.empty()
           && phoneNumber.empty() && darkestSecret.empty();
}
