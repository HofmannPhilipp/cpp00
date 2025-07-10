/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:46:25 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/10 13:15:21 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"
#include "utils.hpp"

int main(void)
{
	std::string input;
	PhoneBook book;

	std::cout << "📞 Welcome to my Phonebook 📖" << std::endl;
	while (1)
	{
		std::cout << "\nPlease enter a command:\n"
				  << "  ADD    - Add a new contact\n"
				  << "  SEARCH - Search and display a contact\n"
				  << "  EXIT   - Exit the program\n"
				  << std::endl;

		input = readInput("> ");
		if (input == "ADD")
			add(book);
		else if (input == "SEARCH")
			search(book);
		else if (input == "EXIT")
		{
			std::cout << "👋 Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		}
		else
			printErrorMsg("❌ Unknown command: Please enter ADD, SEARCH or EXIT.");
	}
	return 0;
}