#include "Contact.hpp"

/**
 * Default constructor.
 * Initializes all contact fields to empty strings.
 */
Contact::Contact()
    : firstName(""), lastName(""), nickname(""),
      phoneNumber(""), darkestSecret("") {}

/**
 * Copy constructor.
 * Copies all fields from another Contact.
 * @param other Contact to copy from.
 */
Contact::Contact(const Contact& other)
    : firstName(other.firstName),
      lastName(other.lastName),
      nickname(other.nickname),
      phoneNumber(other.phoneNumber),
      darkestSecret(other.darkestSecret) {}

/**
 * Copy assignment operator.
 * Assigns fields from another Contact.
 * @param other Contact to assign from.
 * @return reference to this Contact.
 */
Contact& Contact::operator=(const Contact& other)
{
    if (this != &other)
    {
        firstName = other.firstName;
        lastName = other.lastName;
        nickname = other.nickname;
        phoneNumber = other.phoneNumber;
        darkestSecret = other.darkestSecret;
    }
    return *this;
}

/**
 * Destructor. No special cleanup required.
 */
Contact::~Contact() {}

/**
 * Set all contact fields at once.
 * @param first First name string.
 * @param last Last name string.
 * @param nick Nickname string.
 * @param phone Phone number string.
 * @param secret Darkest secret string.
 */
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

/**
 * Get the first name.
 * @return first name string.
 */
std::string Contact::getFirstName() const { return firstName; }

/**
 * Get the last name.
 * @return last name string.
 */
std::string Contact::getLastName() const { return lastName; }

/**
 * Get the nickname.
 * @return nickname string.
 */
std::string Contact::getNickname() const { return nickname; }

/**
 * Get the phone number.
 * @return phone number string.
 */
std::string Contact::getPhoneNumber() const { return phoneNumber; }

/**
 * Get the darkest secret.
 * @return darkest secret string.
 */
std::string Contact::getDarkestSecret() const { return darkestSecret; }
