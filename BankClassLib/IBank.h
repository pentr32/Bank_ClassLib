#pragma once

#include <string>
#include <list>
#include "Account.h"
#include "AccountTypeEnum.h"
#include "AccountListItem.h"

class IBank {
public:
	virtual int CreateAccount(std::string name, AccountType type);

	virtual double InsertAmount(int accountNumber, double amount);

	virtual double WithdrawAmount(int accountNumber, double amount);

	virtual Account Balance(int accountNumber);

	virtual void InterestCalculating();

	std::list<AccountListItem> GetAccountList();
};