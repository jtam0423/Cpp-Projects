#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;

class Square : public Shape
{
private:
	double length;

public:
	Square(string name, double l) : Shape(l, l, name)
	{
		length = l;
	}

	virtual double area() const
	{
		return length * length;
	}

	virtual void draw() const
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	~Square()
	{};

};
#endif /*SQUARE_H*/