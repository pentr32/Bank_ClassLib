// BankClassLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankService.h"
#include "AccountTypeEnum.h"

IBank* bankService;

int main() 
{
	bankService->CreateAccount("Robert", AccountType::AccountChecking);

	std::cout << bankService->Balance(1).GetBalance();
}