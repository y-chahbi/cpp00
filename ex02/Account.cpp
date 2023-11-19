/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:49:30 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/19 15:27:57 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
static		int  i = 0;

Account::Account( int initial_deposit )
{
	_accountIndex		= i;
	_amount				= initial_deposit;
	_nbDeposits			= 0;
	_nbWithdrawals		= 0;
	i++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount;" << _amount << ";created"<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += _amount;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex<< ";p_amount:"
	<< _amount - deposit << ";deposit:" << deposit << ";amount:"
	<< _amount << ";nb_deposits:" << Account::getNbDeposits() << std::endl;
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
	std::cout << "index:" << _accountIndex << ";amount;" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t currentTime = std::time(nullptr);

    // Create a buffer to store the formatted time
    char buffer[80]; // Adjust the size as needed

    // Format the time and store it in the buffer
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&currentTime));

    // Print the formatted time
    std::cout << "[" << buffer << "] ";
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
	std::cout << "index:" << _accountIndex << ";amount;" << _amount << ";closed"<< std::endl;	
}