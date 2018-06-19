#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Circle
	: public Shape
{
private:
	double radius;
	const static double PI = 3.14159;

public:
	Circle(string name, double r) : Shape(r, r, name)
	{
		radius = r;
	}

	virtual double area() const
	{
		return PI * (radius * radius);
	}
	virtual void draw() const
	{
		for (int i = 0; i <= 2 * radius; i++)
		{
			for (int j = 0; j <= 2 * radius; j++)
			{
				double width = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
				if (width > radius - .3 && width < radius + .3)
				{
					cout << " *";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	~Circle()
	{};

};
#endif /*CIRCLE_H*/