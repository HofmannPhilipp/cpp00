/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:06:20 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 17:09:18 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact contacts[MAX_CONTACTS];
		int contactIndex;
	
	public:
		PhoneBook();
		void addContact(Contact newContact);
		void printContacts(void);
		void printContact(int index);
		int getContactIndex(void);
};

#endif