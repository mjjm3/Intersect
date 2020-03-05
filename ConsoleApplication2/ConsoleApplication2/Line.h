#pragma once
#include "Point.h"
#include "Circle.h"
class Line{
private:
	// ax + by + c = 0
	double a;
	double b;
	double c;
public:
	static bool hasCrossPoint(Line* l1, Line* l2);
	static Point CrossPoint(Line* l1, Line* l2);
	static int CrossPoints(Line* l, Circle* c, Point* p1, Point* p2);
	Line(Point p1, Point p2);


};

