/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:02:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/10 13:01:23 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void printErrorMsg(std::string msg)
{
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

std::string readInput(std::string prompt)
{
	std::string buffer;

	while (true)
	{
		std::cout << prompt << std::flush;
		if (std::getline(std::cin, buffer) && !buffer.empty())
			return buffer;
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout << std::endl;
			printErrorMsg("EOF (Ctrl + D) Input not allowed.");
			exit(1);
		}
	}
	return "";
}

std::string format(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void printSearchHeader(void)
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
}

bool isValidPhoneNumber(const std::string &number)
{
	if (number.empty())
	{
		printErrorMsg("❌ Error: Phone number cannot be empty.");
		return false;
	}

	size_t start = 0;
	if (number[0] == '+')
	{
		if (number.length() == 1)
		{
			printErrorMsg("❌ Error: '+' must be followed by digits.");
			return false;
		}
		start = 1;
	}

	for (size_t i = start; i < number.length(); ++i)
	{
		if (!std::isdigit(number[i]))
		{
			printErrorMsg("❌ Error: Phone number must contain digits only (besides optional leading '+').");
			return false;
		}
	}
	if (number.length() < 6)
	{
		printErrorMsg("❌ Error: Phone number is too short. Must be at least 6 characters.");
		return false;
	}
	
	if (number.length() > 15)
	{
		printErrorMsg("❌ Error: Phone number is too long. Max allowed length is 15 characters.");
		return false;
	}
	return true;
}