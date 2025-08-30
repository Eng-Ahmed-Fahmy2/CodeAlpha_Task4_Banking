#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction{
public:
    string type;
    double amount;
    Transaction(string t, double a): type(t), amount(a){}
};

class Account{
    string owner;
    double balance;
    vector<Transaction> history;
public:
    Account(string o, double b=0): owner(o), balance(b){}
    void deposit(double amt){
        balance+=amt;
        history.push_back(Transaction("Deposit",amt));
    }
    void withdraw(double amt){
        if(amt<=balance){
            balance-=amt;
            history.push_back(Transaction("Withdraw",amt));
        } else cout<<"Insufficient funds\n";
    }
    void showHistory(){
        cout<<"Transactions for "<<owner<<":\n";
        for(auto &t:history)
            cout<<t.type<<": "<<t.amount<<"\n";
    }
    void showBalance(){
        cout<<"Balance for "<<owner<<": "<<balance<<"\n";
    }
};

int main(){
    Account a("Fahmy", 1000);
    a.deposit(500);
    a.withdraw(200);
    a.showBalance();
    a.showHistory();
}
