/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:46:25 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 15:27:50 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	std::string buffer;
	PhoneBook book;

	std::cout << "Welcome to my Phonebook 📞📖" << std::endl;
	while(1) {
		std::cout << "\nPlease enter a command:\n"
			<< "  ADD	- Add a new contact\n"
			<< "  SEARCH - Search and display a contact\n"
			<< "  EXIT	- Exit the program\n" 
			<< std::endl;
		std::cout << "> ";
		std::getline(std::cin, buffer);
		if (buffer.compare("ADD") == 0) {
			add(book);
		}
		else if (buffer.compare("SEARCH") == 0) {
			search(book);
		}
		else if (buffer.compare("EXIT") == 0) {
			break;
		}
	}
	return 0;
}