#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;

class Triangle : public Shape
{
private:
	double base;
	double height;

public:
	Triangle(string name, double b, double h) : Shape(b, h, name)
	{
		base = b;
		height = h;
	}
	virtual double area() const
	{
		return .5 * base * height;
	}
	virtual void draw() const
	{
		int x = base;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "* ";
			}
			x--;
			cout << endl;
		}
		cout << endl;
	}
	~Triangle()
	{};

};
#endif /*TRIANGLE_H*/