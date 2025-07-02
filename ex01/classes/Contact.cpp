/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:45:07 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 17:17:26 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	secret = "";
}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
}

void Contact::printSearchDetails(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format(firstName) << "|";
	std::cout << std::setw(10) << format(lastName) << "|";
	std::cout << std::setw(10) << format(nickname) << std::endl;
}

void Contact::printFullDetails(void) const {
	std::cout << "\n--- Contact Details ---" << std::endl;
	std::cout << "First name     : " << firstName << std::endl;
	std::cout << "Last name      : " << lastName << std::endl;
	std::cout << "Nickname       : " << nickname << std::endl;
	std::cout << "Phone number   : " << phoneNumber << std::endl;
	std::cout << "Darkest secret : " << secret << std::endl;
	std::cout << "------------------------" << std::endl;
}

