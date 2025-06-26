/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:45:07 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 17:05:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->secret = "";
}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
}

void Contact::printDetails(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format(this->firstName) << "|";
	std::cout << std::setw(10) << format(this->lastName) << "|";
	std::cout << std::setw(10) << format(this->nickname) << std::endl;
}

void Contact::printFullDetails() const {
	std::cout << "\n--- Contact Details ---" << std::endl;
	std::cout << "First name     : " << this->firstName << std::endl;
	std::cout << "Last name      : " << this->lastName << std::endl;
	std::cout << "Nickname       : " << this->nickname << std::endl;
	std::cout << "Phone number   : " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->secret << std::endl;
	std::cout << "------------------------" << std::endl;
}

