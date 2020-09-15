#pragma once

#include "Account.h"
#include "AccountTypeEnum.h"

class CheckingAccount : public Account {
public:
	CheckingAccount(int accountNumber, std::string name) {
		this->AccountNumber = accountNumber;
		this->Name = name;
		this->AccountType = AccountChecking;
	}

	void CalculateInterest() {

		double _balance = GetBalance();
		if (_balance > 0) {

			_balance *= 1.005;
			SetBalance(_balance);
		}
	}
};
