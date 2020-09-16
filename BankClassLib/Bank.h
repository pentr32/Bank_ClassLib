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

// using namespace std; Den bliver en ambiguity og bagefter programmet den ved ikke på hvilken skal så peger.

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

	int CreateAccount(std::string name, AccountType type) override {

		switch (type) {

			// Create a new CheckingAccount and add to accounts list.
		case AccountType::AccountChecking:
				Accounts.push_back(CheckingAccount(++accountCounter, name));
				break;

			// Create a new SavingsAccount and add to accounts list.
			case AccountType::AccountSavings:
				Accounts.push_back(SavingsAccount(++accountCounter, name));
				break;
				
			// Create a new MoneyMarketAccount and add to accounts list.
			case AccountType::AccountMoneyMarket:
				Accounts.push_back(MoneyMarketAccount(++accountCounter, name));
				break;

			default:
				return 0;
		}
		return accountCounter;
	}

	double InsertAmount(int accountNumber, double amount) override {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for(Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Add the amount to the account that was found from the list.
		double _balance = foundAccount.GetBalance();
		_balance += amount;
		foundAccount.SetBalance(_balance);

		// Returns account's balance.
		return foundAccount.GetBalance();
	}

	double WithdrawAmount(int accountNumber, double amount) override {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for (Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Add the amount to the account that was found from the list.
		double _balance = foundAccount.GetBalance();
		_balance -= amount;
		foundAccount.SetBalance(_balance);

		// Returns account's balance.
		return foundAccount.GetBalance();
	}

	Account Balance(int accountNumber) override {

		// Find the specific account from the list by account number.
		Account foundAccount;
		for (Account acc : Accounts) {
			if (acc.AccountNumber == accountNumber) foundAccount = acc;
		}

		// Find the specific account from the list by account number.
		return foundAccount;
	}

	void InterestCalculating() override {
		
		for (Account acc : Accounts) {
			acc.CalculateInterest();
		}
	}

	std::list<AccountListItem> AccountLookUpList() override {

		std::list<AccountListItem> accountList;
		for (Account acc : Accounts) {

			AccountListItem newAccountListItem;
			newAccountListItem.SetAccountNumner(acc.AccountNumber);
			newAccountListItem.SetName(acc.Name);

			accountList.push_back(newAccountListItem);
		}

		return accountList;
	}

	std::list<AccountListItem> GetAccountList() override {
	
		std::list<AccountListItem> accountList;
		for (Account acc : Accounts) {

			AccountListItem newAccountListItem;
			newAccountListItem.SetAccountNumner(acc.AccountNumber);
			newAccountListItem.SetName(acc.Name);
			newAccountListItem.SetBalance(acc.GetBalance());
			newAccountListItem.SetAccountType(acc.AccountType);

			accountList.push_back(newAccountListItem);
		}

		return accountList;
	}
};