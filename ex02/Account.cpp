/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:49:30 by ychahbi           #+#    #+#             */
/*   Updated: 2023/12/09 12:56:50 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "Account.hpp"

int Account::_nbAccounts			= 0;
int Account::_totalAmount			= 0;
int Account::_totalNbDeposits		= 0;
int Account::_totalNbWithdrawals	= 0;
static	int	i 						= 0;

Account::Account( int initial_deposit )
{
	_accountIndex		= i;
	_amount				= initial_deposit;
	_totalAmount		+= _amount;
	_nbDeposits			= 0;
	_nbWithdrawals		= 0;
	i++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";p_amount:"
	<< _amount - deposit << ";deposit:" << deposit << ";amount:"
	<< _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _amount)
	{
		_amount = _amount - withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex<< ";p_amount:"
		<< _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:"
		<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (1);
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";p_amount:"
	<< _amount << ";withdrawal:refused" << std::endl;
	return (0);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t currentTime = std::time(NULL);

    char myTime[16];
    strftime(myTime, sizeof(myTime), "%Y%m%d_%H%M%S", std::localtime(&currentTime));
    std::cout << "[" << myTime << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:"
	<< _totalAmount << ";deposits:" << Account::getNbDeposits() << ";withdrawals:"
	<< Account::getNbWithdrawals() << std::endl;
	
}
int	Account::getNbAccounts( void )
{
	return (i);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"<< std::endl;	
}