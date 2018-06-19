#ifndef PICTURE_H
#define PICTURE_H
#include "Shape.h"
#include <iostream>
using namespace std;

typedef class ShapeLinkedListPair * ShapeLinkedList;
class ShapeLinkedListPair
{
public:
	Shape * info;
	ShapeLinkedList next;
	ShapeLinkedListPair(Shape * newInfo, ShapeLinkedList newNext)
		: info(newInfo), next(newNext)
	{}

};

class Picture
{
private:
	ShapeLinkedList head;

public:
	Picture()
		: head(0)
	{}
	void add(Shape *sp)
	{
		head = new ShapeLinkedListPair(sp, head);
	}
	
	void drawAll()
	{
		for (ShapeLinkedList ptr = head; ptr != '\0'; ptr = ptr->next)
		{
			ptr->info->draw();
		}
	}

	double totalArea()
	{
		double sum_area = 0.0;
		for (ShapeLinkedList ptr = head; ptr != '\0'; ptr = ptr->next)
		{
			sum_area += ptr->info->area();
		}
		return sum_area;
	}

	~Picture()
	{};
};
#endif /*PICTURE_H*/