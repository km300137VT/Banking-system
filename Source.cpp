//EGR 125
//Banking System
//10-20-2022

#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;
class Customer_banking_accounts
{
	double accountNumbers[10]={10020};
	string passwords[10];
	string firtNames[10];
	string lastNames[10];//once you switch index's to [100] go back and switch the i<= values on all of the loops
	double accountBalances[10];
public:
	double GetaccountNumber( int a)
		{

		return accountNumbers[a];
		}
	void SetaccountNumber (int a, double b)//a is  for the spot on the array & b is for the account number
		{
		accountNumbers[a]=b;
		}
	string Getpassword(int a) {
		return passwords[a];
	}
	void Setpassword(int a, string b)
	{
		passwords[a] = b;
	}
	string GetfirtNames(int a)//A is the spot on the array you whish to retrive
	{
		return firtNames[a];
	}
	void SetfirtNames(int a, string b)
	{
		firtNames[a] = b;
	}
	string GetlastNames(int a)
	{
		return lastNames[a];
	}
	void SetlastNames(int a, string b)
	{
		lastNames[a] = b;
	}
	double GetaccountBalances(int a)
	{
		return accountBalances[a];
	}
	void SetaccountBalances(int a, double b)
	{
		accountBalances[a] = b;
	}

} person[100];


int accountNumberGenerator( )// s is the account number that was generated and store for that person
{
	int h=0;
	double s;
	int n;
	for (int i = 0; i <= 10; i++)// The loop checks for avalable stop and it use that spot to genrate an account nuber\/
	{
		if (person[i].GetaccountNumber(i) == 0)//from the array before and store it.
		{
			h = i;
			n = i - 1;
			s = person[n].GetaccountNumber(n) + 1;
			person[h].SetaccountNumber(h, s);
			person[h].SetfirtNames(h, "");
			person[h].SetlastNames(h, "");
			person[h].SetaccountBalances(h, 0);
			person[h].Setpassword(h, "");
			break;
		}
	}return h;// h is the stop number in the array that will be use for all of that particular persons informations
}


	int b, f, g,k,j,m,n,p,z;
	string a, d, e, c;
	

int main()
{
	cout << "WARNING DONT!! USE CAPITAL LETTERS" << endl << endl;
	cout << "If you have not use the program before you need to create a account" << endl << endl;
		string yesOrNoarray[2] = { "yes","no" };
		do {
			cout << "Do you have an acount:" << endl;
			cin >> a;
			if (a == yesOrNoarray[0])
			{
				do {
					n = 1;
					cout << "account number:   " << endl;
					cin >> b;
					for (int i = 0; i <= 10; i++)// The loop checks  to see if account exist
					{
						if (person[i].GetaccountNumber(i) == b)
						{
							m = i;
							cout << "Found your account" << endl;
							n = 2;
							break;
						}
					}
					if (n == 1) 
					{
						cout << "Account not found (please reneter account number)" << endl;
					}
				} while (n == 1);

				do {
						p= 1;
						cout << "Pasword:    " << endl;
						cin >> c;
						for (int i = 0; i <= 10; i++)// The loop checks  to see if account exist
						{
							if (person[i].Getpassword(i) == c)
							{
								if (i == m)
								{
									cout << "pasword matches" << endl;
									p = 2;
									break;
								}
							}
						}
						if (p == 1)
						{
							cout << "Pasword doesn't match (please re-enter pasword)" << endl;
						}
				} while (p == 1);
				break;
			}
			else if (a == yesOrNoarray[1])
			{
				p=accountNumberGenerator();
				cout << "Create an acount" << endl << "Fisrt name:  " << endl;
				cin >> d;
				person[p].SetfirtNames(p, d);
				cout << "last name" << endl;
				cin >> e;
				person[p].SetlastNames(p, e);
				cout << person[p].GetfirtNames(p) << " , " << person[p].GetlastNames(p) << endl<<endl;
				cout << "your account number is:  " << person[p].GetaccountNumber(p) << endl<<endl;
				cout << " Create a password: " << endl;
				cin >> c;
				person[p].Setpassword(p,c);
				cout << " Your password is: " << person[p].Getpassword(p) << endl << "Please remember both accoun# and passwords" <<endl;
			}
		} while (a == yesOrNoarray[1]);

		cout << "Your account bance is:  $" << person[m].GetaccountBalances(m) << endl;
		do {
			string t;
			double u;
			u = 0;
			z = 1;
			cout << "Yould you like to DEPOSIT or WITHDRAWL money (type ''deposit'' or ''withdraw''  or 'no' )" << endl;
			cin >> t;
			if (t == "deposit")
			{
				cout << "how much would you like to deposit" << endl;
				cin >> u;
				person[m].SetaccountBalances(m, u + person[m].GetaccountBalances(m));
				cout << "Your new account balance is $" << person[m].GetaccountBalances(m) << endl;
			}
			if (t == "withdraw")
			{
				cout << "How much will you like to withdraw" << endl;
				cin >> u;
				person[m].SetaccountBalances(m,  person[m].GetaccountBalances(m)-u);
				cout << "Your new account balance is $" << person[m].GetaccountBalances(m) << endl;

			}
			if (t == "no")
			{
				cout << endl << "Thank for banking with us BYE! :) " << endl;
				z = 2;
				break;
			}
		} while (z == 1);

			return 0;
		
}