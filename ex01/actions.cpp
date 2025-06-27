
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

	std::cout << "First name     : ";
	std::getline(std::cin, firstName);

	std::cout << "Last name      : ";
	std::getline(std::cin, lastName);

	std::cout << "Nickname       : ";
	std::getline(std::cin, nickname);

	std::cout << "Phone number   : ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, secret);

	Contact contact(firstName, lastName, nickname, phoneNumber, secret);
	book.addContact(contact);
	std::cout << "✅ Contact saved!" << std::endl;
}

void	search(PhoneBook book) {
	std::string buffer;
	int			 index;
	if (book.getContactIndex() == 0)
	{
		printErrorMsg("No Contacts in Phonebook");
		return ;
	}
	printSearchHeader();
	while (1) {
		
		book.printContacts();
		std::cout << "\nEnter the index of the contact you want to view (0-7): ";
		std::getline(std::cin, buffer);
		index = stringToIntSafe(buffer);
		if (index < 0 || index >= MAX_CONTACTS) {
			printErrorMsg("❌ Invalid index");
			return ;
		}
		else {
			book.printContact(index);
			return ;
		}
	}
}