/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:30:41 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/03 13:36:09 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex		= Account::_nbAccounts;
	this->_amount			= initial_deposit;
	this->_nbDeposits		= 0;
	this->_nbWithdrawals	= 0;
	Account::_nbAccounts++;
	Account::_totalAmount	+= initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:"	<< this->_accountIndex	<< ";";
	std::cout << "amount:"	<< this->_amount		<< ";";
	std::cout << "created"	<< std::endl;
}

Account::~Account( void ) {
	Account::_nbAccounts--;
	Account::_totalAmount			-= this->_amount;
	Account::_totalNbDeposits		-= this->_nbDeposits;
	Account::_totalNbWithdrawals	-= this->_nbWithdrawals;

	Account::_displayTimestamp();
	std::cout << "index:"	<< this->_accountIndex	<< ";";
	std::cout << "amount:"	<< this->_amount		<< ";";
	std::cout << "closed"	<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	tempAmount = this->_amount;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" 		<< this->_accountIndex	<< ";";
	std::cout << "p_amount:"	<< tempAmount			<< ";";
	std::cout << "deposit:"		<< deposit				<< ";";
	std::cout << "amount:"		<< this->_amount		<< ";";
	std::cout << "nb_deposits:"	<< this->_nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal ( int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:"			<< this->_accountIndex	<< ";";
	std::cout << "p_amount:"		<< this->_amount		<< ";";

	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	Account::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount 			-= withdrawal;
	Account::_totalAmount 	-= withdrawal;

	std::cout << "withdrawal:"		<< withdrawal			<< ";";
	std::cout << "amount:"			<< this->_amount		<< ";";
	std::cout << "nb_withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
	return true;
}

int Account::checkAmount( void ) const {
	return this->_amount;
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
	Account::_displayTimestamp();
	std::cout << "accounts:"	<< Account::getNbAccounts()		<< ";";
	std::cout << "total:"		<< Account::getTotalAmount()	<< ";";
	std::cout << "deposits:"	<< Account::getNbDeposits()		<< ";";
	std::cout << "withdrawals:"	<< Account::getNbWithdrawals()	<< std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	now			= std::time(0);
	std::tm*	localTime	= std::localtime(&now);

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
	std::cout << "index:"		<< this->_accountIndex	<< ";";
	std::cout << "amount:"		<< this->_amount		<< ";";
	std::cout << "deposits:"	<< this->_nbDeposits	<< ";";
	std::cout << "withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
}