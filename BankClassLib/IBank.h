#pragma once

#include <string>
#include <list>
#include "Account.h"
#include "AccountTypeEnum.h"
#include "AccountListItem.h"

struct IBank {
public:
	std::string BankName;
	double Inventory;

	std::string GetBankName() { return BankName; }
	double GetInventory() { return Inventory; }

	virtual int CreateAccount(std::string name, AccountType type) = 0;

	virtual double InsertAmount(int accountNumber, double amount) = 0;

	virtual double WithdrawAmount(int accountNumber, double amount) = 0;

	virtual Account Balance(int accountNumber) = 0;

	virtual void InterestCalculating() = 0;

	virtual std::list<AccountListItem> AccountLookUpList() = 0;

	virtual std::list<AccountListItem> GetAccountList() = 0;
	
	virtual ~IBank() = default;
};