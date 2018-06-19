#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
	Coins( int q, int d, int n, int p )
	{
		quarters = q;
		dimes = d;
		nickels = n;
		pennies = p;
	}
	void deposit_coins( Coins & c )
	{
		quarters += c.quarters;
		dimes += c.dimes;
		nickels += c.nickels;
		pennies += c.pennies;
	}
	bool has_exact_change_for_cents( int amount_in_cents )
	{	
		int q_num = quarters;
		int d_num = dimes;
		int n_num = nickels;
		int p_num = pennies;
		if (amount_in_cents > total_value_in_cents())
		{
			return false;
		}
                while (amount_in_cents > 0)
                {

                        if(q_num > 0 and amount_in_cents >= CENTS_PER_QUARTER)
                        {
                                q_num -= 1;
                                amount_in_cents -= CENTS_PER_QUARTER;
                        }
                        else if(d_num > 0 and amount_in_cents >= CENTS_PER_DIME)
                        {
                                d_num -= 1;
                                amount_in_cents -= CENTS_PER_DIME;
                        }
                        else if(n_num > 0 and amount_in_cents >= CENTS_PER_NICKEL)
                        {
                                n_num -= 1;
                                amount_in_cents -= CENTS_PER_NICKEL;
                        }
                        else if(p_num > 0 and amount_in_cents >= 1)
                        {
                                p_num -= 1;
                                amount_in_cents -= 1;
                        }
			else
			{
				return false;
				break;
			}
                }
		return true;	
	}
	Coins extract_exact_change_for_cents( int amount_in_cents )
	{
		if (!has_exact_change_for_cents( amount_in_cents ))
		{
			cout << "Amount greater than amount stored" << endl;
			Coins same(quarters, dimes, nickels, pennies);
			return same;
		}

		int q_num = quarters;
                int d_num = dimes;
                int n_num = nickels;
                int p_num = pennies;

		while (amount_in_cents > 0)
		{

			if(quarters > 0 and amount_in_cents >= CENTS_PER_QUARTER)
			{
				quarters -= 1;
				amount_in_cents -= CENTS_PER_QUARTER;
			}	
	
			else if(dimes > 0 and amount_in_cents >= CENTS_PER_DIME)
			{	
				dimes -= 1;
				amount_in_cents -= CENTS_PER_DIME;
		    	}

			else if(nickels > 0 and amount_in_cents >= CENTS_PER_NICKEL)
			{
				nickels -= 1;
				amount_in_cents -= CENTS_PER_NICKEL;
			}
			else if(pennies > 0 and amount_in_cents >= 1)
			{
				pennies -= 1;
				amount_in_cents -= 1;
      			}
		}
		Coins collect(q_num-quarters, d_num-dimes, n_num-nickels, p_num-pennies);
		return collect;
	}

	int total_value_in_cents()
	{
		return quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + nickels*CENTS_PER_NICKEL + pennies;
	}
	void print( ostream & out )
	{
		out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";
	}
private:
	int quarters, dimes, nickels, pennies;
};
ostream & operator << ( ostream & out, Coins c )
{
	c.print(out);
	return out;
}
