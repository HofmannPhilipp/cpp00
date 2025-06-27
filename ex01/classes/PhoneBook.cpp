/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:41:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 17:09:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->contactIndex = 0;
}

void	PhoneBook::addContact(Contact newContact)
{
	this->contacts[contactIndex % MAX_CONTACTS] = newContact;
	this->contactIndex++;
}
void	PhoneBook::printContacts(void) {
	int	len = contactIndex < MAX_CONTACTS ? contactIndex : MAX_CONTACTS;
	for(int i = 0; i < len; i++) {
		this->contacts[i].printDetails(i);
	}
}

void	PhoneBook::printContact(int index) {
	if (index >= this->contactIndex || index < 0 || index > MAX_CONTACTS) {
		printErrorMsg("Wrong Index");
		return ;
	}
	contacts[index].printFullDetails();
}

int PhoneBook::getContactIndex() {
	return this->contactIndex;
}
