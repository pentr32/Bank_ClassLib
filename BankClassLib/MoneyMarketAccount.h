#pragma once

#include "Account.h"
#include "AccountTypeEnum.h"

class MoneyMarketAccount : public Account {
public:
	MoneyMarketAccount(int accountNumber, std::string name) {
		this->AccountNumber = accountNumber;
		this->Name = name;
		this->AccountType = AccountType::AccountMoneyMarket;
	}

	void CalculateInterest() override {

		double _balance = GetBalance();
		if (_balance > 0) {

			_balance *= 1.005;
			SetBalance(_balance);
		}

			
		else {
			_balance *= 0.95;
			SetBalance(_balance);
		}
	}
};
