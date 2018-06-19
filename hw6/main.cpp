#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Picture.h"
#include <iostream>
using namespace std;

int main()
{
	Picture p;
	p.add(new Triangle("FirstTriangle",5,5)); //FirstTriangle: height = 5, base = 5
	p.add(new Triangle("SecondTriangle",4,3)); //SecondTriangle : height = 4, base = 3
	p.add(new Circle("FirstCircle",5)); //FirstCircle: radius = 5
	p.add(new Circle("SecondCircle",10)); //SecondCircle : radius = 10
	p.add(new Square("FirstSquare",5)); //FirstSquare: side=5
	p.add(new Square("SecondSquare",10)); //SecondSqaure: side = 10
	p.add(new Rectangle("FirstRectangle",4, 8)); //FirstRectangle: height = 4 width=8
	p.add(new Rectangle("SecondRectangle",8, 4)); //SecondRectangle: height = 8 width = 4
	p.drawAll();
	cout << "Total area is: " << p.totalArea() << " sq units" << endl;
	return 0;
}