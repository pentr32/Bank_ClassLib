#pragma once

#include "IBank.h"
#include "Bank.h"
#include <memory>

class BankService {
	IBank* _bankService = nullptr;
public:
	BankService(IBank* service)
		: _bankService(service) {

		if (_bankService == nullptr) {

			throw std::invalid_argument("Service must not be null!");

		}
	}
};