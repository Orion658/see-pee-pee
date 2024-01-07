#include <iostream>
#include <string>
using namespace std;

class Account{
    private:
        string accountName;
        string accountType;
        int accountBalance;
        int accountNumber;
    
    public:
        static int accountCount; 
        Account(){
            // check when it is called
            this->accountNumber = Account::accountCount;
            this->accountName = "Default";
            this->accountType = "saving";
            this->accountBalance = 0;   
        }
        Account(string name, string type){
            this->accountNumber = Account::accountCount;
            this->accountName = name;
            this->accountType = type;
            if(type == "saving"){
                this->accountBalance = 0;
            } else {
                this->accountBalance = 1000;
            }    
        }  

        int getAccountNumber(){
            // cout << "Called .."  << this->accountNumber << endl;
            return this->accountNumber;
        }

        // check if already taken (do not allow to change)
        void setAccountNumber( int accountNumber){
            this->accountNumber = accountNumber;    
        }

        int getAccountBalance(){
            return this->accountBalance;
        }

        void setAccountBalance( int accountBalance){
            this->accountBalance = accountBalance;    
        }

        void depositMoney(int ammount){
            this->accountBalance += ammount;
            cout << "new Balance : " << this->getAccountBalance() << endl;
        }

        void withdrawMoney(int ammount){
            if (ammount > this->accountBalance){
                cout << "transaction not possible ..";
            }
            else{
                this->accountBalance -= ammount;
                cout << "new Balance : " << this->getAccountBalance() << endl;
            }
        }

        string getAccountName(){
            return this->accountName;
        }

        void setAccountName( string accountName){
            this->accountName = accountName;    
        }

        string getAccountType(){
            return this->accountType;
        }

        void setAccountType( string accountType){
            this->accountType = accountType;    
        }

        int getAccountCount(){
            return Account::accountCount;
        }

        void incAccountCount(){
            accountCount += 1;
            return;
        }

        void display(){
            // if ()
            cout << "****** Account details *****" << endl;
            cout << "Account Name : " << this->accountName << endl;
            cout << "Account Balance : " << this->accountBalance << endl;
            cout << "Account Number : " << this->accountNumber << endl;
            cout << "Account Type : " << this->accountType << endl;
        }

};

int Account::accountCount = 1;

Account addAccount(){
    string name, type;
    int choice;
    char dummy;
    cout << " Enter name : " << endl;
    cin >> dummy;
    getline(cin, name);
    name = dummy+name;
    cout << " Enter type (1.saving or 2.current) : " << endl;
    cin >> choice;
    if (choice == 1)
        type = "saving";
    else
        type = "current";
    Account acc(name, type); // call perameterized constructor
    acc.incAccountCount();
    return acc;
}

// int findAccount(int accountNumber,Account accountList[], int count){
    
//     // bool found = false;
//     for(int i = 0 ; i <= count ; i++){
//         // it will check every object 
//         cout << count << " " << accountNumber << endl;
//         if((accountList[i].getAccountNumber() == accountNumber)){
//             return i;
//         }
//     }
//     // cout << "Account NOT FOUND" << endl;
//     return -1;
// }

// overloaded
void display(Account accountList[], int count){
    cout << "Enter Account Number for which you want details" << endl;
    int accountNumber;
    cin >> accountNumber;

    bool found = false;
    for(int i = 0 ; i <= count ; i++){
        // it will check every object 
        if(accountList[i].getAccountNumber() == accountNumber){
            found = true;
            accountList[i].display();
        }
    }
    if(!found){
        cout << "Account NOT FOUND" << endl;
    }
    return;
}

void displayAllAccount(Account accountList[], int count){
    for(int i = 0 ; i < count ; i++){
        accountList[i].display();
    }
    return;
}

void withdrawAmmount(Account accountList[], int count){
    // find account ..
    int ammount;
    cout << "Enter Account Number for withdrawal : " << endl;
    int accountNumber;
    cin >> accountNumber;
    bool found = false;
    for(int i = 0 ; i <= count ; i++){
        // it will check every object 
        if(accountList[i].getAccountNumber() == accountNumber){
            found = true;
            cout << "Your Balance : " << accountList[i].getAccountBalance() << endl;
            cout << "Enter the ammount to Withdraw : ";
            cin >> ammount;
            accountList[i].withdrawMoney(ammount);
        }
    }
    if(!found){
        cout << "Account NOT FOUND" << endl;
    }
    return;
}

void depositAmmount(Account accountList[], int count){
    int ammount;
    cout << "Enter Account Number for Deposit : " << endl;
    int accountNumber;
    cin >> accountNumber;
    bool found = false;
    for(int i = 0 ; i <= count ; i++){
        // it will check every object 
        if(accountList[i].getAccountNumber() == accountNumber){
            found = true;
            cout << "Your Balance : " << accountList[i].getAccountBalance() << endl;
            cout << "Enter the ammount to Deposit : ";
            cin >> ammount;
            accountList[i].depositMoney(ammount);
        }
    }
    if(!found){
        cout << "Account NOT FOUND" << endl;
    }
    return;
}

int main(){
    cout << "Lets GO !" << endl;
    Account accoutList[30]; 
    int count = 0;
    int ch = 0;
    do
    {
        cout << "\nWelcome to the Bank !" << endl;
        cout << " 1. ADD Account\n 2. Withdraw\n 3. Deposit \n 4. Display\n 5. DisplayAll\n 6. exit" <<endl;
        cin>> ch;

        switch(ch){
        case 1:
            accoutList[count] = addAccount();
            count++;
            break;
        case 2:
            withdrawAmmount(accoutList, count);
            break;
        case 3:
            depositAmmount(accoutList, count);
            break;
        case 4:
            display(accoutList, count);
            break;
        case 5:
            displayAllAccount(accoutList, count);
            break;
        case 6:
            cout << "Thank you .." << endl;
            break;
        default:
            cout << "Enter Valid Option" << endl;
            break;
        }
    } while (ch != 6);
    

    //while
    //switch
    // 1. Add
    // 2. withdraw
    // 3. deposit
    // 4. display1
    // 5. displayAll
    // 6. exit
    return 0;
}