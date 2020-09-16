#pragma once

#include "Account.h"
#include "AccountTypeEnum.h"

class SavingsAccount : public Account {
public:
	SavingsAccount(int accountNumber, std::string name) {
		this->AccountNumber = accountNumber;
		this->Name = name;
		this->AccountType = AccountType::AccountSavings;
	}

	void CalculateInterest() override {

        double _balance = GetBalance();
        if (_balance > 100000) {

            _balance *= 1.03;
            SetBalance(_balance);
        }

        else
        {
            if (_balance > 50000) {

                _balance *= 1.02;
                SetBalance(_balance);
            }

            else
            {
                if (_balance > 0) {
                    _balance *= 1.01;
                    SetBalance(_balance);
                }
            }
        }
	}
};