#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
private:
	int x;
	int y;
	string z;

public:
	Shape(int centerX, int centerY, string name)
	{
		x = centerX;
		y = centerY;
		z = name;

	}
	virtual double area() const = 0;
	virtual void draw() const = 0;
	~Shape()
	{};

};
#endif /* SHAPE_H*/