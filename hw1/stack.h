#define STACK_CAPACITY 1000
#include <iostream>
using namespace std;

class Stack
{
private:
	char stk[STACK_CAPACITY];
	int count;

public:
	Stack(){
		count = 0;
	}

	void push( char c )
	{
		if (isFull())
		{
			cout << "ERROR: Push on full stack";
			return;
		}
		stk[count++] = c;
	}
	
	char pop()
	{
		if (isEmpty())
		{
			cout << "ERROR: Pop on empty stack";
			return 0;
		}
		else
		{
			--count;
			return top();
		}
	}

	char top()
	{
		return stk[count];
	}

	bool isEmpty()
	{
		return count <= 0;
	}

	bool isFull()
	{
		return count >= STACK_CAPACITY;
	}

	~Stack(){
	};
};
