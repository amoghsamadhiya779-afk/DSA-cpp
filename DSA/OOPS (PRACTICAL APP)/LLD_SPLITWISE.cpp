#include <bits/stdc++.h>
using namespace std;

int simplifyDebts(vector<tuple<string, string, int>>& transactions) {
    // 1. Calculate Net Balances
    unordered_map<string, int> balances;

    for (auto& t : transactions) {
        string payer, payee;
        int amount;
        tie(payer, payee, amount) = t;

        balances[payer] -= amount;
        balances[payee] += amount;
    }

    // 2. Build Max Heaps
    priority_queue<int> creditors; // positive balances
    priority_queue<int> debtors;   // store absolute values of negative balances

    for (auto& [user, balance] : balances) {
        if (balance > 0) {
            creditors.push(balance);
        } else if (balance < 0) {
            debtors.push(-balance); // store as positive
        }
    }

    int transaction_count = 0;

    // 3. Settle Debts
    while (!creditors.empty() && !debtors.empty()) {
        int max_credit = creditors.top(); creditors.pop();
        int max_debt = debtors.top(); debtors.pop();

        int settled_amount = min(max_credit, max_debt);
        transaction_count++;

        if (max_credit > settled_amount) {
            creditors.push(max_credit - settled_amount);
        }

        if (max_debt > settled_amount) {
            debtors.push(max_debt - settled_amount);
        }
    }

    return transaction_count;
}