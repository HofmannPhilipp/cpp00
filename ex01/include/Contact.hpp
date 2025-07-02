/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:17:02 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 17:17:22 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "utils.hpp"

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;

	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret);

		void printSearchDetails(int index) const;
		void printFullDetails() const;
};

#endif