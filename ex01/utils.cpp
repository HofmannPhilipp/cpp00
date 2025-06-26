/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:02:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 17:10:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"

std::string format(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

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
		error_msg("No Contacts in Phonebook");
		return ;
	}
	while (1) {
		std::cout << std::setw(10) << "index" << "|";
		std::cout << std::setw(10) << "first name" << "|";
		std::cout << std::setw(10) << "last name" << "|";
		std::cout << std::setw(10) << "nickname" << std::endl;
		book.printContacts();
		std::cout << "\nEnter the index of the contact you want to view (0-7): ";
		std::getline(std::cin, buffer);
		index = std::stoi(buffer);
		if (index < 0 || index >= 8) {
			std::cout << "❌ Invalid index. Please enter a valid number between 0 and "
					  << (8 - 1) << ".\n";
		}
		else {
			book.printContact(index);
			return ;
		}
	}
}

void	error_msg(std::string msg) {
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}