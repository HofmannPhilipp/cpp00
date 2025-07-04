/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:06:20 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 17:18:25 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact contacts[MAX_CONTACTS];
		int contactIndex;
	
	public:
		PhoneBook();
		void addContact(Contact newContact);
		void printSearchContacts(void);
		void printContact(int index);
		int getContactIndex(void);
};

#endif