#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	std:: string str = " ";
	bool escape = true;
	while (escape != false)
	{
		Stack stk;
		cout << "Input a string\n";
		escape = getline(cin, str);
		if (str == "^D")
		{
			escape == false;
		}
		for (int i = 0; i < str.length(); i++)
		{
			stk.push(str.at(i));
		}
		while ( stk.isEmpty() == false)
		{
			cout << stk.pop();
		}
		cout << endl;
	}
	return 0;

}
