/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:30:41 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 18:46:41 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	
}

void	makeDeposit( int deposit ) {
	this.
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "accounts:" << Account::getNbAccounts << ";";
	std::cout << "total:" << Account::getNbAccounts << ";";
	std::cout << "deposits:" << Account::getNbAccounts << ";";
	std::cout << "withdrawals:" << Account::getNbAccounts << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	now = std::time(0);
	std::tm*	localTime = std::localtime(&now);

	std::cout
		<< "["
		<< (1900 + localTime->tm_year)
		<< std::setw(2) << std::setfill('0') << (1 + localTime->tm_mon)
		<< std::setw(2) << std::setfill('0') << localTime->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << localTime->tm_hour
		<< std::setw(2) << std::setfill('0') << localTime->tm_min
		<< std::setw(2) << std::setfill('0') << localTime->tm_sec
		<< "] ";
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}