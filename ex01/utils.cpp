/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:02:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/06/26 17:10:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	printErrorMsg(std::string msg) {
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

int 	stringToIntSafe(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    result = !ss.fail() && ss.eof() ? result : -1;
    return result;
}

std::string format(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	printSearchHeader(void) {
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
}