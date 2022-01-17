/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:47:18 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 02:08:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex
		<< ";amount:" << Account::_amount
		<< ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex
		<< ";amount:" << Account::_amount
		<< ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void )
{
	time_t tmp;
	struct tm *timeInfo;
	char buf[18] = {};

	time(&tmp);
	timeInfo = localtime(&tmp);
	strftime(buf, 18, "[%Y%m%d_%H%M%S]", timeInfo);
	std::cout << buf;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex
		<< ";p_amount:" << Account::_amount
		<< ";deposit:" << deposit;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << Account::_amount
		<< ";nb_deposits:" << Account::_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex
		<< ";p_amount:" << Account::_amount
		<< ";withdrawal:";
	if (Account::_amount < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << withdrawal
		<< ";amount:" << Account::_amount
		<< ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex
		<< ";amount:" << Account::_amount
		<< ";deposits:" << Account::_nbDeposits
		<< ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}


Account::Account( void )
{
	
}
