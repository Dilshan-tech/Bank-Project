#include<iostream>
using namespace std;
class account {
	protected:
		float opening_bal_saving,balance_saving;
		float opening_bal_current,balance_current;
	public:
		virtual void withdraw()=0;
		virtual void deposit()=0;
};

class saving_acc:public account
{
	public:
		saving_acc()
		{
			opening_bal_saving=0.0;
		}
		saving_acc(float openbal)
		{
			opening_bal_saving=openbal;
		}
		void withdraw()
		{
			int amount;
			cout <<"Balance amount in your saving a/c is: " <<opening_bal_saving;
			cout <<"\nEnter the amount to withdraw";
			cin>> amount;
			balance_saving=opening_bal_saving - amount;
			cout <<"The balance amount in your saving a/c is: "<<balance_saving;
		}
		void deposit()
		{
			int amount;
			cout <<"Balance amount in your saving account is: "<<opening_bal_saving;
			cout <<"\nEnter the amount to deposit";
			cin>>amount;
			balance_saving = opening_bal_saving + amount;
			cout << "The balance amount in your saving a/c is: "<<balance_saving;
		}
};

class current_acc:public account {
	public:
		current_acc()
		{
			opening_bal_current=0.0;
		}
		current_acc(float openbal)
		{
			opening_bal_current = openbal;
		}
		void withdraw()
		{
			int amount;
			cout <<"Balance amount in your current a/c is: "<<opening_bal_current;
			cout <<"\nEnter the amount to withdraw:";
			cin>>amount;
			balance_current=opening_bal_current-amount;
			cout <<"The balance amount in your current a/c is: "<<balance_current;
		}
		void deposit()
		{
			int amount;
			cout <<"Balance amount in your saving a/c is: "<<opening_bal_current;
			cout <<"\nEnter the amount to deposit:*";
			cin>>amount;
			balance_current = opening_bal_current + amount;
			cout <<"The balance amount in your a/c is: "<<balance_current;
		}
};

int main()
{
	//account acc;  //Error, object of an abstract class can not be initiated
	account *acc;
	saving_acc savingobj(20000);
	current_acc currentobj(50000);
	int choice;
	char ans,ch;
	cout <<"Which Bank Account you want to operate";
	cout <<"\n1.Saving account";
	cout <<"\n2.Current account";
	cout <<"\n3.Other";
	cout <<"\n4.Quit";
	cout <<"\nEnter your choice";
	cin>>choice;
	switch(choice)
	{
		case 1:
			acc=&savingobj;
			cout <<"Press 'd' to deposit the amount; press 'w' to withdraw the amount: ";
			cin>>ch;
			if(ch=='d') acc->deposit();
			if(ch=='w') acc->withdraw();
			break;
		case 2:
			acc=&currentobj;
			cout <<"Press 'd' to deposit the amount; press 'w' to withdraw the amount: ";
			cin>>ch;
			if(ch=='d') acc->deposit();
			else acc->withdraw();
			break;
		case 3:
			cout <<"\n Other facilities are provided to you; to avail,please contact branch mmanager";
			break;
		case 4:
			return 0;
		default:
			cout <<"You entered the wrong choice";
			return 0;
	}
	return 0;
}
