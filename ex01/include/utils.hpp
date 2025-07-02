/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 13:03:36 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>


class PhoneBook ;

std::string	format(const std::string& str);
void		add(PhoneBook& book);
void		search(PhoneBook book);
void		printErrorMsg(std::string msg);
std::string	readInput(std::string prompt);
void	 	printSearchHeader(void);
void		add(PhoneBook& book);
void		search(PhoneBook book);

#endif