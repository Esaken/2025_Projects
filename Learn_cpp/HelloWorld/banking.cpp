#include <iostream>
using namespace std;
class BankAccount {
    int balance;
public:
    BankAccount() { balance = 0; }
    void deposit(int amount) { balance += amount; }
    void withdraw(int amount) {
        if(amount > balance) cout << "Insufficient funds!\n";
        else balance -= amount;
    }
    void showBalance() { cout << "Balance: " << balance << endl; }
};
int main() {
    BankAccount acc;
    int choice, amt;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter amount: "; cin >> amt; acc.deposit(amt); break;
            case 2: cout << "Enter amount: "; cin >> amt; acc.withdraw(amt); break;
            case 3: acc.showBalance(); break;
            case 4: cout << "Goodbye!\n"; break;
        }
    } while(choice != 4);
    return 0;
}
L
