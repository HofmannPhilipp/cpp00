/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:02:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 13:23:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	printErrorMsg(std::string msg) {
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

std::string	readInput(std::string prompt) {
	std::string buffer;

	while (true) {
		std::cout << prompt << std::flush;
		if (std::getline(std::cin, buffer) && !buffer.empty())
			return buffer;
		if (std::cin.eof()) {
			std::cin.clear();
			std::cout << std::endl;
			printErrorMsg("EOF (Ctrl + D) Input not allowed.");
			exit(1);
		}
	}
	return "";
}

std::string format(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	printSearchHeader(void) {
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
}