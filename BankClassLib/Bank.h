#pragma once

#include <iostream>
#include <string>
#include <list>
#include "IBank.h"
#include "Account.h"
#include "AccountListItem.h"
#include "AccountTypeEnum.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "MoneyMarketAccount.h"

class Bank : public IBank {
private:
	int accountCounter;
	std::list<Account> Accounts;

public:
	std::string BankName;
	double Inventory;

	#pragma region
	Bank(std::string bankName, double inventory) {
		this->BankName = bankName;
		this->Inventory = inventory;
	}
	#pragma endregion

	int CreateAccount(std::string name, AccountType type) {

		switch (type) {

			// Create a new CheckingAccount and add to accounts list.
			case AccountChecking:
				Accounts.push_back(CheckingAccount(++accountCounter, name));
				break;

			// Create a new SavingsAccount and add to accounts list.
			case AccountSavings:
				Accounts.push_back(SavingsAccount(++accountCounter, name));
				break;
				
			// Create a new MoneyMarketAccount and add to accounts list.
			case AccountMoneyMarket:
				Accounts.push_back(MoneyMarketAccount(++accountCounter, name));
				break;

			default:
				return 0;
		}
		return accountCounter;
	}

	double InsertAmount(int accountNumber, double amount) {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for(Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Add the amount to the account that was found from the list.
		foundAccount.Balance += amount;

		// Returns account's balance.
		return foundAccount.Balance;
	}

	double WithdrawAmount(int accountNumber, double amount) {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for (Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Add the amount to the account that was found from the list.
		foundAccount.Balance -= amount;

		// Returns account's balance.
		return foundAccount.Balance;
	}

	Account Balance(int accountNumber) {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for (Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Find the specific account from the list by account number.
		return foundAccount;
	}

	void InterestCalculating() {
		
		for (Account acc : Accounts) {
			acc.CalculateInterest();
		}
	}

	//std::list<AccountListItem> GetAccountList() {

	//	std::list<AccountListItem> accountList;
	//	for (Account acc : Accounts) {

	//		accountList.push_back(AccountListItem{


	//		});
	//	}
	//}
};