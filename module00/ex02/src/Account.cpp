#include <iostream>
#include <iomanip>
#include "Account.hpp"

// Public:

int		Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
		<< std::endl;
}


Account::Account( int initial_deposit ) : _amount(initial_deposit) {

	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

Account::~Account( void ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "closed" << std::endl;
}


void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		 << "p_amount:" << this->checkAmount() << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";"
		 << "amount:" << this->checkAmount() << ";"
		 << "nb_deposits:" << this->_nbDeposits
		 << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		 << "p_amount:" << this->checkAmount() << ";";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {

	return this->_amount;
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

// Private:

void	Account::_displayTimestamp( void ) {

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout << "["
		<< 1900 + timeinfo->tm_year
		<< std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << timeinfo->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << timeinfo->tm_hour
		<< std::setw(2) << std::setfill('0') << timeinfo->tm_min
		<< std::setw(2) << std::setfill('0') << timeinfo->tm_sec
		<< "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
