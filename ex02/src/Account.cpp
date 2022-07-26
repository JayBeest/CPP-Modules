#include <iostream>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

using namespace::std;

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
	cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
		<< endl;
}


Account::Account( int initial_deposit ) : _amount(initial_deposit) {

	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << endl;

}

Account::~Account( void ) {

	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "closed" << endl;

}


void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "p_amount:" << this->checkAmount() << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	cout << "deposit:" << deposit << ";"
		 << "amount:" << this->checkAmount() << ";"
		 << "nb_deposits:" << this->_nbDeposits
		 << endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "p_amount:" << this->checkAmount() << ";";
	if (withdrawal > this->checkAmount())
	{
		cout << "withdrawal:refused" << endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< endl;

	return (true);
}

int		Account::checkAmount( void ) const {

	return this->_amount;
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< endl;

}

// Private:

void	Account::_displayTimestamp( void ) {

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	cout << "["
		<< 1900 + timeinfo->tm_year
		<< setw(2) << setfill('0') << timeinfo->tm_mon + 1
		<< setw(2) << setfill('0') << timeinfo->tm_mday
		<< "_"
		<< setw(2) << setfill('0') << timeinfo->tm_hour
		<< setw(2) << setfill('0') << timeinfo->tm_min
		<< setw(2) << setfill('0') << timeinfo->tm_sec
		<< "] ";

}


