#include "Coins.h"
const int CENTS_FOR_CHIPS = 68, CENTS_TRANSFER = 205;
int main()
{
	Coins pocket( 5, 3, 6, 8 );
	Coins piggyBank( 50, 50, 50, 50 );
	cout << "I started with " << pocket << " in my pocket" << endl;
	Coins payForChips = pocket.extract_exact_change_for_cents( CENTS_FOR_CHIPS );
	cout << "I bought chips for " << CENTS_FOR_CHIPS << " cents using " << payForChips <<endl;
	cout << "I have " << pocket << " left in my pocket" << endl;
	cout << "I have " << piggyBank << " in my piggy bank" << endl;
	Coins transfer = piggyBank.extract_exact_change_for_cents ( CENTS_TRANSFER );
	cout << "I transferred " << CENTS_TRANSFER << " cents from my piggy bank to my pocket and now have " << piggyBank << " in my piggy bank" << endl;
	pocket.deposit_coins( transfer );
	cout << "I now have " << pocket << " cents in my pocket" << endl;
	Coins foundInCouch( 10, 10, 10, 10);
	piggyBank.deposit_coins( foundInCouch );
	int total_cents = piggyBank.total_value_in_cents();
	int dollars = total_cents/100;
	int cents = total_cents - dollars * 100;
	cout << "I found " << foundInCouch << " in the couch and put it in my piggy bank" << endl;
	if (cents < 10)
	{
		cout << "I now have " << piggyBank << " which totals to $" << dollars << ".0" << cents << endl;
	}
	else
	{
		cout << "I now have " << piggyBank << " which totals to $" << dollars << "." << cents << endl;
	}	
	return 0;
}
