#include <iostream>
#include <string>

using namespace std;

/*  Classes,Objects,AND STATE 
     
A 'Class' is a blueprint .
An 'Object' is the actual entity built from the blueprint.


*/

class BankAccount{
    // 1. ENCAPSULATION :We hide the data so the outside code can't accidently  ruint it.

    private:
    string owner;
    double balance;
    // 2. Public Interface : These are the methods outside code is allowed to use.
    public:
    // The Constructor
    // Runs automatically when a new BankAccount object is created.
    BankAccount(string owner_name,double initial_balance){
        owner = owner_name;
        balance = initial_balance;

    }
    //A method 
    void check_balance(){
        cout<< "$"<<owner <<"'sBalance is :$"<<balance <<endl;

    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount){
        if (balance >= amount) {
          balance -=amount;
          cout<<"Withdraw:$"<<amount <<"New Balance is "<<balance<<endl;
        } else {
          cout<<"Insufficient Funds"<<endl;
        }

          
    }

};

int main(){
    BankAccount alice_account("Alice",1000.0);
    cout<<"----Alice's Account----"<<endl;
    alice_account.check_balance();
    alice_account.deposit(500.0);

    
    alice_account.check_balance();
    

    return 0;

}