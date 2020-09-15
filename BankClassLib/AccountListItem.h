#pragma once

#include <string>
#include "AccountTypeEnum.h"

class AccountListItem {
public:
	int AccountNumber;
	std::string Name;
	double Balance;
	AccountType Accounttype;

	int GetAccountNumber() { return AccountNumber; }
	void SetAccountNumner(int accountNumber) { this->AccountNumber = accountNumber; }

	std::string GetName() { return Name; }
	void SetName(std::string name) { this->Name = name; }

	double GetBalance() { return Balance; }
	void SetBalance(double balance) { this->Balance = balance; }

	AccountType GetAccountType() { return Accounttype; }
	void SetAccountType(AccountType accountType) { this->Accounttype = accountType; }
};