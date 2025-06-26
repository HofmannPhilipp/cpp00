/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 15:20:14 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string.h>
#include <iostream>

class PhoneBook ;

std::string	format(const std::string& str);
void		add(PhoneBook& book);
void		search(PhoneBook book);
void		error_msg(std::string msg);

#endif