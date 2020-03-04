#pragma once
#include "Point.h"
class Line{
private:
	double a;
	double b;
	double c;
public:
	static bool hasCrossPoint(Line* l1, Line* l2);
	static Point CrossPoint(Line* l1, Line* l2);
	Line(Point p1, Point p2);


};

