
#include "utils.hpp"
#include "PhoneBook.hpp"

void add(PhoneBook &book)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	std::cout << "-------------------------------" << std::endl;
	std::cout << "        Add New Contact        " << std::endl;
	std::cout << "-------------------------------" << std::endl;

	firstName = readInput("FIRST NAME	: ");
	if (firstName == "EXIT")
		return;

	lastName = readInput("LAST NAME	: ");
	if (lastName == "EXIT")
		return;

	nickname = readInput("NICKNAME	: ");
	if (nickname == "EXIT")
		return;

	phoneNumber = readInput("PHONE NUMBER	: ");
	if (phoneNumber == "EXIT")
		return;

	while (!isValidPhoneNumber(phoneNumber))
	{
		phoneNumber = readInput("PHONE NUMBER	: ");
		if (phoneNumber == "EXIT")
			return;
	}
	
	secret = readInput("DARKEST SECRET	: ");
	if (secret == "EXIT")
		return;
	Contact contact(firstName, lastName, nickname, phoneNumber, secret);
	book.addContact(contact);
	std::cout << "\n✅ Contact saved!" << std::endl;
}

void search(PhoneBook book)
{
	std::string input;
	int index;
	if (book.getContactIndex() == 0)
	{
		printErrorMsg("❌ No contacts found. Please add contacts before searching.");
		return;
	}

	while (true)
	{
		printSearchHeader();
		book.printSearchContacts();
		input = readInput("\nEnter the index of the contact you want to view or type EXIT: ");
		if (input == "EXIT")
			return;

		if (input.length() != 1)
		{
			printErrorMsg("❌ Invalid input: Please enter a single digit index (0-7) or EXIT.");
			continue;
		}

		if (!std::isdigit(input[0]))
		{
			printErrorMsg("❌ Invalid input: Index must be a digit (0-7).");
			continue;
		}

		index = input[0] - '0';
		if (index < 0 || index >= MAX_CONTACTS)
		{
			printErrorMsg("❌ Index out of range. Valid index is between 0 and 7.");
			continue;
		}

		if (index >= book.getContactIndex())
		{
			printErrorMsg("❌ No contact exists at this index.");
			continue;
		}
		book.printContact(index);
		return;
	}
}