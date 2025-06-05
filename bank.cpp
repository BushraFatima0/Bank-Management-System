#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
    private:
    string accountholder;
    int accountnumber;
    double balance;

    public:

    BankAccount(string name, int accnum, double initialbalance){
        accountholder=name;
        accountnumber=accnum;
        balance=initialbalance;
    }

    void Deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Rs."<<amount<<" deposited successfully.\n Balance= Rs."<<balance<<"\n";
        }
        else{
            cout<<"Invalid deposit amount.\n";
        }
    }

    void Withdraw(double amount){
        if(amount<=balance && amount>0){
            balance-=amount;
            cout<<"Rs."<<amount<<" withdrawn successfully.\n Balance= Rs."<<balance<<"\n";
        }
        else if(amount>balance){
            cout<<"Insufficient balance.\n";
        }
        else{
            cout<<"Invalid withdrawal amount.\n";
        }
    }

    void Display(){
        cout<<"Account Holder: "<<accountholder<<"\n";
        cout<<"Account Number: "<<accountnumber<<"\n";
        cout<<"Balance: Rs."<<balance<<"\n";
    }

    int getaccountnumber(){
        return accountnumber;
    } 
};

int main(){
    vector<BankAccount>accounts;
    int choice;

    while(true){
        cout<<"\n________BANK MANAGEMENT SYSTEM________\n";
        cout<<"1. Create Account\n"
            <<"2. Deposit Money\n"
            <<"3. Withdraw Money\n"
            <<"4. Display Account Details\n"
            <<"5. Exit\n"
            <<"\nEnter your choice: ";
            cin>>choice;

            if(choice==1){
                string name;
                int accnum;
                double initialbalance;
                cout<<"Enter Account Holder Name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter Account Number: ";
                cin>>accnum;
                cout<<"Enter Initial Balance: ";
                cin>>initialbalance;
                accounts.push_back(BankAccount(name,accnum,initialbalance));
                cout<<"Account created successfully.\n";
            }
            else if(choice==2){
                int accnum;
                double amount;
                cout<<"Enter Account Number: ";
                cin>>accnum;
                bool found=false;

                for(auto &acc:accounts){
                    if(acc.getaccountnumber()== accnum){
                        cout<<"Enter Amount to Deposit: ";
                        cin>>amount;
                        acc.Deposit(amount);
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Account not found.\n";
                }
            }
            else if(choice==3){
                int accnum;
                double amount;
                cout<<"Enter Account Number: ";
                cin>>accnum;
                bool found=false;
                for(auto &acc: accounts){
                    if(acc.getaccountnumber()==accnum){
                        cout<<"Enter Amount to Withdraw: ";
                        cin>>amount;
                        acc.Withdraw(amount);
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Account not found.\n";
                }
            }
            else if(choice==4){
                int accnum;
                cout<<"Enter Account Number: ";
                cin>>accnum;
                bool found=false;
                for(auto &acc: accounts){
                    if(acc.getaccountnumber()==accnum){
                        acc.Display();
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Account not found.\n";
                }
            }
            else if(choice==5){
                cout<<"Exiting the system...\n";
                break;
            }
            else{
                cout<<"Invalid choice. Please try again.\n";
            }
        }
        return 0;
    }

