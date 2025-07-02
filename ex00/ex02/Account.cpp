/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:30:41 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/02 17:53:19 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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