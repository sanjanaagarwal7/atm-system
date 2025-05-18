#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
using namespace std;

class ATM {
    private:
    long int Account_no;
    string name;
    int pin;
    double balance;
    string mobile_no;
    public:
    void setData(int account_no_a,string name_a,int pin_a,double balance_a,string mobile_no_a){
        Account_no=account_no_a;
        name=name_a;
        pin=pin_a;
        balance=balance_a;
        mobile_no=mobile_no_a;
    }

    long int getaccountno(){
        return Account_no;
    }
    string getname(){
        return name;
    }
    int getpin(){
        return pin;
    }
    double getbalance(){
        return balance;
    }
    string getmobileno(){
        return mobile_no;
    }

    void updatePhone(string mobprev,string mobnew){
        if(mobprev==mobile_no){
            mobile_no=mobnew;
            cout<<"Successfully updated mobile no";
            _getch();
        }
        else{
            cout<<"Mobile no is wrong";
            _getch();
        }
    }
    void cash_withdraw(double cash){
        if(cash>0 && cash<=balance){
            cout<<"Withdrawl is successful";
            balance=balance-cash;
            cout<<"Remaining balance is: "<<balance;
            _getch();
        }
        else{
            cout<<"Insufficient balance";
            _getch();
        }
    }
};

int main(){
    int choice;
    long int account;
    int p;
    ATM a;
    string mobprev;
    string mobnew;
    system("cls");
    a.setData(125678,"Miki",1245,75000,"8065421124");
    do{
    system("cls");
    cout<<"Welcome to ATM"<<endl;
    cout<<"Enter account no: ";
    cin>>account;
    cout<<"Enter pin: ";
    cin>>p;
    if(account=a.getaccountno() && p==a.getpin()){
        do{
            cout<<"1.Check Balance"<<endl;
            cout<<"2.Cash Withdraw"<<endl;
            cout<<"3.User Details"<<endl;
            cout<<"4.Update Mobile no"<<endl;
            cout<<"5.Exit"<<endl;

            cout<<"Enter choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                cout<<"Bank balance: "<<a.getbalance()<<endl;
                _getch();
                break;
                case 2: 
                double cash;
                cout<<"Amount want to withdraw: ";
                cin>>cash;
                a.cash_withdraw(cash);
                break;
                case 3: 
                cout<<"Details"<<endl;
                cout<<"Account no: "<<a.getaccountno()<<endl;
                cout<<"Name: "<<a.getname()<<endl;
                cout<<"Balance: "<<a.getbalance()<<endl;
                cout<<"Mobile no: "<<a.getmobileno()<<endl;
                _getch();
                break;
                case 4:
                cout<<"Enter previous mobileno: ";
                cin>>mobprev;
                cout<<"Enter new mobileno: ";
                cin>>mobnew;
                a.updatePhone(mobprev,mobnew);
                break;
                case 5: 
                exit(0);
                default: 
                    cout<<"Details are not valid";
            }
        }while(1);


    }

    else{
        cout<<"Invalid accountno or pin";
    }
    }while(1);
    return 0;
}
