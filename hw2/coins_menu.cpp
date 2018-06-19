#include "Coins.h"
using namespace std;
int main()
{
	cout << "\n* * * * * * * * * * * *" << endl;
	cout << "* * * -Coin Menu- * * *" << endl;
	cout << "* - - - - - - - - - - *" << endl;
	bool change = true;
	Coins myCoins(0,0,0,0);
	while( change )
	{
		char c = 0;
		cout << "\nWould you like to:\nDeposit Change(1)\nExtract Change(2)\nPrint Balance (3)\nExit Menu(4)\nEnter in a number (1-4)" << endl;
		cin >> c;
		switch ( c )
		{
			case '1':
			{
				int q, d, n, p;
				cout << "\nDeposit Change Selected" << endl;
				cout << "How many Quarters do you want to deposit?" << endl;
				cin >> q;
				cout << "How many Dimes do you want to deposit?" << endl;
	                        cin >> d;
				cout << "How many Nickels do you want to deposit?" << endl;
				cin >> n;
				cout << "How many Pennies do you want to deposit?" << endl;
				cin >> p;
				Coins dep_Coins( q, d, n, p );
				myCoins.deposit_coins(dep_Coins);
				cout << "Thank You!" << endl;
				break;
			}
			case '2':
			{
				cout << "\nExtract Change Selected" << endl;
				cout << "How much do you want to withdraw?" << endl;
				int withdraw;
				cin >> withdraw;
				if (withdraw <= myCoins.total_value_in_cents() and myCoins.has_exact_change_for_cents(withdraw)) 
				{
					Coins wit_Coins = myCoins.extract_exact_change_for_cents( withdraw );

					cout << "Withdrawal successful!" << endl;
				}
				else
				{
					cout << "Error: Insufficient funds" << endl;
				}
				break;
			}

			case '3':
			{
				cout << "\nPrint Balance Selected" << endl;
				int total_cents = myCoins.total_value_in_cents();
				int dollars = total_cents/100;
				int coins = total_cents - dollars * 100;
				if (coins < 10)
				{
					cout << "Total Balance: $" << dollars << ".0" << coins << endl;
				}
				else
				{
					 cout << "Total Balance:  $" << dollars << "." << coins << endl;
				}
				break;
			}
			case '4':
			{
				change = false;
			}
		}
	}
	return 0;
}
