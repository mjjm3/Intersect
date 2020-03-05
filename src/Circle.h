#pragma once
#include "Point.h"
class Circle {
public:
	double x;
	double y;
	double r;
	Circle(double, double, double);
	static int CrossPoints(Circle* c1, Circle* c2, Point* p1, Point* p2);
};
