#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    char    buffer[20];
    time_t  timestamp;
    tm      *now;

    timestamp = std::time(NULL);
    now = std::localtime(&timestamp);
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", now);
    std::cout << buffer;
    // std::cout << "[19920104_091532] ";
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

Account::Account( int initial_deposit )
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created"
              << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed"
              << std::endl;
}

void Account::makeDeposit( int deposit )
{
    int p_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    int p_amount = this->_amount;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";withdrawal:";

    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;

    return true;
}

int Account::checkAmount( void ) const
{
    return this->_amount;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
