#pragma once

enum class AccountType {

    // Used for daily expenses and bills.
    // Account holders can write checks for funds in the account.
    AccountChecking,

    // Used for saving money for emergencies or a specific goal.
    // Typically earns interest.
    AccountSavings,

    // Deposit account that earns interest.
    // Limits the number of transactions each month.
    AccountMoneyMarket,
};