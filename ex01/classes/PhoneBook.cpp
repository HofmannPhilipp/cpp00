/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:41:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 17:18:16 by phhofman         ###   ########.fr       */
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
void	PhoneBook::printSearchContacts(void) {
	int	len = contactIndex < MAX_CONTACTS ? contactIndex : MAX_CONTACTS;
	for(int i = 0; i < len; i++) {
		this->contacts[i].printSearchDetails(i);
	}
}

void	PhoneBook::printContact(int index) {
	contacts[index].printFullDetails();
}

int		PhoneBook::getContactIndex() {
	return this->contactIndex;
}
