#pragma once

#include <string>
#include "AccountTypeEnum.h"
#include "CustomException.h"

class Account {
private:
	double Balance;

public:
	int AccountNumber;
	std::string Name;
	AccountType AccountType;

	double GetBalance() { return Balance; }
	void SetBalance(double balance) {

		this->Balance = balance;

		if (this->Balance < 0) {
			throw OverdraftException();
		}
	}

	virtual void CalculateInterest();
};