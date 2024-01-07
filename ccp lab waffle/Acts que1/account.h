#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<bits/stdc++.h>
using namespace std;


class Account
{
private:
    int acc_no;
    string acc_name;
    string acc_type;
    int acc_bal;

public:

    void set_data();
    int get_acc();
    void withdraw();
    void deposit();
    void displayAll();
    void displayOne();
};

#endif 