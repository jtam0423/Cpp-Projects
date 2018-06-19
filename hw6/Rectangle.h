#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Square.h"
#include <string>
#include <iostream>
using namespace std;

class Rectangle : public Square
{
private:
	double length;
	double width;

public:
	Rectangle(string name, double l, double w) : Square(name, l)
	{
		length = l;
		width = w;
	}

	virtual double area() const
	{
		return length * width;
	}

	virtual void draw() const
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << " *";
			}
			cout << endl;
		}
		cout << endl;
	}
	~Rectangle()
	{};
};
#endif /*RECTANGLE_H*/