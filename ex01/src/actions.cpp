
#include "utils.hpp"
#include "PhoneBook.hpp"


void add(PhoneBook& book) {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	std::cout << "-------------------------------" << std::endl;
	std::cout << "        Add New Contact        " << std::endl;
	std::cout << "-------------------------------" << std::endl;

	firstName =		readInput("FIRST NAME	: ");
	lastName =		readInput("LAST NAME	: ");
	nickname =		readInput("NICKNAME	: ");
	phoneNumber =	readInput("PHONE NUMBER	: ");
	secret =		readInput("DARKEST SECRET	: ");

	Contact contact(firstName, lastName, nickname, phoneNumber, secret);
	book.addContact(contact);
	std::cout << "✅ Contact saved!" << std::endl;
}

void	search(PhoneBook book) {
	std::string input;
	int			 index;

	if (book.getContactIndex() == 0) {
		printErrorMsg("❌ No Contacts in Phonebook");
		return ;
	}
	while (true) {
		printSearchHeader();
		book.printSearchContacts();
		input = readInput("\nEnter the index of the contact you want to view : ");
		if (input.length() != 1 || !std::isdigit(input[0])) {
			printErrorMsg("❌ Invalid index");
			continue;
		}
		index = input[0] - '0';
		if ((index < 0 || index >= MAX_CONTACTS) && index >= book.getContactIndex()) {
			printErrorMsg("❌ Invalid index");
			continue;
		}
		else {
			book.printContact(index);
			return ;
		}
	}
}