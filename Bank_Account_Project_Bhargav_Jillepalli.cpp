// Bhargav J
// 04/16/21

#include <iostream>
using namespace std;

class BankAccount{


private:
    string customerName;
    double balance;
    int accountNumber;
public:
    BankAccount(){
        customerName = "";
        balance = 0;
        accountNumber = 0;
    }
    BankAccount(string customerName,double balance, int accountNumber){
        this->customerName = customerName;
        this->balance = balance;
        this->accountNumber = accountNumber;
    }
    double withdraw(double amount){
        if(amount > balance){
            cout << "Insufficient funds" << endl;
            return balance;
        }
        else{
            balance = balance - amount;
            return balance;
        }
    }

    double deposit(double amount){
        balance = balance + amount;
        return balance;
    }
    string getAccountInfo(){
        return customerName + " - " + to_string(accountNumber) +  " - $" +to_string(balance);
    }


};



int main(){


    BankAccount account1;
    BankAccount account2;


    string customerName;
    double accNum;
    double bal;

    string a,b;

    cout << "Enter details for account1: " << endl;
    cout << "Please enter customer name: ";
    getline(cin,customerName);
    cout << "Please enter balance: ";
    getline(cin,a);


    bal = stod(a);
    cout << "Please enter account number: ";
    getline(cin,b);


    accNum = stoi(b);


    account1 = *new BankAccount(customerName,bal,accNum);


    cout << "\nEnter details for account2: " << endl;
    cout << "Please enter customer name: ";
    getline(cin,customerName);
    cout << "Please enter balance: ";
    getline(cin,a);

  
    bal = stod(a);
    cout << "Please enter account number: ";
    getline(cin,b);
    accNum = stoi(b);


    account2 = *new BankAccount(customerName,bal,accNum);

    cout << "\nDepositing 500 to account1..\nUpdated balance = " << account1.deposit(500) << endl;
    cout << "\nWithdrawing amount 200 from account2.. \nUpdated balance = " << account2.withdraw(200) << endl << endl;

    cout << account1.getAccountInfo() << endl;
    cout << account2.getAccountInfo() << endl;

    return 0;
}