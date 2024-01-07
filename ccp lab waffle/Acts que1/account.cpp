#include "account.h"

static int count = 1000;

void Account::set_data()
{
    cout << "\n\nWelcome to Account Addition Menu\n";
    ::count++;
    this->acc_no = ::count;
    cout << "\nYou Have Been Allocated ACCOUNT NO. : " << this->acc_no << endl;
    cout << "Enter your First Name: ";
    string first_name, last_name;
    cin >> first_name;
    cout << "Enter Last Name : ";
    cin >> last_name;
    this->acc_name = first_name + " " + last_name;
    cout << "Select Account Type\n1.Savings\n2.Current\nChoice: ";
    int choice;
    cin >> choice;
    if (choice > 2 || choice < 1) // Fix the condition to check for invalid choice
    {
        cout << "\nInvalid Account Selection\n Going Back!!..";
        return;
    }
    this->acc_type = choice == 1 ? "Savings" : "Current";
    this->acc_bal = choice == 1 ? 0 : 1000;
    cout << "\nAccount Created Successfully.....!!!";
    cout << "\n-------------------------------------------------------------------\n";
}

int Account::get_acc()
{
    return this->acc_no;
}

void Account::withdraw()
{
    int withdraw_amount;
    cout << "\nEnter Amount to be withdrawn: ";
    cin >> withdraw_amount;
    if (withdraw_amount > this->acc_bal)
    {
        cout << "\nInsufficient Balance.....!!!!" << endl;
        return;
    }
    if (this->acc_type == "Current" && (this->acc_bal - withdraw_amount) < 1000) // Fix the condition
    {
        cout << "\nAccount is of Current Type and Balance should be greater than 1000 to withdraw.....!!!!" << endl;
        return;
    }
    cout << "\nAmount Withdrawal was Successful...!!!!\n";
    this->acc_bal -= withdraw_amount;
    cout << "Current Balance : " << this->acc_bal << endl;
}

void Account::deposit()
{
    int deposit_amount;
    cout << "\nEnter Amount to Deposit: ";
    cin >> deposit_amount;
    cout << "\nAmount Deposited Successfully...!!!!\n";
    this->acc_bal += deposit_amount;
    cout << "Current Balance : " << this->acc_bal << endl;
}

void Account::displayAll()
{
    cout << "-------------------------------------------------------------------\n";
    cout << "Account Number : " << this->acc_no << endl;
    cout << "Account Holder Name : " << this->acc_name << endl;
    cout << "Account Type : " << this->acc_type << endl;
    cout << "Account Balance : " << this->acc_bal << endl;
    cout << "-------------------------------------------------------------------\n";
}

void Account::displayOne()
{
    cout << "-------------------------------------------------------------------\n";
    cout << "Account Number : " << this->acc_no << endl;
    cout << "Account Holder Name : " << this->acc_name << endl;
    cout << "Account Type : " << this->acc_type << endl;
    cout << "Account Balance : " << this->acc_bal << endl;
    cout << "-------------------------------------------------------------------\n\n";
}
